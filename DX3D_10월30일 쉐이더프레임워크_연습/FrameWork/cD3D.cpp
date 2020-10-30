#include "stdafx.h"
#include "cD3D.h"


cD3D::cD3D()
{
}


cD3D::~cD3D()
{
}

void cD3D::SetUp()
{
	OnSetUp();
}

void cD3D::Update()
{
	OnUpdate();
}

void cD3D::Render()
{
	OnRender();
}
