#include "stdafx.h"
#include <iostream>
#include <string>

/*
	Q4 �� ���� ���� ���� �߽��� ��ǥ(x,y)�� ������ r�� �Է¹޾�
	�� ��° ���� ���ο� �ִ���(���� / �ܺ� �Ǵ�), 
	ù ��° ���� ��ġ������ �Ǵ��ϴ� ���α׷� �ۼ�

		ex >	C1 0.5 5.1 13
				C2 1 1.7 4.5
				=> c2�� c1�� ���ο� �ִ�.
*/

using namespace std;

struct Radius
{
	float x1, x2;
	float y1, y2;
	float r1, r2;
};

void Calculation(Radius*);

void main(void) {

	Radius radius;

	cout << "C1 x1�� �Է��ϼ��� : ";
	cin >> radius.x1;
	cout << endl;

	cout << "C1 y1�� �Է��ϼ��� : ";
	cin >> radius.y1;
	cout << endl;

	cout << "C1 r1�� �Է��ϼ��� : ";
	cin >> radius.r1;
	cout << endl;


	cout << "C2 x2�� �Է��ϼ��� : ";
	cin >> radius.x2;
	cout << endl;

	cout << "C2 y2�� �Է��ϼ��� : ";
	cin >> radius.y2;
	cout << endl;

	cout << "C2 r2�� �Է��ϼ��� : ";
	cin >> radius.r2;
	cout << endl;


	Calculation(&radius);

}

void Calculation(Radius*radius) 
{
	//�� �߽��� ������ �Ÿ�
	float powResult = pow((radius->x2 - radius->x1), 2) + pow((radius->y2 - radius->y1), 2);
	float centerBetween = sqrt(powResult);


	//float centerBetween = sqrt(pow((radius->x2 - radius->x1),2) + pow((radius->y2 - radius->y1),2));



	//ù��° ���� �� ũ�ų� �������
	if (radius->r1 >= radius->r2) 
	{
		
		if (centerBetween > radius->r1 + radius->r2) 
		{
			cout << "�� ���� ��ġ�� �ʽ��ϴ�";
		}
		else
		{
			//���� �����̰ų� ��ĥ���
			if (centerBetween+radius->r2 <= radius->r1) 
			{
				cout << "ù ��° ���� �� ��° ���� �����ϰ� �ֽ��ϴ� ";
			}
			else
			{
				cout << "�� ���� ���� ��Ĩ�ϴ�";
			}
		}

	}
	else //ù��° ���� �� �������
	{
		if (centerBetween > radius->r1 + radius->r2) 
		{
			cout << "�� ���� ��ġ�� �ʽ��ϴ�";
		}
		else
		{
			if (centerBetween + radius->r1 <= radius->r2) 
			{
				cout << "�� ��° ���� ù ��° ���� �����ϰ� �ֽ��ϴ�";
			}
			else
			{
				cout << "�� ���� ���� ��Ĩ�ϴ�";
			}
		}

	}

	
}