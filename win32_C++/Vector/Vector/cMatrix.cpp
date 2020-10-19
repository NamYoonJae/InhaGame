#include "stdafx.h"
#include "cMatrix.h"

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
		//m_vecData.push_back(rand() % 10);
		m_vecData.push_back(0);	
	}

	
}

void cMatrix::cRow::Resize(int nDimension)
{
	//값을 넣는 함수로 작성함 . 내 방식에는 필요없는 함수
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

	cout << endl;

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
	cout << "단위행렬 생성" << endl;
	cMatrix matrix(nDimension);

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
	cout << "서로 같은가?" << endl;
	for (i = 0; i < cCol.size(); i++) 
	{
		for (j = 0; j < cCol.size(); j++) 
		{
			if (abs(cCol[i].GetVecData(j) - mat.cCol[i].GetVecData(j)) > epsilon)
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
	cout << "서로 다른가?" << endl;
	for (i = 0; i < cCol.size(); i++)
	{
		for (j = 0; j < cCol.size(); j++)
		{
			if (abs(cCol[i].GetVecData(j) - mat.cCol[i].GetVecData(j)) < epsilon)
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
	cout << "==덧셈 임시 배열 생성==" << endl;
	cMatrix result(cCol.size());

	cout << "==덧셈 실행==" << endl;
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
	cout << "==뺄셈 임시 배열 생성==" << endl;
	cMatrix result(cCol.size());

	cout << "==뺄셈 실행==" << endl;

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

	cout << "==곱셈 matrix * matrix 임시 배열 생성==" << endl;
	cMatrix result(cCol.size());

	for (i = 0; i < cCol.size(); i++) 
	{
		for (j = 0; j < cCol.size(); j++) 
		{
			result[i][j] = 0;
		}
	}

	cout << "==곱셈 실행==" << endl;

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
	cout << "==스칼라 곱셈 임시 배열 생성==" << endl;
	cMatrix result(cCol.size());

	for (i = 0; i < cCol.size(); i++)
	{
		for (j = 0; j < cCol.size(); j++)
		{
			result[i][j] = 0;
		}
	}

	return cMatrix();
}

cMatrix cMatrix::operator/(float f)
{
	int i = 0;
	int j = 0;
	float temp = 1 / f;

	cout << "==나눗셈 임시 배열 생성==" << endl;
	cMatrix result(cCol.size());

	for (i = 0; i < cCol.size(); i++)
	{
		for (j = 0; j < cCol.size(); j++)
		{
			result[i][j] = 0;
		}
	}

	cout << "==나눗셈 실행==" << endl;
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
	if (-epsilon <  fDetermonant && fDetermonant < epsilon)
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

	for (i = 0; i < result.cCol.size(); i++)
	{
		for (j = 0; j < result.cCol.size(); j++)
		{
			result[i][j] = 0;
		}
	}

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

	cout << "== 임시 배열 생성==" << endl;
	cMatrix result(cCol.size());

	for (i = 0; i < cCol.size(); i++)
	{
		for (j = 0; j < cCol.size(); j++)
		{
			result[i][j] = 0;
		}
	}

	for (i = 0; i < cCol.size(); i++)
	{
		for (j = 0; j < cCol.size(); j++)
		{
			result[i][j] = cCol[j].GetVecData(i);
		}
	}


	return result;
}