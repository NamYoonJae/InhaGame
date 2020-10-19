// ClientTest.cpp : Defines the entry point for the console application.
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

void Client_Code();

int main()
{
	Client_Code();

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

void Client_Code()
{
	WSADATA wsaData;
	SOCKET serverSocket;

	char msg[Buf_Size];
	int strLength, i;

	SOCKADDR_IN serverAddr;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)	//���� ���� 2.0
		Error("WSASartup error");

	Log("Start...");

	serverSocket = socket(PF_INET, SOCK_STREAM, 0);	//PF_INET ipv6 ���, SOCK_STREAM TCP����� ����ϰڴ�
	if (serverSocket == INVALID_SOCKET)
		Error("socket() error");

	Log("socket ok");

	memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.S_un.S_addr = inet_addr(strServerIP);
	serverAddr.sin_port = htons(atoi(strPort));

	if (connect(serverSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
		Error("connect() error");
	else
		Log("connected...");

	while (1)
	{
		fputs("Input Message(Q to quit) : ", stdout);
		fgets(msg, Buf_Size, stdin);
		if (!strcmp(msg, "q\n") || !strcmp(msg, "Q\n"))
			break;

		send(serverSocket, msg, strlen(msg), 0);
		strLength = recv(serverSocket, msg, Buf_Size - 1, 0);
		msg[strLength] = 0;
		printf("Message from server : %s\n", msg);
	}

	closesocket(serverSocket);
	WSACleanup();
}
