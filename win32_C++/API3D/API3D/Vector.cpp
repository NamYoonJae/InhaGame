// Vector.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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
	cout << "같은지 비교" << endl;
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

	//Dot을 통해 예각 둔각 구별 가능-> 코사인 그래프 참고 -> 충돌체크할 때 자신보다 앞인지 뒤인지 구별도 가능 
	// 0보다 크면 예각 0보다 작으면 둔각
	//newVector1->Dot(*newVector1, *newVector2);
	//newVector1->Cross(*newVector1, *newVector2);
	//newVector1->Length();
	//newVector1->Normalize();
    
	/*
	cVector3 u(1, 1, 0);
	cVector3 v(-2, 2, 0);

	//내적 값에서 acos을 해주면 각도가 나온다
	float result = cVector3::Angle(u, v);
	cout << "내적: "<<result << endl;
	cout << "각: " << acos(result) * (180/3.14) << endl; //acos 반환값이 라디안이기때문에 (180/3.14)를 곱해줘야한다.
	*/

	/*
		어떤 좌표계를 기준으로 점 A = (0, 0, 0), B = (0, 1, 3), C = (5, 1, 0)
		이 세 점 하나의 삼각형을 저의한다고 하자.
		이 삼각형에 수직인 벡터를 구하라.
	*/
	
	/*
	cVector3 a(0, 0, 0);
	cVector3 b(0, 1, 3);
	cVector3 c(5, 1, 0);

	

	cVector3* newVector = new cVector3();
		
	newVector->triangleVector(a,b,c);
	*/


	//역행렬 = (1 / D) * adjoint;
	/*
	1. Determinant(행렬식)
	2. Adjoint -> Cofactor (여인수)
		각 요소의 Minor matrix에 대한 determinant(행렬식)을 구해서 새로운 행렬을 만들어 줘야한다
		이것이 Adjoint
	3. Adjoint =  Cofactor의 전치행렬(Cofactor를 전치행렬로 바꾸면 Adjoint가 된다)
	*/


	/*
	A11에 대한 마이너 행렬이란
		A11이 있는 행과 열을 제외한 행열을 뜻한다
	
	A = A11 A12 A13
		A21 A22 A23
		A31 A 32 A33

	m-A11 = A22 A23
			A32 A33

	
	a b
	c d
	ad - bc
	위에있는 2차 행렬 식을

	3차식으로 만들어보자
	a b c
	d e f
	g h i

	마이너 행렬로 만들고 Determinant한 것
	a(ei - fh) - b(di - fg) + c(dh - eg)

	
	*/

	/*
	A =  2 3 -1
		 4 4 -3
		-2 3 -1
	*/
//ad-bc가 행렬식이다 -> 이게 0이면 역행렬이 없다
//이거에 대한 판단을 Determonant
// (-1)^(1+j) 로 부호가 결정 된다 j가 열숫자를 뜻한다-1을 j승 한 것
//결국 + - + - 가 반복된다

1. Determinant
	2 | 4 -3 |	- 3 | 4 -3 |	+ -1| 4 4 |
	  | 3 -1 |	    | -2 -1|		|-2 3 |
	= 2 * 5 - 3 * -10 + -1 * 20
	= 10 + 30 - 20
	= 20

2.  A11 = 5, A12 = 10, A13 = 20
	A21 = 0, A22 = -4, A23 = -12
	A31 = -5, A32 = 2, A33 = -4 // -> 이게 cofactor

	5 10 20
	0 -4 -12
	-5 2 -4

	//--> 이게cofactor행렬

3. Adjoint //-> cofactor를 전치 시킨 값
	5 0 - 5
	10 -4 2
	20 -12 -4

4.
	adj * 1 / 20  //=> 다시 역행렬로 adjoint / Determinant
	
	=>	1/4  0   -1/4
		1/2 -1/5  1/10
		1   -3/5 -1/5

5. 원래 식에서 adj의 역행렬을 곱한다
	
	A A^-1 = I

	 2 3 -1		1/4   0   -1/4
	 4 4 -3		1/2  -1/5  1/10
	-2 3 -1		1    -3/5 -1/5

	= 2*1/4 + 3*1/2 + -1	2*0 + 3*-1/5 + 3/5	 2*-1/4 + 3*1/10 + 1/5
	= 4*4/4 + 0+4*1/2 + -3
	= 0 + -4/5 + 9/5
	= -1 + 4/10

}

