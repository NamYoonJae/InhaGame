#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
int *testFunc(void) {
	
	int nData = 10;

	return &nData; //지금 당장은 돌아간다 하지만 이영역을 벗어나면 범위를 지정한 락이 풀리는셈이다
	//그러므로 후에 거대한 코드를 사용시 다른 코드가 해당 주소를 사용할수도 있기에 이건 잘못된 코드이다.

}


int main(void) {

	int *pnResult = NULL;

	pnResult = testFunc();

	printf("%d\n", *pnResult);

	return 0;
}