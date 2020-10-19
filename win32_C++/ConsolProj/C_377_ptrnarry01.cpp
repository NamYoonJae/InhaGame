#include "stdafx.h"
#include <conio.h>
#include <windows.h>

int main(void) {

	int array[3] = { 10, 20, 30 };
	/*
	printf("%x %x %x\n", array, array + 0, &array[0]);
	printf("%x %x \n", array + 1, &array[1]);
	printf("%x %x \n", array + 2, &array[2]);
	//&array[0]) array[0]의 첫번째 주소

	printf("%d %d %d \n", sizeof(array), sizeof(array[0]), sizeof(array[1]));
	//array 배열의 전체 크기 // int형 3개 가지고 있으므로 출력 12 가 출력됨
	//array 0번째의 크기 //4가 출력 됨
	//array 1번째의 크기 // 4가 출력 됨
	*/


	//배열의 주소를 나타내는 방식을 다르게 해보자
	printf("%d %d %d \n", *array, *(array+0), *&array[0]);
	printf("%d %d \n", *(array + 1), *&array[1]);
	printf("%d %d \n", *(array + 2), *&array[2]);

	/*
	*(array + i) == *&array[i] == array[i] 
	*/

	int *p = NULL;
	p = array;

	//주소를 표현해보자
	printf("%x %x %x \n", p, p + 0, &p[0]);
	printf("%x %x \n", p + 1, &p[1]);
	printf("%x %x \n", p + 2, &p[2]);

	//값을 표현해보자
	printf("%d %d %d \n", *p, *(p + 0), *&p[0]);
	printf("%d %d \n", *(p + 1), *&p[1]);	//*&p[1]) *&이 붙으면 상쇄된다 생각하고 없애도 된다
	printf("%d %d \n", *(p + 2), *&p[2]);	//*&p[2]) *&이 붙으면 상쇄된다 생각하고 없애도 된다

	for (int i = 0; i < 3; i++) 
	{
		printf("%d %d %d\n", *(array+i), *&array[i], array[i]);
		printf("%d %d %d\n", *(p + 1), *&p[i], p[i]);
	}

	printf("배열의 크기 :  %d, 포인터의 크기 : %d\n", sizeof(array), sizeof(p));

	//주소에 접근하는 방법
	p = array+2; // = &array[1]과 같다 즉, 첫번째 방의 주소

	printf("%d %d %d\n", *(p-2), *(p - 1), *(p)); //이건 10 20 30 이 나온다
	
	//수정 전
	// p+1 했기 때문에 p = p+1 이라고 생각해야한다.
	//그래서 p+2는 쓰레기 값이 나온다.


	p = array;
	*p = 40;

	p = array + 1;
	*p = 50;

	p = array + 2;
	*p = 60;

	printf("%d %d %d\n", *(p-2), *(p-1), *p);



	return 0;
}