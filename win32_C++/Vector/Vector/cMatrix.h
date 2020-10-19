
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
		float& operator[](int index);//������ ���� ������ ��ȯ

		float GetVecData(int index);
	};

	vector<cRow> cCol;

public:
	

	cMatrix();
	~cMatrix();

	

	cMatrix(int nDimension);	// : random

	void Print();
	void Resize(int nDimension);
	int Dimension();	//�� �� �� ���� �̷�������� ��ȯ

	static cMatrix Identity(int nDimension); //���� ����� �������ֱ�
	cRow& operator[](int nIndex);//���� ��ȯ

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

