#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib, "wsock32.lib")

int main(void)
{
	SOCKET s, cs;
	WSADATA wsaData;
	struct sockaddr_in sin, cli_addr;
	int size = sizeof(cli_addr);
	char data[10] = { 0, };

	if (WSAStartup(WINSOCK_VERSION, &wsaData) != 0)
	{
		printf("WSAStartup 실패, 에러 코드 = %d \n", WSAGetLastError());
		return 1;
	}

	s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (s == INVALID_SOCKET)
	{
		printf("소켓생성실패, 에러코드 : %d \n", WSAGetLastError());
		WSACleanup();
		return 1;
	}

	sin.sin_family = AF_INET;
	sin.sin_port = htons(10000);
	sin.sin_addr.s_addr = htonl(ADDR_ANY);

	if (bind(s, (struct sockaddr*)&sin, sizeof(sin)) == SOCKET_ERROR)
	{
		printf("바인드 실패, 에러코드 : %d \n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return 1;
	}

	if (listen(s, SOMAXCONN) != 0)
	{
		printf("리슨 모드 설정 실패, 에러코드 : %d \n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return 1;
	}

	printf("클라이언트로부터 접속을 기다리고 있습니다 \n");

	cs = accept(s, (struct sockaddr*)&cli_addr, &size);

	if (cs == INVALID_SOCKET) 
	{
		printf("접속 승인 실패, 에러코드 : %d \n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return 1;
	}

	puts("클라이언트와 연결되었습니다.");

	if (recv(cs, data, 3, 0) < 3)
	{
		printf("데이터 승인 실패, 에러코드 : %d \n", WSAGetLastError());
		closesocket(cs);
		closesocket(s);
		WSACleanup();
		return 1;
	}

	printf("%s가 클라이언트로부터 수신되었습니다.\n", data);

	if (closesocket(cs) != 0 || closesocket(s) != 0)
	{
		printf("소켓 제거 실패, 에러코드 : %d \n", WSAGetLastError());
		WSACleanup();
		return 1;
	}

	if (WSACleanup() != 0)
	{
		printf("WSACleanup 제거 실패, 에러코드 : %d \n", WSAGetLastError());
		return 1;
	}

	return 0;
}