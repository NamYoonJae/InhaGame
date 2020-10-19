#pragma once
class cMatrix; // -> 전방 선언 => 어딘가에 cMatrix가 선언되어 있으니 참조하라는 뜻

class cVector3
{



private:
	float x, y, z;

private:
	float length;

	float sumX, sumY, sumZ;
	float imsubX, imsubY, imsubZ;

	float mulX, mulY, mulZ;
	float divX, divY, divZ;
	float dotResult, crossResult;

	float crossX, crossY, crossZ;
	float NormalizeX, NormalizeY, NormalizeZ;

public:
	cVector3();
	cVector3(float a, float b, float c);
	~cVector3();



	bool operator == (cVector3& vec);
	bool operator != (cVector3& vec);
	cVector3 operator+(cVector3& vec);
	cVector3 operator-(cVector3& vec);
	cVector3 operator*(float f); //곱셉은 스칼라를 곱한다
	cVector3 operator/(float f);

	static float Dot(cVector3& v1, cVector3& v2);
	static cVector3 Cross(cVector3& v1, cVector3& v2);
	float Length();
	cVector3 Normalize();

	static float Angle(cVector3& v1, cVector3& v2);

	void triangleVector(cVector3& a, cVector3& b, cVector3& c);
	static cVector3 Transformcoord(cVector3& v, cMatrix& mat);//점이 이동하는 코드
	static cVector3 TransformNormal(cVector3& v, cMatrix& mat);//벡터가 이동하는 코드




	float get_x() const
	{
		return x;
	}

	void set_x(float x)
	{
		this->x = x;
	}

	__declspec(property(get = get_x, put = set_x)) float X;

	float get_y() const
	{
		return y;
	}

	void set_y(float y)
	{
		this->y = y;
	}

	__declspec(property(get = get_y, put = set_y)) float Y;

	float get_z() const
	{
		return z;
	}

	void set_z(float z)
	{
		this->z = z;
	}

	__declspec(property(get = get_z, put = set_z)) float Z;

	
};

