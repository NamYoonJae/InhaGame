#include "stdafx.h"
#include <iostream>
#include <string>


/*
	Q3. �� ���簢���� ���� �߽����� x,y ��ǥ �� �� w, ���� h�� �Է¹޾�
	�� ��° ���簢���� ù ��° ���簢���� ���ο� �ִ���,
	ù ��° ���簢���� ��ġ������ �Ǵ��ϴ� ���α׷� �ۼ�

	ex >	R1 2.5 / 4 / 2.5 / 43
			R2 1.5 / 5 / 0.5 / 3
			=> R2�� R1�� ���ο� �ִ�
*/
using namespace std;



struct Radius
{

	float x1, x2;
	float y1, y2;
	float w1, w2;
	float h1, h2;
};

void Calculation(Radius *);


void main(void) {
	Radius radius;

	float h2;

	cout << "R1�� x1�� �Է��ϼ��� : ";
	cin >> radius.x1;
	cout << endl;

	cout << "R1�� y1�� �Է��ϼ��� : ";
	cin >> radius.y1;
	cout << endl;

	cout << "R1�� w1�� �Է��ϼ��� : ";
	cin >> radius.w1;
	cout << endl;

	cout << "R1�� h1�� �Է��ϼ��� : ";
	cin >> radius.h1;
	cout << endl;


	cout << "R2�� x2�� �Է��ϼ��� : ";
	cin >> radius.x2;
	cout << endl;

	cout << "R2�� y2�� �Է��ϼ��� : ";
	cin >> radius.y2;
	cout << endl;

	cout << "R2�� w2�� �Է��ϼ��� : ";
	cin >> radius.w2;
	cout << endl;

	cout << "R2�� h2�� �Է��ϼ��� : ";
	cin >> radius.h2;
	cout << endl;


	Calculation(&radius);
}

void Calculation(Radius *radius) 
{
	float rightMark1 = radius->x1 + (radius->w1 / 2); //R1 x�� ������ �� ��ǥ
	float reftMark1 = radius->x1 - (radius->w1 / 2); //R1 x�� ���� �� ��ǥ

	float highH1 = radius->y1 + (radius->h1 / 2); //R1 y�� �ֻ�� ��ǥ
	float lowH1 = radius->y1 - (radius->h1 / 2); //R1 y�� ���ϴ� ��ǥ


	float rightMark2 = radius->x2 + (radius->w2 / 2);
	float reftMark2 = radius->x2 - (radius->w2 / 2);

	float highH2 = radius->y2 + (radius->h2 / 2);
	float lowH2 = radius->y2 - (radius->h2 / 2);

	//�� ��° �簢���� �߾��� ù ��° �簢�� �ȿ� ����ֳ� ����
	if (reftMark1 <= radius->x2 && radius->x2 <= rightMark1 && lowH1<=radius->y2 && radius->y2 <=highH1) 
	{
		//�簢�� �ȿ� �ִ� ���
		if (reftMark1 <= reftMark2 && rightMark1 >= rightMark2 && highH1 >= highH2 && lowH1 <= lowH2)
		{
			cout << "�� ��° �簢���� ù ��° �簽�� ���ο� ����ֽ��ϴ�.";
			cout << endl;
		}
		else
		{
			cout << "�� ��° �簢���� ù ��° �簢���� ��Ĩ�ϴ�";
			cout << endl;
		}
	}
	//�� ��° �簽���� �߾��� ù ��° �簽�� �ȿ� ���� ��� 
	else
	{

		//�� ��° �簢���� 4���� ������ �ϳ��� ù ��° �����ȿ� ���� ���
		if (reftMark2 > reftMark1 && reftMark2 < rightMark1 && reftMark2 < highH1 && reftMark2 >lowH1 ) 
		{
			cout << "�� ��° �簢���� ù ��° �簢���� ��Ĩ�ϴ�.";
			cout << endl;
		}
		else if (rightMark2 > reftMark1 && rightMark2 < rightMark1 && rightMark2 < highH1 && rightMark2 > lowH1) 
		{
			cout << "�� ��° �簢���� ù ��° �簢���� ��Ĩ�ϴ�.";
			cout << endl;
		}
		else if (highH2 > reftMark1 && highH2 < rightMark2 && highH2 < highH1 && highH2 > lowH1)
		{
			cout << "�� ��° �簢���� ù ��° �簢���� ��Ĩ�ϴ�.";
			cout << endl;
		}
		else if (lowH2 > reftMark1 && lowH2 < rightMark1 && lowH2 < highH1 && lowH2 > lowH1)
		{
			cout << "�� ��° �簢���� ù ��° �簢���� ��Ĩ�ϴ�.";
			cout << endl;
		}

		//ù ��° �簢���� 4���� ������ �ϳ��� �� ��° �����ȿ� ���� ���
		else if (reftMark1 < rightMark2 && reftMark1 > reftMark2 && reftMark1 <highH2 && reftMark1 >lowH2) 
		{
			cout << "ù ��° �簢���� �� ��° �簢���� ��Ĩ�ϴ�.";
			cout << endl;
		}
		else if (rightMark1 < rightMark2 && rightMark1 > reftMark2 && rightMark1 <highH2 && rightMark1 >lowH2)
		{
			cout << "ù ��° �簢���� �� ��° �簢���� ��Ĩ�ϴ�.";
			cout << endl;
		}
		else if (highH1 < rightMark2 && highH1 > reftMark2 && highH1 <highH2 && highH1 >lowH2)
		{
			cout << "ù ��° �簢���� �� ��° �簢���� ��Ĩ�ϴ�.";
			cout << endl;
		}
		else if (lowH1 < rightMark2 && lowH1 > reftMark2 && lowH1 <highH2 && lowH1 >lowH2)
		{
			cout << "ù ��° �簢���� �� ��° �簢���� ��Ĩ�ϴ�.";
			cout << endl;
		}

		//�������� ��ġ�� ������ �� ���� ��ĥ���
		else if(reftMark1 < reftMark2 && rightMark1 > rightMark2 && highH1 < highH2 && lowH1 > lowH2)
		{
			cout << "�� ������ ��Ĩ�ϴ�";
			cout << endl;
		}
		else if (reftMark1 > reftMark2 && rightMark1 < rightMark2 && highH1 > highH2 && lowH1 < lowH2)
		{
			cout << "�� ������ ��Ĩ�ϴ�";
			cout << endl;
		}

		else
		{
			cout << "�� ��° �簢���� ù ��° �簢���� ��ġ�� �ʽ��ϴ�.";
			cout << endl;
		}


	}

}
