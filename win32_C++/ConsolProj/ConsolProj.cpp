#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>




int main(void) {
	/*
	char c = 'A';
	char * cp = NULL;
	cp = &c;
	printf("%x %c %c\n", &c, c, *&c);//c�� ���빰 ���ڴ� //x�� �ּ� ���ڴ�

	printf("%x %x %x\n", &cp, cp, *&cp);
	//cpó�� *�Ⱥ��̸� cp�� �ּҸ� �ǹ� 

	//&cp�� cp�� �ּҰ�
	//*&cp cp�ּ��� ����
	//cp�� cp����
	
	printf("%c : %c\n", c, *cp);

	int a = 0, b = 0, c = 0;
	int *ip = NULL;
	ip = &a;
	*ip = 10;
	printf("%d %d %d %d \n",a, b, c, *ip);
	//���� ip���� a�� �ּҰ� ���������
	//*ip = 10���� �ٲٸ� ip�� ����Ű�� �ּ��� ���� 10���� �ٲٰڴ� ��

	
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
	printf("%x %x %d\n",&num ,&*&ip, *&ip, **&ip); //�̷������ �Ⱦ��� �񱳿��� �������� �����
	printf("%x %x %x %x \n", num, &ip, ip, *ip);
	//*&�� ������ ���� ���ȴ� �����ϸ��
	//*ip ip�� ���� �������ΰ� num�� �ּҰ� ��ϵ����� �� �ּ� ã�ư��� �� ���� ����
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
	//num2�� 20�� ��µȴ�.
	*/



	return 0;
}

/*
407p

strcpy_s(szBuffer, _msize(szBuffer), .....)
sprintf_s(szBuffer, "%s ���̴� %d", "ȫ�浿", 22) 
//ȫ�浿 ���̴� 22 //%s ���̴� %d", "ȫ�浿", 22 �̰��� �ƿ� ����ȭ ���� szBuffer�� ����ϰڴٴ� ��
//szBuffer�� ���� ȫ�浿 ���̴� 22 �� ���� ���̴�.



/*



*/


*/