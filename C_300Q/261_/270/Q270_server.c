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
		printf("WSAStartup ����, ���� �ڵ� = %d \n", WSAGetLastError());
		return 1;
	}

	s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (s == INVALID_SOCKET)
	{
		printf("���ϻ�������, �����ڵ� : %d \n", WSAGetLastError());
		WSACleanup();
		return 1;
	}

	sin.sin_family = AF_INET;
	sin.sin_port = htons(10000);
	sin.sin_addr.s_addr = htonl(ADDR_ANY);

	if (bind(s, (struct sockaddr*)&sin, sizeof(sin)) == SOCKET_ERROR)
	{
		printf("���ε� ����, �����ڵ� : %d \n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return 1;
	}

	if (listen(s, SOMAXCONN) != 0)
	{
		printf("���� ��� ���� ����, �����ڵ� : %d \n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return 1;
	}

	printf("Ŭ���̾�Ʈ�κ��� ������ ��ٸ��� �ֽ��ϴ� \n");

	cs = accept(s, (struct sockaddr*)&cli_addr, &size);

	if (cs == INVALID_SOCKET) 
	{
		printf("���� ���� ����, �����ڵ� : %d \n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return 1;
	}

	puts("Ŭ���̾�Ʈ�� ����Ǿ����ϴ�.");

	if (recv(cs, data, 3, 0) < 3)
	{
		printf("������ ���� ����, �����ڵ� : %d \n", WSAGetLastError());
		closesocket(cs);
		closesocket(s);
		WSACleanup();
		return 1;
	}

	printf("%s�� Ŭ���̾�Ʈ�κ��� ���ŵǾ����ϴ�.\n", data);

	if (closesocket(cs) != 0 || closesocket(s) != 0)
	{
		printf("���� ���� ����, �����ڵ� : %d \n", WSAGetLastError());
		WSACleanup();
		return 1;
	}

	if (WSACleanup() != 0)
	{
		printf("WSACleanup ���� ����, �����ڵ� : %d \n", WSAGetLastError());
		return 1;
	}

	return 0;
}