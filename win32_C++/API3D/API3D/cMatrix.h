
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



	// >> :
	static cMatrix Scale(float plus);
	static cMatrix Translation(float x, float y, float z);
	static cMatrix Translation(cVector3& v);
	static cMatrix RotationX(float Angle);
	static cMatrix RotationY(float Angle);
	static cMatrix RotationZ(float Angle);
	static cMatrix View(cVector3& vEye, cVector3& vLookAt, cVector3& vUp); //vUp은 기본적으로 90으로 설정 // vLookAt이 내려가면 그 각의 90도로 vUp 다시 설정 그 후 두개의 vector를 통해 하나의 vector 다시 설정
	static cMatrix Projection(float fFovY, float fAspect, float fNearZ, float fFarZ);
	static cMatrix Viewport(float x, float y, float w, float h, float minZ, float maxz);

	static cMatrix Pipeline(RECT rt);
};

