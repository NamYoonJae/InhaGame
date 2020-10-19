#include "stdafx.h"
#include "cMatrix.h"


float Radian(float angle);

cMatrix::cRow::cRow()
{
}

cMatrix::cRow::~cRow()
{
}

cMatrix::cRow::cRow(int nDimension)
{

	for (int i = 0; i < nDimension; i++) 
	{
		m_vecData.push_back(0);
	}

}

void cMatrix::cRow::Resize(int nDimension)
{
	m_vecData.resize(nDimension);

	for (size_t i = 0; i < nDimension; ++i)
	{
		m_vecData[i] = nDimension;
	}
}

float & cMatrix::cRow::operator[](int index)
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	//행의 열을 반환
	return m_vecData[index];
	
}

float cMatrix::cRow::GetVecData(int index)
{

	return m_vecData[index];
}

cMatrix::cMatrix()
{
}

cMatrix::~cMatrix()
{
}

cMatrix::cMatrix(int nDimension)
{
	
	
	for (int i = 0; i < nDimension; i++)
	{
		cRow row(nDimension);
		cCol.push_back(row);
	}


}

void cMatrix::Print()
{
	for (int i = 0; i < cCol.size(); i++)
	{
		for (int j = 0; j < cCol.size(); j++)
		{
			cout << cCol[i][j] << " ";
		}
		cout << endl;
	}
}

void cMatrix::Resize(int nDimension)
{
	cCol.resize(nDimension);

	for (size_t i = 0; i < nDimension; ++i)
	{
		cCol[i].Resize(nDimension);
	}
}

int cMatrix::Dimension()
{
	return cCol.size();
}

cMatrix cMatrix::Identity(int nDimension)
{
	int i = 0;
	int j = 0;

	cMatrix matrix(nDimension);

	for (i = 0; i < nDimension; i++) 
	{
		for (j = 0; j < nDimension; j++) 
		{
			matrix[i][j] = 0;
			//matrix[i][j] = (i == j) ? 1 : 0;
		}
	}

	for (i = 0; i< nDimension; i++) 
	{
		matrix[i][i] = 1;
	}

	
	return matrix;
}

cMatrix:: cRow & cMatrix::operator[](int nIndex)
{
	return cCol[nIndex];
}


bool cMatrix::operator==(cMatrix & mat)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < cCol.size(); i++) 
	{
		for (j = 0; j < cCol.size(); j++) 
		{
			if (abs(cCol[i].GetVecData(j) - mat.cCol[i].GetVecData(j)) > EPSILON)
				return false;
			//이것을 추가 작성시 더 빠른 조건 처리가 가능
			//if (abs(cCol[i].GetVecData(j) - mat.cCol[i].GetVecData(j)) < epsilon)
			//	return false;
		}
	}

	return true;
}

bool cMatrix::operator!=(cMatrix & mat)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < cCol.size(); i++)
	{
		for (j = 0; j < cCol.size(); j++)
		{
			if (abs(cCol[i].GetVecData(j) - mat.cCol[i].GetVecData(j)) < EPSILON)
			{
				cout << "두 행렬은 일치합니다" << endl;
				return false;
			}
		}
	}
	cout << "두 행렬은 일치하지 않습니다" << endl;
	return true;
}

cMatrix cMatrix::operator+(cMatrix & mat)
{
	int i = 0;
	int j = 0;

	cMatrix result(cCol.size());

	for (i = 0; i < cCol.size(); i++)
	{
		for (j = 0; j < cCol.size(); j++)
		{
			result[i][j] = cCol[i].GetVecData(j) + mat.cCol[i].GetVecData(j);
		}
	}
	
	//return !(*this == mat); //-> 윗 소스 생략하고 이것만 작성해도 가능
	
	return result;
}

cMatrix cMatrix::operator-(cMatrix & mat)
{
	int i = 0;
	int j = 0;

	cMatrix result(cCol.size());


	for (i = 0; i < cCol.size(); i++)
	{
		for (j = 0; j < cCol.size(); j++)
		{
			result[i][j] = cCol[i].GetVecData(j) - mat.cCol[i].GetVecData(j);
		}
	}


	return cMatrix();
}

cMatrix cMatrix::operator*(cMatrix & mat)
{
	int i = 0;
	int j = 0;
	int k = 0;

	cMatrix result(cCol.size());

	


	for (i = 0; i < cCol.size(); i++) 
	{
		for (j = 0; j < cCol.size(); j++) 
		{
			for (k = 0; k < cCol.size(); k++) 
			{
				result[i][j] += cCol[i].GetVecData(k) * mat.cCol[k].GetVecData(j);
			}
			
		}
	}


	return result;
}

cMatrix cMatrix::operator*(float f)
{
	int i = 0;
	int j = 0;

	cMatrix result(cCol.size());

	for (i = 0; i < cCol.size(); i++)
	{
		for (j = 0; j < cCol.size(); j++)
		{
			result[i][j] = cCol[i].GetVecData(j) * f;
		}
	}

	return result;
}

cMatrix cMatrix::operator/(float f)
{
	int i = 0;
	int j = 0;
	float temp = 1 / f;


	cMatrix result(cCol.size());


	for (i = 0; i < cCol.size(); i++) 
	{
		for (j = 0; j < cCol.size(); j++) 
		{
			result[i][j] = cCol[i].GetVecData(j) * temp;
		}
	}

	return result;
}

cMatrix cMatrix::Inverse()
{
	//역행렬 = (1 / D) * adjoint

	//Determonant -> ad-bc를 통해 cofactor를 구한다 -> cofator를 전치시켜 adjoint를 구한다 -> adjoint/det 하면 역행렬이 구해진다
	
	return Adjoint() / (Determinant());
}


cMatrix cMatrix::Inverse(OUT float & fDetermonant) 
{
	cMatrix matRet = cMatrix::Identity(Dimension());
	fDetermonant = Determinant();
	if (-EPSILON <  fDetermonant && fDetermonant < EPSILON)
	{
		cout << "역행렬이 존재 하지 않음!!!" << endl;
		return matRet;
	}
	cMatrix matAdj = Adjoint();

	matRet = matAdj * (1 / fDetermonant);
	return matRet;
}


float cMatrix::Determinant()
{
	//2*2행렬일 때 -> ad-bc 
	//3*3 이상일 때 -> 각 요소에 코펙터를 곱한 후 더한다 
	// (-1)^(1+j)

	int i = 0;
	int j = 0;

	float result = 0;

	if (cCol.size() == 2)
	{
		float a = cCol[0][0];
		float b = cCol[0][1];
		float c = cCol[1][0];
		float d = cCol[1][1];

		return a*d - b*c;
	}
	else
	{
		for (i = 0; i < cCol.size(); i++)
		{
			result += cCol[0][i] * Cofactor(0, i);
		}

	}


	return result;
}

float cMatrix::Cofactor(int nRow, int nCol)
{
	//자신의 행열을 제외하고 ad-bc
	/*
		int nConst = 1;
		if((nRow + n nCol) % 2 != 0)
			nConst = -1;
		return nConst * Minor(nRow, nCol);
	*/

	return Minor(nRow, nCol) * pow(-1, nRow + nCol);
}

float cMatrix::Minor(int nRow, int nCol)
{
	//자기 자신의 행과 열을 제외한 행열
	int i = 0;
	int j = 0;
	int x = 0;
	int y = 0;

	cMatrix result(cCol.size() - 1);

	// nRow 와 nCol을 제외한 행열
	for (i = 0; i < cCol.size(); i++)
	{
		for (j = 0; j < cCol.size(); j++)
		{
			if (i != nRow && j != nCol)
			{

				result[x][y] = cCol[i].GetVecData(j);
				y++;

				if (y == result.cCol.size())
				{
					x++;
					y = 0;
				}

			}
		}
	}

	//result.Print();


	return result.Determinant();
}

cMatrix cMatrix::Scale(float plus)
{
	cMatrix result;
	result = result.Identity(4);

	result[0][0] = plus;
	result[1][1] = plus;
	result[2][2] = plus;

	return result;
}

cMatrix cMatrix::Translation(float x, float y, float z)
{
	//이동행렬
	cMatrix result(4);
	result= result.Identity(4);

	result[3][0] = x;
	result[3][1] = y;
	result[3][2] = z;
	
	return result;
}

cMatrix cMatrix::Translation(cVector3 & v)
{
	cMatrix result(4);
	result = result.Identity(4);

	result[3][0] = v.get_x();
	result[3][1] = v.get_y();
	result[3][2] = v.get_z();

	return result;
}

cMatrix cMatrix::RotationX(float Angle)
{
	cMatrix result(4);
	result = result.Identity(4);

	result[1][1] = cosf(Angle);
	result[1][2] = sinf(Angle);
	result[2][1] = -sinf(Angle);
	result[2][2] = cosf(Angle);

	return result;
}

cMatrix cMatrix::RotationY(float Angle)
{
	cMatrix result(4);
	result = result.Identity(4);

	result[0][0] = cosf(Angle);
	result[0][2] = -sinf(Angle);
	result[2][0] = sinf(Angle);
	result[2][2] = cosf(Angle);




	return result;
}

cMatrix cMatrix::RotationZ(float Angle)
{

	cMatrix result(4);
	result = result.Identity(4);

	result[0][0] = cosf(Angle);
	result[0][1] = sinf(Angle);
	result[1][0] = -sinf(Angle);
	result[1][1] = cosf(Angle);

	return result;
}

cMatrix cMatrix::View(cVector3 & vEye, cVector3 & vLookAt, cVector3 & vUp)
{
	/*
	ViewMatrix
	eye, look at, up

	l = look vector
	r = right vector

	u = up vector
	r.x			u.x				l.x				0
	r.y			u.y				l.y				0
	r.z			u.z				l.z				0
	-r.dot.eye	-u.dot.eye		-l.dot eye		1

	*/

	cMatrix view(4);
	view = view.Identity(4);

	//vLookAt - eye 하면 lookVector가 만들어진다
	cVector3 lookVector = (vLookAt - vEye).Normalize();

	cVector3 rightVector = rightVector.Cross(vUp, lookVector);

	//look 과 right 를 croos 시키면 다시 up이 나온다
	cVector3 upVector = vUp.Cross(lookVector, rightVector);
	
	view[0][0] = rightVector.get_x();
	view[1][0] = rightVector.get_y();
	view[2][0] = rightVector.get_z();

	view[0][1] = upVector.get_x();
	view[1][1] = upVector.get_y();
	view[2][1] = upVector.get_z();

	view[0][2] = lookVector.get_x();
	view[1][2] = lookVector.get_y();
	view[2][2] = lookVector.get_z();
	//-r.dot.eye - u.dot.eye - l.dot eye		0

	view[3][0] = -cVector3::Dot(rightVector, vEye);
	view[3][1] = -cVector3::Dot(upVector, vEye);
	view[3][2] = -cVector3::Dot(lookVector, vEye);
	
	return view;
}

cMatrix cMatrix::Projection(float fFovY, float fAspect, float fNearZ, float fFarZ)
{
	/*
	 fFovY = 각도(시야각)
	 fAspect = 종횡비 = 폭 / 높이
	 
	 fNearZ = 어디서부터 볼 것인지 // 일반적으로 1~1000까지 값을 준다
	 fFarZ = 어디까지 볼 것인지	// 일반적으로 1~1000까지 값을 준다
	 */
	
	/*
	 *투영
	sy = cot(fov / 2) => 1.0f / tanf(fFovY / 2.0f) ==> 원근감 
	sx = sy / aspect

	sx			0			0				0
	0			sy			0				0
	0			0			fz/(fz-nz)		1
	0			0			-fz*nz/(fz-nz)	0

	*/

	float sy = 1.0f / tanf(fFovY / 2.0f);
	float sx = sy / fAspect;

	cMatrix result(4);
	
	result[0][0] = sx;
	result[1][1] = sy;
	result[2][2] = fFarZ / (fFarZ - fNearZ);
	result[2][3] = 1;
	result[3][2] = -fFarZ * fNearZ / (fFarZ - fNearZ);

	
	return result;
}

cMatrix cMatrix::Viewport(float x, float y, float w, float h, float minZ, float maxZ)
{
	/* x, y 윈도우의 시작 좌표 (0, 0)
	 * w, h 윈도우의 끝 좌표(width, height)
	 * minZ, maxZ 평상시 minZ는 0이다, maxZ는 1이다. 무엇을 의미 하는지는 나중에
	 * 
	 * Projection까지가 3D 공간이다
	 * 월드 행렬은 3D공간이다
	 * 그러나 윈도우안에서 공간은 2D이다
	 * 때문에 평면화 작업을 해줘야하는데 그것을 해주는 곳이 ViewPort이다.
	 * 윈도우 상에는 실수가 없다 모두 정수이다(양수만 존재). 수학좌표랑 윈도우 좌표는 y가 반대이다.
	 * 
	 */

	//h값을 뒤집어 주는 이유는 y축이 반대이기 때문
	//

	
	/*
		w/2.0f			0			0			0
		0				-h/2.0f		0			0
		0				0			maxz-minz	0
		x+(w/2.0f)		y+(h/2.0f)	minz		1

		default => maxz = 1, minz = 0
	*/

	cMatrix result(4);

	result[0][0] = w / 2.0f;
	result[1][1] = -h / 2.0f;
	result[2][2] = maxZ - minZ;
	result[3][0] = x + (w / 2.0f);
	result[3][1] = y + (h / 2.0f);
	result[3][2] = minZ;
	result[3][3] = 1;
	

	
	return result;
}

cMatrix cMatrix::Adjoint()
{
	int i = 0;
	int j = 0;

	cMatrix result(cCol.size());
	for (i = 0; i < cCol.size(); i++)
	{
		for (j = 0; j < cCol.size(); j++)
		{
			result[i][j] = 0;
		}
	}


	for (i= 0; i < cCol.size(); i++) 
	{
		for (j = 0; j < cCol.size(); j++) 
		{
			result[i][j] = Cofactor(i, j);
		}
	}

	return result.Transpose();;
}

cMatrix cMatrix::Transpose()
{
	//행과 전치행열 -> 행과 열을 체인지
	int i = 0;
	int j = 0;


	cMatrix result(cCol.size());


	for (i = 0; i < cCol.size(); i++)
	{
		for (j = 0; j < cCol.size(); j++)
		{
			result[i][j] = cCol[j].GetVecData(i);
		}
	}

	return result;
}

float Radian(float angle)
{
	float radian = angle * M_PI / 180;
	return radian;
}

cMatrix cMatrix::Pipeline(RECT rt)
{
	// S * R * T * V * P * VP;
	//최종 행렬 => 3D값이지만 윈도우에 들어가면 2D값이 된다.

	cMatrix result(4);

	
	//초기값은 항등행렬로
	result = result.Identity(4);

	cVector3 eye(0, 10, -20);	// => 나의 눈
	cVector3 lookAt(0, 0, 0); // => 바라볼 사물의 중심점
	cVector3 up(0, 1, 0);



	result = result * cMatrix::RotationY((changeAngle)); //=> 각도 회전
	
	result = result * cMatrix::View(eye, lookAt, up);//카메라
	
	result = result * cMatrix::Projection(Radian(45), (float)rt.right / (float)rt.bottom, 1, 1000);
	
	result = result * cMatrix::Viewport(0, 0, (float)rt.right, (float)rt.bottom, 0, 1);



	return result;
}