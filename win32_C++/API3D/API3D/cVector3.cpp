#include "stdafx.h"
#include "cVector3.h"

using namespace std;

cVector3::cVector3()
{
	x = 0;
	y = 0;
	z = 0;
}

cVector3::cVector3(float a, float b, float c)
{
	x = a;
	y = b;
	z = c;

	sumX = sumY = sumZ = imsubX = imsubY = imsubZ = mulX = mulY = mulZ = divX = divY =  divZ = dotResult = crossResult = crossX = crossY = crossZ = NormalizeX = NormalizeY = NormalizeZ = 0;

}


cVector3::~cVector3()
{
}


bool cVector3::operator==(cVector3 & vec)
{
	//방향과 길이가 같은지 판별

	if (x != vec.x)
	{
		return false;
	}
	else if (y != vec.y) 
	{
		return false;
	}
	else if (z != vec.z) 
	{
		return false;
	}



	return true;
}


bool cVector3::operator!=(cVector3 & vec)
{
	if (x == vec.x)
	{
		return false;
	}
	else if (y == vec.y)
	{
		return false;
	}
	else if (z == vec.z)
	{
		return false;
	}

	return true;
}

cVector3 cVector3::operator+(cVector3 & vec)
{

	cVector3 v;

	v.x = x + vec.x;
	v.y =  y + vec.y;
	v.z = z + vec.z;

	return v;
}

cVector3 cVector3::operator-(cVector3 & vec)
{

	cVector3 v;

	v.x = x - vec.x;
	v.y = y - vec.y;
	v.z = z - vec.z;

	return v;

}

cVector3 cVector3::operator*(float f)
{

	cVector3 v;
	v.x = x * f;
	v.y = y * f;
	v.z = z * f;

	return v;
}

cVector3 cVector3::operator/(float f)
{
	cVector3 v;
	v.x = x / f;
	v.y = y / f;
	v.z = z / f;

	return v;

}

float cVector3::Dot(cVector3 & v1, cVector3 & v2)
{
	//각 변끼리 곱하고 더하기
	cVector3 cV;
	cV.dotResult = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;

	return cV.dotResult;
}

cVector3 cVector3::Cross(cVector3 & v1, cVector3 & v2)
{
	cVector3 cV;

	cV.x = v1.y * v2.z - v1.z * v2.y;
	cV.y = v1.z * v2.x - v1.x * v2.z;
	cV.z = v1.x * v2.y - v1.y * v2.x;
		
	return cV;
}

float cVector3::Length()
{
	length = sqrt(x*x + y*y + z*z);

	return length;
}

cVector3 cVector3::Normalize()
{
	cVector3 v;
	length = Length();
	
	v.x = x / length;
	v.y = y / length;
	v.z = z / length;

	return v;
}

float cVector3::Angle(cVector3 & v1, cVector3 & v2)
{
	cVector3 cV;
	cV.dotResult = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;


	float degree = acos(cV.dotResult);

	return degree;
}

void cVector3::triangleVector(cVector3 & a, cVector3 & b, cVector3& c)
{
	
	//B - A
	float x1 = b.x - a.x;
	float y1 = b.y - a.y;
	float z1 = b.z - a.z;

	//C - A
	float x2 = c.x - a.x;
	float y2 = c.y - a.y;
	float z2 = c.z - a.z;

	//Cross (x1, y1, z1), (x2, y2, z2)
	float crossX = y1 * z2 - z1 * y2;
	float crossY = z1 * x2 - x1 * z2;
	float crossZ = x1 * y2 - y1 * x2;
	
	//Cross 랑 B -A 내적
	float crossResult = x1 * crossX + y1 * crossY + z1 * crossZ;
	float degree = acos(crossResult) * (180 / 3.14);


	//이것도 90도가 나와야한다
	/*
	//A - C
	a.x - c.x;
	a.y - c.y;
	a.z - c.z;


	//B - C
	b.x - c.x;
	b.y - c.y;
	b.z - c.z;
	*/

}

cVector3 cVector3::Transformcoord(cVector3 & v, cMatrix & mat)
{
	//점 이동에 관해 쓰인다
	/*

		//vector * M 을 하면 된다

		먼저 M을 구하자
		M = Rotate * Translation	

		vector * M  //vector는 내가 회전 시키고자 하는 점이다.

		곱해서 나온 결과값 (x, y, z ,w)에서 곱했기 때문에 w가 1이 아닐수도 있다
		때문에 w를 나눠준다
		(x/w, y/w, z/w, w/w);

	*/
	
	float w = 1;
	cVector3 result;

	result.x = v.x * mat[0][0] + v.y * mat[1][0] + v.z * mat[2][0] + w * mat[3][0];
	result.y = v.x * mat[0][1] + v.y * mat[1][1] + v.z * mat[2][1] + w * mat[3][1];
	result.z = v.x * mat[0][2] + v.y * mat[1][2] + v.z * mat[2][2] + w * mat[3][2];
	w = v.x * mat[0][3] + v.y * mat[1][3] + v.z * mat[2][3] + mat[3][3];
	
	if(-EPSILON > w || w > EPSILON) 
	{
		result.x = result.x / w;
		result.y = result.y / w;
		result.z = result.z / w;
		w = w / w;
	}
	

	return result;
}

cVector3 cVector3::TransformNormal(cVector3 & v, cMatrix & mat)
{
	//벡터이동에 관해 쓰인다
	cVector3 result;



	result.x = v.x * mat[0][0] + v.y * mat[1][0] + v.z * mat[2][0];
	result.y = v.x * mat[0][1] + v.y * mat[1][1] + v.z * mat[2][1];
	result.z = v.x * mat[0][2] + v.y * mat[1][2] + v.z * mat[2][2];

	return cVector3();
}
