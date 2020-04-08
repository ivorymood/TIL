#include <stdio.h>
#include <winsock2.h>
#pragma comment(lib, "wsock32.lib")
#pragma warning(disable:4996)

int main(void)
{
	SOCKET s;
	WSADATA wsaData;
	SOCKADDR_IN sin;
	char data[10] = "abc";

	if (WSAStartup(WINSOCK_VERSION, &wsaData) != 0)
	{
		printf("WSAStartup 실패, 에러 코드 = %d \n", WSAGetLastError());
		return 1;
	}

	s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (s == INVALID_SOCKET)
	{
		printf("소켓 생성 실패, 에러 코드 : %d \n", WSAGetLastError());
		WSACleanup();
		return 1;
	}

	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = inet_addr("127.0.0.1");
	sin.sin_port = htons(10000);

	if (connect(s, (struct sockaddr*) & sin, sizeof(sin)) != 0)
	{
		printf("접속 실패, 에러 코드 = %u \n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return 1;
	}

	if (send(s, data, 3, 0) < 3)
	{
		printf("데이터 전송 실패, 에러코드 : %d \n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return 1;
	}

	puts("abc를 서버 프로그램에 전송하였습니다.");

	if (closesocket(s) != 0)
	{
		printf("소켓 제거 실패, 에러 코드 = %u \n", WSAGetLastError());
		WSACleanup();
		return 1;
	}

	if (WSACleanup() != 0)
	{
		printf("WSACleanup 실패, 에러 코드 = %u \n", WSAGetLastError());
		return 1;
	}

	puts("127.0.0.1의 10000번 포트에 접속을 성공하였습니다.");

	return 0;
}