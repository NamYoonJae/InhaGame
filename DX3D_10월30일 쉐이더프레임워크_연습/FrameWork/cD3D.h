#pragma once
class cD3D
{
private:


public:
	cD3D();
	virtual ~cD3D();

	void SetUp();
	void Update();
	void Render();


	virtual void OnSetUp() = 0;
	virtual void OnUpdate() = 0;
	virtual void OnRender() = 0;


};

