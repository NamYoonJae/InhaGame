#include "stdafx.h"
//#include "cVector3.h"
#include "cMatrix.h"

#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif

using namespace std;

//void MatrixTest();

void main() 
{
	
	int row = 4;
	
	cMatrix matrix(row);
	matrix.Identity(row);

	//MatrixTest();
	



}

/*
void MatrixTest()
{
	int nMatDimension;
	cout << "행렬 차수를 입력하시오: ";
	cin >> nMatDimension;

	cMatrix mat1(nMatDimension);
	mat1 = cMatrix::Identity(nMatDimension);

	for (int row = 0; row < nMatDimension; row++)
	{
		for (int col = 0; col < nMatDimension; col++)
		{
			printf("[%d , %d]: ", row + 1, col + 1);
			cin >> mat1[row][col];
		}
	}

	cout << "초기 행렬: " << endl;
	mat1.Print();

	cout << "Determinant: ";
	cout << mat1.Determinant() << endl;

	cout << "Adjoint: " << endl;
	mat1.Adjoint().Print();

	float fDet = 0.0f;
	cMatrix matInv = mat1.Inverse(fDet);
	cout << "역행렬: " << endl;
	matInv.Print();

	cout << "역행렬 확인: " << endl;
	(matInv * mat1).Print();

}
*/