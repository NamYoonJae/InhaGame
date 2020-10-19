
#include "stdafx.h"
#include <conio.h>

//교재 164p
int main(void) {
	//c언어는 에러가 뜨며 c ++은 실행이 된다 왜냐하면 컴파일러 방식에 따라 다름 되도록 괄호를 이용하는게 좋다

	int nInput = 0, nSelect = 0;

	scanf("%d", &nInput);

	nInput <= 10 ? nSelect = 10 : nSelect = 20; //비정상
	printf("%d\n", nSelect);

	nInput <= 10 ? (nSelect = 10) : (nSelect = 20); //정상
	printf("%d\n", nSelect);

	return 0;
}

