
#pragma once
#include "stdafx.h"

class cMatrix
{
private:
	
	
	class cRow 
	{
	private:
		std::vector<float> m_vecData;
	public:
		cRow();
		~cRow();

		cRow(int nDimension);	// : random

		void Resize(int nDimension);
		float& operator[](int index);//지정한 행의 열값을 반환

		float GetVecData(int index);
	};

	vector<cRow> cCol;

public:
	

	cMatrix();
	~cMatrix();

	

	cMatrix(int nDimension);	// : random

	void Print();
	void Resize(int nDimension);
	int Dimension();	//몇 행 몇 열로 이루어졌는지 반환

	static cMatrix Identity(int nDimension); //단위 행렬을 리턴해주기
	cRow& operator[](int nIndex);//행을 반환

	//=============================================================

	bool operator==(cMatrix& mat);
	bool operator!=(cMatrix& mat);
	cMatrix operator+(cMatrix& mat);
	cMatrix operator-(cMatrix& mat);
	cMatrix operator*(cMatrix& mat);
	cMatrix operator*(float f);
	cMatrix operator/(float f);
	cMatrix Transpose();
	cMatrix Inverse();
	cMatrix Inverse(OUT float & fDetermonant);
	float Determinant();
	cMatrix Adjoint();
	float Cofactor(int nRow, int nCol);
	float Minor(int nRow, int nCol);


};

