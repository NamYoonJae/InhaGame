#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>




int main(void) {
	/*
	char c = 'A';
	char * cp = NULL;
	cp = &c;
	printf("%x %c %c\n", &c, c, *&c);//c는 내용물 보겠다 //x는 주소 보겠다

	printf("%x %x %x\n", &cp, cp, *&cp);
	//cp처럼 *안붙이면 cp의 주소를 의미 

	//&cp는 cp의 주소값
	//*&cp cp주소의 내용
	//cp는 cp내용
	
	printf("%c : %c\n", c, *cp);

	int a = 0, b = 0, c = 0;
	int *ip = NULL;
	ip = &a;
	*ip = 10;
	printf("%d %d %d %d \n",a, b, c, *ip);
	//현재 ip에는 a의 주소가 저장돼있음
	//*ip = 10으로 바꾸면 ip가 가리키는 주소의 값을 10으로 바꾸겠단 뜻

	
	ip = &b;
	*ip = 20;
	printf("%d %d %d %d \n", a, b, c, *ip);
	
	ip = &c;
	*ip = 30;
	printf("%d %d %d %d \n", a, b, c, *ip);
	*/

	/*
	int num = 10;
	int * ip = NULL;

	ip = &num;
	printf("%x %x %d\n",&num ,&*&ip, *&ip, **&ip); //이런방식은 안쓴다 비교예를 보기위해 사용함
	printf("%x %x %x %x \n", num, &ip, ip, *ip);
	//*&가 만나면 서로 상쇄된다 생각하면됨
	//*ip ip의 값을 보여줘인가 num의 주소가 등록됐으니 그 주소 찾아가서 그 값을 보냄
	*/

	/*
	10 0 0 10
	10 20 0 20
	10 20 30 30
	*/
	/*
	int num2 = 0;
	num2 = *ip + num;
	printf("%d\n", num2);
	//num2에 20이 출력된다.
	*/



	return 0;
}

/*
407p

strcpy_s(szBuffer, _msize(szBuffer), .....)
sprintf_s(szBuffer, "%s 나이는 %d", "홍길동", 22) 
//홍길동 나이는 22 //%s 나이는 %d", "홍길동", 22 이것을 아예 문장화 시켜 szBuffer에 출력하겠다는 뜻
//szBuffer를 찍어내면 홍길동 나이는 22 가 나올 것이다.



/*



*/


*/