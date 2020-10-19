#include "stdafx.h"
#include "cVector3.h"
#include <cmath>
#include <iostream>

using namespace std;

cVector3::cVector3()
{
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
	//¹æÇâ°ú ±æÀÌ°¡ °°ÀºÁö ÆÇº°

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

	sumX = x + vec.x;
	sumY = y + vec.y;
	sumZ = z + vec.z;

	cout << "µ¡¼À °á°ú" << endl;
	cout << "sumX: " << sumX << endl;
	cout << "sumY: " << sumY << endl;
	cout << "sumZ: " << sumZ << endl;
	cout << endl;
	cout << endl;

	return cVector3();
}

cVector3 cVector3::operator-(cVector3 & vec)
{

	imsubX = x - vec.x;
	imsubY = y - vec.y;
	imsubZ = z - vec.z;

	cout << "»¬¼À °á°ú" << endl;
	cout << "imsubX: " << imsubX << endl;
	cout << "imsubY: " << imsubY << endl;
	cout << "imsubZ: " << imsubZ << endl;
	cout << endl;
	cout << endl;

	return cVector3();
}

cVector3 cVector3::operator*(float f)
{

	mulX = x * f;
	mulY = y * f;
	mulZ = z * f;

	cout << "°ö¼À °á°ú" << endl;
	cout << "mulX: " << mulX << endl;
	cout << "mulY: " << mulY << endl;
	cout << "mulZ: " << mulZ << endl;
	cout << endl;
	cout << endl;
	return cVector3();
}

cVector3 cVector3::operator/(float f)
{

	divX = x / f;
	divY = y / f;
	divZ = z / f;;

	cout << "³ª´°¼À °á°ú" << endl;
	cout << "divX: " << divX << endl;
	cout << "divY: " << divY << endl;
	cout << "divZ: " << divZ << endl;
	cout << endl;
	cout << endl;

	return cVector3();
}

float cVector3::Dot(cVector3 & v1, cVector3 & v2)
{
	//°¢ º¯³¢¸® °öÇÏ°í ´õÇÏ±â
	cVector3 cV;
	cV.dotResult = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;

	cout << "º¤ÅÍ ³»Àû °á°ú" << endl;
	cout << "cV->dotResult: " << cV.dotResult << endl;

	return cV.dotResult;
}

cVector3 cVector3::Cross(cVector3 & v1, cVector3 & v2)
{
	cVector3 cV;

	cV.crossX = v1.y * v2.z - v1.z * v2.y;
	cV.crossY = v1.z * v2.x - v1.x * v2.z;
	cV.crossZ = v1.x * v2.y - v1.y * v2.x;

	cout << "º¤ÅÍ ¿ÜÀû °á°ú" << endl;
	cout << "cV->crossX: " << cV.crossX << endl;
	cout << "cV->crossY: " << cV.crossY << endl;
	cout << "cV->crossZ: " << cV.crossZ << endl;
	cout << endl;
	cout << endl;

	return cVector3();
}

float cVector3::Length()
{
	length = sqrt(x*x + y*y + z*z);

	cout << "º¤ÅÍ ±æÀÌ" << endl;
	cout << "length: " << length << endl;

	return length;
}

cVector3 cVector3::Normalize()
{

	NormalizeX = x / length;
	NormalizeY = y / length;
	NormalizeZ = z / length;

	cout << "º¤ÅÍ Á¤±ÔÈ­" << endl;
	cout << "NormalizeX: " << NormalizeX << endl;
	cout << "NormalizeY: " << NormalizeY << endl;
	cout << "NormalizeZ: " << NormalizeZ << endl;
	cout << endl;
	cout << endl;
	
	return cVector3();
}

float cVector3::Angle(cVector3 & v1, cVector3 & v2)
{
	cVector3 cV;
	cV.dotResult = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;

	cout << "º¤ÅÍ ³»Àû °á°ú" << endl;
	cout << "cV->dotResult: " << cV.dotResult << endl;

	float degree = acos(cV.dotResult);
	cout << "°¢µµ: " << degree;
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
	
	//Cross ¶û B -A ³»Àû
	float crossResult = x1 * crossX + y1 * crossY + z1 * crossZ;
	float degree = acos(crossResult) * (180 / 3.14);
	cout << "degree: " << degree << endl;


	//ÀÌ°Íµµ 90µµ°¡ ³ª¿Í¾ßÇÑ´Ù
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
