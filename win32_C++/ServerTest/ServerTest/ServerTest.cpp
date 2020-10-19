// ServerTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string>
#include <winSock2.h>
#pragma comment(lib, "ws2_32.lib")

#define Buf_Size 1024

void Error(char* msg);
void Log(char* msg);

char strServerIP[] = "165.246.192.56";//�ڽ��� pc ip�ּ�
char strClientIP[] = "127.0.0.1"; //�ڽ��� pc�� �ǹ���
char strPort[] = "12345";

void Server_Code();

int main()
{
	Server_Code();

    return 0;
}

void Error(char * msg)
{
	Log(msg);
	exit(1);
}

void Log(char * msg)
{
	fputs(msg, stderr);
	fputc('\n', stderr);
}

void Server_Code()
{
	WSADATA wsaData;
	SOCKET serverSocket, clientSocket;

	char msg[Buf_Size];
	int strLength, i;

	SOCKADDR_IN serverAddr, clientAddr;
	int clientAddrSize;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)	//���� ���� 2.0
		Error("WSASartup error");

	serverSocket = socket(PF_INET, SOCK_STREAM, 0);	//PF_INET ipv6 ���, SOCK_STREAM TCP����� ����ϰڴ�
	if (serverSocket == INVALID_SOCKET)
		Error("socket() error");

	memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;	//PF �� AF�� ������ �ణ�� ���̴� �ִ�.
	serverAddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	serverAddr.sin_port = htons(atoi(strPort));

	if (bind(serverSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
		Error("bind() error");

	Log("bind() ok");

	if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR)
		Error("listen() error");

	Log("listen() ok");

	clientAddrSize = sizeof(clientAddr);
	memset(msg, 0, sizeof(msg));
	for (i = 0 ; i < SOMAXCONN; i++) //������ �ִ�ġ��ŭ �ްڴ�
	{
		clientSocket = accept(serverSocket, (SOCKADDR*)&clientAddr, &clientAddrSize);
			Log("Accept()...");
		if (clientSocket == SOCKET_ERROR)
			Error("Accep() error");
		else
			printf("Connected client %d \n", i + 1);

		while ((strLength = recv(clientSocket, msg, Buf_Size, 0)) != 0)
		{
			printf("%d client : %s", i + 1, msg);
			send(clientSocket, msg, strLength, 0);
			memset(msg, 0, sizeof(msg));
		}
		closesocket(clientSocket);
	}

	closesocket(serverSocket);
	WSACleanup();
	Log("Finish()...");

}
