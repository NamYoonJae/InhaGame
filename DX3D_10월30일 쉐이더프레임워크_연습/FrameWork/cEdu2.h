#pragma once
#include "cD3D.h"
class cEdu2 :
	public cD3D
{
public:
	cEdu2();
	~cEdu2();

	void OnSetUp();
	void OnUpdate();
	void OnRender();
};

