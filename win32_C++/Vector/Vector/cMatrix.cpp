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
	//���� �ִ� �Լ��� �ۼ��� . �� ��Ŀ��� �ʿ���� �Լ�
	m_vecData.resize(nDimension);

	for (size_t i = 0; i < nDimension; ++i)
	{
		m_vecData[i] = nDimension;
	}
}

float & cMatrix::cRow::operator[](int index)
{
	// TODO: ���⿡ ��ȯ ������ �����մϴ�.
	//���� ���� ��ȯ
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
	cout << "������� ����" << endl;
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
	cout << "���� ������?" << endl;
	for (i = 0; i < cCol.size(); i++) 
	{
		for (j = 0; j < cCol.size(); j++) 
		{
			if (abs(cCol[i].GetVecData(j) - mat.cCol[i].GetVecData(j)) > epsilon)
				return false;
			//�̰��� �߰� �ۼ��� �� ���� ���� ó���� ����
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
	cout << "���� �ٸ���?" << endl;
	for (i = 0; i < cCol.size(); i++)
	{
		for (j = 0; j < cCol.size(); j++)
		{
			if (abs(cCol[i].GetVecData(j) - mat.cCol[i].GetVecData(j)) < epsilon)
			{
				cout << "�� ����� ��ġ�մϴ�" << endl;
				return false;
			}
		}
	}
	cout << "�� ����� ��ġ���� �ʽ��ϴ�" << endl;
	return true;
}

cMatrix cMatrix::operator+(cMatrix & mat)
{
	int i = 0;
	int j = 0;
	cout << "==���� �ӽ� �迭 ����==" << endl;
	cMatrix result(cCol.size());

	cout << "==���� ����==" << endl;
	for (i = 0; i < cCol.size(); i++)
	{
		for (j = 0; j < cCol.size(); j++)
		{
			result[i][j] = cCol[i].GetVecData(j) + mat.cCol[i].GetVecData(j);
		}
	}
	
	//return !(*this == mat); //-> �� �ҽ� �����ϰ� �̰͸� �ۼ��ص� ����
	
	return result;
}

cMatrix cMatrix::operator-(cMatrix & mat)
{
	int i = 0;
	int j = 0;
	cout << "==���� �ӽ� �迭 ����==" << endl;
	cMatrix result(cCol.size());

	cout << "==���� ����==" << endl;

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

	cout << "==���� matrix * matrix �ӽ� �迭 ����==" << endl;
	cMatrix result(cCol.size());

	for (i = 0; i < cCol.size(); i++) 
	{
		for (j = 0; j < cCol.size(); j++) 
		{
			result[i][j] = 0;
		}
	}

	cout << "==���� ����==" << endl;

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
	cout << "==��Į�� ���� �ӽ� �迭 ����==" << endl;
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

	cout << "==������ �ӽ� �迭 ����==" << endl;
	cMatrix result(cCol.size());

	for (i = 0; i < cCol.size(); i++)
	{
		for (j = 0; j < cCol.size(); j++)
		{
			result[i][j] = 0;
		}
	}

	cout << "==������ ����==" << endl;
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
	//����� = (1 / D) * adjoint

	//Determonant -> ad-bc�� ���� cofactor�� ���Ѵ� -> cofator�� ��ġ���� adjoint�� ���Ѵ� -> adjoint/det �ϸ� ������� ��������
	
	return Adjoint() / (Determinant());
}


cMatrix cMatrix::Inverse(OUT float & fDetermonant) 
{
	cMatrix matRet = cMatrix::Identity(Dimension());
	fDetermonant = Determinant();
	if (-epsilon <  fDetermonant && fDetermonant < epsilon)
	{
		cout << "������� ���� ���� ����!!!" << endl;
		return matRet;
	}
	cMatrix matAdj = Adjoint();

	matRet = matAdj * (1 / fDetermonant);
	return matRet;
}


float cMatrix::Determinant()
{
	//2*2����� �� -> ad-bc 
	//3*3 �̻��� �� -> �� ��ҿ� �����͸� ���� �� ���Ѵ� 
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
	//�ڽ��� �࿭�� �����ϰ� ad-bc
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
	//�ڱ� �ڽ��� ��� ���� ������ �࿭
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

	// nRow �� nCol�� ������ �࿭
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
	//��� ��ġ�࿭ -> ��� ���� ü����
	int i = 0;
	int j = 0;

	cout << "== �ӽ� �迭 ����==" << endl;
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