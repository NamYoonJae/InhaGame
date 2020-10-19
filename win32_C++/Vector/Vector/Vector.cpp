// Vector.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "cVector3.h"
#include <iostream>

using namespace std;


void main()
{

	/*
	cVector3 * newVector1 = new cVector3(1, 2, 3);
	cVector3 * newVector2 = new cVector3(2, 2, 2);
	*/
	

	/*
	cout << "������ ��" << endl;
	if ((*newVector1 == *newVector2) == true)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}

	cout << endl;
	cout << endl;

	(*newVector1 + *newVector2);
	(*newVector1 - *newVector2);
	(*newVector1 * 0.2);
	(*newVector1 / 0.2);
	*/

	//Dot�� ���� ���� �а� ���� ����-> �ڻ��� �׷��� ���� -> �浹üũ�� �� �ڽź��� ������ ������ ������ ���� 
	// 0���� ũ�� ���� 0���� ������ �а�
	//newVector1->Dot(*newVector1, *newVector2);
	//newVector1->Cross(*newVector1, *newVector2);
	//newVector1->Length();
	//newVector1->Normalize();
    
	/*
	cVector3 u(1, 1, 0);
	cVector3 v(-2, 2, 0);

	//���� ������ acos�� ���ָ� ������ ���´�
	float result = cVector3::Angle(u, v);
	cout << "����: "<<result << endl;
	cout << "��: " << acos(result) * (180/3.14) << endl; //acos ��ȯ���� �����̱⶧���� (180/3.14)�� ��������Ѵ�.
	*/

	/*
		� ��ǥ�踦 �������� �� A = (0, 0, 0), B = (0, 1, 3), C = (5, 1, 0)
		�� �� �� �ϳ��� �ﰢ���� �����Ѵٰ� ����.
		�� �ﰢ���� ������ ���͸� ���϶�.
	*/
	
	/*
	cVector3 a(0, 0, 0);
	cVector3 b(0, 1, 3);
	cVector3 c(5, 1, 0);

	

	cVector3* newVector = new cVector3();
		
	newVector->triangleVector(a,b,c);
	*/


	//����� = (1 / D) * adjoint;
	/*
	1. Determinant(��Ľ�)
	2. Adjoint -> Cofactor (���μ�)
		�� ����� Minor matrix�� ���� determinant(��Ľ�)�� ���ؼ� ���ο� ����� ����� ����Ѵ�
		�̰��� Adjoint
	3. Adjoint =  Cofactor�� ��ġ���(Cofactor�� ��ġ��ķ� �ٲٸ� Adjoint�� �ȴ�)
	*/


	/*
	A11�� ���� ���̳� ����̶�
		A11�� �ִ� ��� ���� ������ �࿭�� ���Ѵ�
	
	A = A11 A12 A13
		A21 A22 A23
		A31 A 32 A33

	m-A11 = A22 A23
			A32 A33

	
	a b
	c d
	ad - bc
	�����ִ� 2�� ��� ����

	3�������� ������
	a b c
	d e f
	g h i

	���̳� ��ķ� ����� Determinant�� ��
	a(ei - fh) - b(di - fg) + c(dh - eg)

	
	*/

	/*
	A =  2 3 -1
		 4 4 -3
		-2 3 -1
	*/
//ad-bc�� ��Ľ��̴� -> �̰� 0�̸� ������� ����
//�̰ſ� ���� �Ǵ��� Determonant
// (-1)^(1+j) �� ��ȣ�� ���� �ȴ� j�� �����ڸ� ���Ѵ�-1�� j�� �� ��
//�ᱹ + - + - �� �ݺ��ȴ�

1. Determinant
	2 | 4 -3 |	- 3 | 4 -3 |	+ -1| 4 4 |
	  | 3 -1 |	    | -2 -1|		|-2 3 |
	= 2 * 5 - 3 * -10 + -1 * 20
	= 10 + 30 - 20
	= 20

2.  A11 = 5, A12 = 10, A13 = 20
	A21 = 0, A22 = -4, A23 = -12
	A31 = -5, A32 = 2, A33 = -4 // -> �̰� cofactor

	5 10 20
	0 -4 -12
	-5 2 -4

	//--> �̰�cofactor���

3. Adjoint //-> cofactor�� ��ġ ��Ų ��
	5 0 - 5
	10 -4 2
	20 -12 -4

4.
	adj * 1 / 20  //=> �ٽ� ����ķ� adjoint / Determinant
	
	=>	1/4  0   -1/4
		1/2 -1/5  1/10
		1   -3/5 -1/5

5. ���� �Ŀ��� adj�� ������� ���Ѵ�
	
	A A^-1 = I

	 2 3 -1		1/4   0   -1/4
	 4 4 -3		1/2  -1/5  1/10
	-2 3 -1		1    -3/5 -1/5

	= 2*1/4 + 3*1/2 + -1	2*0 + 3*-1/5 + 3/5	 2*-1/4 + 3*1/10 + 1/5
	= 4*4/4 + 0+4*1/2 + -3
	= 0 + -4/5 + 9/5
	= -1 + 4/10

}

