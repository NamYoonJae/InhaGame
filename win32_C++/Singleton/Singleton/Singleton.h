#pragma once

#include "resource.h"
#include <iostream>

using namespace std;

class cGameManager
{
private:
	cGameManager() {}
public:
	~cGameManager() {}
public:
	static cGameManager* GetInstance()
	{
		static cGameManager instance;
		return &instance;

		//static cGameManager* instance = new cGameManager;
		//return instance;
		//�̷��� ��򰡿��� ���������
	}
private:
	int objCount;
	string playerName;
	int HP;
public:
	int GetObjCount() { return objCount; }
	void SetObjCount(int set) { objCount = set };
};

#define g_pGameManager cGameManager::GetInstance()