#include "stdafx.h"
#include "galsPanic.h"
#include <vector>
#include <stdio.h>
#include <iostream>

using namespace std;

extern vector <POINT> vPointList;
extern vector <POINT> vLine;

bool moveImpossible(int c_CenterX, int c_CenterY, int c_move, int direction);

enum
{
	enum_right = 1,
	enum_left = 2,
	enum_up = 3,
	enum_down = 4,

};

Charactor::Charactor()
{
}

Charactor::Charactor(int x, int y)
{
	c_CenterX = 400;
	c_CenterY = 400;
	c_R = 5;
	c_move = 5;
	c_Direction = 0;
	c_StartX = 0;
	c_StartY = 0;
}

Charactor::~Charactor()
{
}

void Charactor::Draw(HDC hdc)
{
	Ellipse(hdc, c_CenterX - c_R, c_CenterY - c_R, c_CenterX + c_R, c_CenterY + c_R);
}

void Charactor::Move(HDC hdc, int direction, HWND hWnd)
{

	if (c_Direction != direction) 
	{
		POINT tempPoint;
		tempPoint.x = c_CenterX;
		tempPoint.y = c_CenterY;
		vLine.push_back(tempPoint);

		c_StartX = c_CenterX;
		c_StartY = c_CenterY;

	}
	
	MoveToEx(hdc, c_StartX, c_StartY, NULL);
	LineTo(hdc, c_CenterX, c_CenterY);
	RECT rt;
	GetClientRect(hWnd, &rt);
	bool result = 0;

	if (direction == enum_right) 
	{

		if (c_CenterX + c_R < rt.right)
		{
			result = moveImpossible(c_CenterX, c_CenterY, c_move, enum_right);

			if (result == true) //짝수이거나 0이면 외부 판정으로 이동 가능
			{
				c_CenterX += c_move;
			}

		}

	}
	else if (direction == enum_left)
	{

		if (c_CenterX-c_R > rt.left)
		{
			result = moveImpossible(c_CenterX, c_CenterY, c_move, enum_left);

			if (result == true) 
			{
				c_CenterX -= c_move;
			}
		}
	}
	else if (direction == enum_up)
	{
		if (c_CenterY-c_R > rt.top) 
		{
			result = moveImpossible(c_CenterX, c_CenterY, c_move, enum_up);

			if (result == true)
			{
				c_CenterY -= c_move;
			}
		}
	}
	else if (direction == enum_down)
	{
		if (c_CenterY + c_R < rt.bottom - c_R) 
		{
			result = moveImpossible(c_CenterX, c_CenterY, c_move, enum_up);
			if (result == true)
			{
				c_CenterY += c_move;
			}
		}
	}

	Ellipse(hdc, c_CenterX - c_R, c_CenterY - c_R, c_CenterX + c_R, c_CenterY + c_R);

}

int Charactor::GetCenterX()
{
	return c_CenterX;
}

int Charactor::GetCenterY()
{
	return c_CenterY;
}

bool moveImpossible(int c_CenterX, int c_CenterY, int c_move, int direction)
{
	int i = 0;
	int j = 0;
	int count = 0;
	int moveTempX = 0;
	int moveTempY = 0;

	if (direction == enum_right) 
	{
		moveTempX = c_CenterX + c_move;
		moveTempY = c_CenterY;
	}
	else if (direction == enum_left) 
	{
		moveTempX = c_CenterX - c_move;
		moveTempY = c_CenterY;
	}
	else if (direction == enum_up) 
	{
		moveTempX = c_CenterX;
		moveTempY = c_CenterY - c_move;
	}
	else if (direction == enum_down) 
	{
		moveTempX = c_CenterX;
		moveTempY = c_CenterY;
	}

	for (i = 0; i < vPointList.size(); i++) 
	{
		int j = (i + 1) % vPointList.size();

		if ((vPointList[i].y > moveTempY) != (vPointList[j].y > moveTempY))
		{
			double atX = (vPointList[j].x - vPointList[i].x) * (moveTempY - vPointList[i].y) / (vPointList[j].y - vPointList[i].y) + vPointList[i].x;

			if (moveTempX < atX)
				count++;
			cout << i <<"번째" <<"vPointList[].x : " << vPointList[i].x << endl;
			cout << i <<"번째" <<"vPointList[].y : " << vPointList[i].y << endl;

			if (moveTempX == vPointList[i].x || moveTempY == vPointList[i].y)
			{
				return true;
			}
		}


	}
	cout << count << endl;

	if (count % 2 == 0 || count == 0)
	{
		return true;
	}

	return false;
}
