#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
int *testFunc(void) {
	
	int nData = 10;

	return &nData; //���� ������ ���ư��� ������ �̿����� ����� ������ ������ ���� Ǯ���¼��̴�
	//�׷��Ƿ� �Ŀ� �Ŵ��� �ڵ带 ���� �ٸ� �ڵ尡 �ش� �ּҸ� ����Ҽ��� �ֱ⿡ �̰� �߸��� �ڵ��̴�.

}


int main(void) {

	int *pnResult = NULL;

	pnResult = testFunc();

	printf("%d\n", *pnResult);

	return 0;
}