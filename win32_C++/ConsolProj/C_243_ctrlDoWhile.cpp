#include "stdafx.h"
#include <conio.h>
#include <windows.h>

//���� 243p do While��
/*
	do while���� for���� while������ �޸� �ϴ� �ѹ��� ���� �� �� ������ ���Ѵ�

	*���ǻ���*
	���������� ���ǽİ�ȣ�ڿ� ;�� �ٴ´� -<���� ���� �ܰ� �մ�
*/
int main(void) {

	char ch = 0;

	do {
		ch = getchar();
		putchar(ch);
	} while (ch != '\n'); // <- ���ǽ� �� ;(�����ݷ�)�� �ٴ´�


}