#pragma once
class cVector3
{



private:
	float x, y, z;
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
	cVector3 operator*(float f); //°ö¼ÁÀº ½ºÄ®¶ó¸¦ °öÇÑ´Ù
	cVector3 operator/(float f);

	static float Dot(cVector3& v1, cVector3& v2);
	static cVector3 Cross(cVector3& v1, cVector3& v2);
	float Length();
	cVector3 Normalize();

	static float Angle(cVector3& v1, cVector3& v2);

	void triangleVector(cVector3& a, cVector3& b, cVector3& c);

};

