
#include "stdafx.h"
#include <conio.h>

//���� 164p
int main(void) {
	//c���� ������ �߸� c ++�� ������ �ȴ� �ֳ��ϸ� �����Ϸ� ��Ŀ� ���� �ٸ� �ǵ��� ��ȣ�� �̿��ϴ°� ����

	int nInput = 0, nSelect = 0;

	scanf("%d", &nInput);

	nInput <= 10 ? nSelect = 10 : nSelect = 20; //������
	printf("%d\n", nSelect);

	nInput <= 10 ? (nSelect = 10) : (nSelect = 20); //����
	printf("%d\n", nSelect);

	return 0;
}

