
#include "stdafx.h"
#include <conio.h>


int main(void) {
	int limitLife = 100 * 365 * 24 * 60; //�ΰ� 100�� ����(��) 52,560,000 ��
	int todaySmoking = 0; //�Ϸ翡 �� ���� �Ǵ���(���� 2��)

	int breakLife = 0; //���� ����(�� ��)
	int mLimitLife = 0; //��� ����(�� ��)

	int nMlife = 0; //���� ���� (��)
	int nHLife = 0; //���� ���� (�ð�)
	int nDayLife = 0; //���� �ð�(��)
	int nMonLife = 0; //���� �ð�(��)
	int nYearLife = 0; //���� �ð�(��)

	int mLife = 0;	//��� ���� (��)
	int hLife = 0; //��� ����(�ð�)
	int dayLife = 0; //��� ���� (��)
	int monLife = 0; //��� ����(��)
	int yearLife = 0; //��� ����(��)



	printf("�Ϸ翡 �Ǵ� ����?");

	scanf("%d", &todaySmoking);

	breakLife = todaySmoking * 2 * 365 * 20; //1����� 2�� *  1�� * 20���ǿ�� ���̴� ����(��)���� ǥ��
	printf("���� ���� %d�� �Դϴ�\n", breakLife);

	mLimitLife = limitLife - breakLife;
	printf("��� ���� %d�� �Դϴ�\n", mLimitLife);



	//���� ����
	nYearLife = breakLife / (60 * 24 * 30.41 * 12);
	nMonLife = (breakLife % int(60 * 24 * 30.41666666666667 * 12)) / (60 * 24 * 30.41666666666667); //��� ����(��) -> ����
	nDayLife = (breakLife % int(60 * 24 * 30.41666666666667 * 12)) % int(60 * 24 * 30.41666666666667) / (60 * 24); //��� ����(��) -> ��
	nHLife = (breakLife % int(60 * 24 * 30.41666666666667 * 12)) % int(60 * 24 * 30.41666666666667) % (60 * 24) / 60; //��� ����(��) -> �ð�
	nMlife = (breakLife % int(60 * 24 * 30.41666666666667 * 12)) % int(60 * 24 * 30.41666666666667) % (60 * 24) % 60; //��� ����(��)



	 //��� ����
	yearLife = mLimitLife / (60 * 24 * 30.41 * 12);
	monLife = (mLimitLife % int(60 * 24 * 30.41666666666667 * 12)) / (60 * 24 * 30.41666666666667); //��� ����(��) -> ����
	dayLife = (mLimitLife % int(60 * 24 * 30.41666666666667 * 12)) % int(60 * 24 * 30.41666666666667) / (60 * 24); //��� ����(��) -> ��
	hLife = (mLimitLife % int(60 * 24 * 30.41666666666667 * 12)) % int(60 * 24 * 30.41666666666667) % (60 * 24) / 60; //��� ����(��) -> �ð�
	mLife = (mLimitLife % int(60 * 24 * 30.41666666666667 * 12)) % int(60 * 24 * 30.41666666666667) % (60 * 24) % 60; //��� ����(��)


	printf("���� ���� %d�� %d���� %d�� %d�ð� %d�� �Դϴ�\n", nYearLife, nMonLife, nDayLife, nHLife, nMlife);
	printf("��� ���� %d�� %d���� %d�� %d�ð� %d�� �Դϴ�\n", yearLife, monLife, dayLife, hLife, mLife);


	return 0;


}

