
#pragma once
#include "stdafx.h"

class cMatrix
{
private:
	
	
	class cRow 
	{
	private:
		vector<float> m_vecData;
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



	// >> :
	static cMatrix Scale(float plus);
	static cMatrix Translation(float x, float y, float z);
	static cMatrix Translation(cVector3& v);
	static cMatrix RotationX(float Angle);
	static cMatrix RotationY(float Angle);
	static cMatrix RotationZ(float Angle);
	static cMatrix View(cVector3& vEye, cVector3& vLookAt, cVector3& vUp); //vUp�� �⺻������ 90���� ���� // vLookAt�� �������� �� ���� 90���� vUp �ٽ� ���� �� �� �ΰ��� vector�� ���� �ϳ��� vector �ٽ� ����
	static cMatrix Projection(float fFovY, float fAspect, float fNearZ, float fFarZ);
	static cMatrix Viewport(float x, float y, float w, float h, float minZ, float maxz);

	static cMatrix Pipeline(RECT rt);
};

