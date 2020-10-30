#pragma once
#include "cD3D.h"
class cEdu :
	public cD3D
{
public:
	cEdu();
	~cEdu();

	void OnSetUp();
	void OnUpdate();
	void OnRender();
};

