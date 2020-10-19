#include "stdafx.h"
#include <iostream>
#include "cShape.h"
#include <vector>
#include <cstdlib>
#include <string>
#include <ctime>
#define _USE_MATH_DEFINES
#include<math.h>

extern vector<cShape> shapeList;
extern int mode;
using namespace std;

enum 
{
	enum_Right = 1,
	enum_Left = 2,
	enum_Down = 3,
	enum_Up = 4,
	enum_UpRight = 5,
	enum_DownRight = 6,
	enum_DownLeft = 7,
	enum_UpLeft = 8,

};

//int flag = 0;
//long cross = 0;

cShape::cShape()
{
	srand((unsigned int)time(NULL));
	m_moveX = rand() % 10+5;
	m_moveY = rand() % 10+5;
	m_Shapes = 0;
}

cShape::~cShape()
{
}

cCircle::cCircle()
{
}

cCircle::cCircle(int x, int y, int r)
{


	m_centerX = x;
	m_centerY = y;
	m_rSize = r;
	m_Shapes = 1;

	c_x1 = m_centerX - r;
	c_y1 = m_centerY - r;
	c_x2 = m_centerX + r;
	c_y2 = m_centerY + r;


	srand((unsigned int)time(NULL));
	int random = rand() % 10;

	switch (random)
	{
	case 0:
	case 1 :
		m_moveDirection = enum_Right;
		break;

	case 2 :
		m_moveDirection = enum_Left;
		break;

	case 3:
		m_moveDirection = enum_Down;
		break;

	case 4:
		m_moveDirection = enum_Up;
		break;

	case 5:
		m_moveDirection = enum_UpRight;
		break;

	case 6:
		m_moveDirection = enum_DownRight;
		break;

	case 7:
		m_moveDirection = enum_DownLeft;
		break;

	case 8:
	case 9:
		m_moveDirection = enum_UpLeft;
		break;

	default:
		break;
	}
	

}

cCircle::cCircle(int x, int y, int r, int z)
{
	m_centerX = x;
	m_centerY = y;
	m_rSize = r;
	m_moveDirection = z;
	m_Shapes = 1;

	c_x1 = m_centerX - r;
	c_y1 = m_centerY - r;
	c_x2 = m_centerX + r;
	c_y2 = m_centerY + r;

}

cCircle::~cCircle()
{

}

void cCircle::Draw(HDC hdc)
{
	RECT box;
	box.left = GetPointCenterX()-10;
	box.bottom = GetPointCenterY() + 10;
	box.right = GetPointCenterX() +10;
	box.top = GetPointCenterY()-10;
	Ellipse(hdc, c_x1, c_y1, c_x2, c_y2);
	
}

void cCircle::Move()
{
	
	switch (m_moveDirection)
	{


	case enum_Right:
		m_centerX += m_moveX;

		c_x1 = m_centerX - m_rSize;
		c_y1 = m_centerY - m_rSize;
		c_x2 = m_centerX + m_rSize;
		c_y2 = m_centerY + m_rSize;
		break;

	case enum_Left:
		m_centerX -= m_moveX;

		c_x1 = m_centerX - m_rSize;
		c_y1 = m_centerY - m_rSize;
		c_x2 = m_centerX + m_rSize;
		c_y2 = m_centerY + m_rSize;
		break;

	case enum_Down:
		m_centerY += m_moveY;

		c_x1 = m_centerX - m_rSize;
		c_y1 = m_centerY - m_rSize;
		c_x2 = m_centerX + m_rSize;
		c_y2 = m_centerY + m_rSize;
		break;

	case enum_Up:
		m_centerY -= m_moveY;

		c_x1 = m_centerX - m_rSize;
		c_y1 = m_centerY - m_rSize;
		c_x2 = m_centerX + m_rSize;
		c_y2 = m_centerY + m_rSize;

		break;

	case enum_UpRight:
		m_centerX += m_moveX;
		m_centerY -= m_moveY;

		c_x1 = m_centerX - m_rSize;
		c_y1 = m_centerY - m_rSize;
		c_x2 = m_centerX + m_rSize;
		c_y2 = m_centerY + m_rSize;
		break;

	case enum_DownRight:
		m_centerX += m_moveX;
		m_centerY += m_moveY;

		c_x1 = m_centerX - m_rSize;
		c_y1 = m_centerY - m_rSize;
		c_x2 = m_centerX + m_rSize;
		c_y2 = m_centerY + m_rSize;

		break;

	case enum_DownLeft:
		m_centerX -= m_moveX;
		m_centerY += m_moveY;

		c_x1 = m_centerX - m_rSize;
		c_y1 = m_centerY - m_rSize;
		c_x2 = m_centerX + m_rSize;
		c_y2 = m_centerY + m_rSize;
		break;

	case enum_UpLeft:
		m_centerX -= m_moveX;
		m_centerY -= m_moveY;

		c_x1 = m_centerX - m_rSize;
		c_y1 = m_centerY - m_rSize;
		c_x2 = m_centerX + m_rSize;
		c_y2 = m_centerY + m_rSize;
		break;
	default:
		break;
	}
	
}

void cCircle::Spin()
{

}

int cCircle::Collision(vector<cShape*> &shapeList, int n, RECT rt, int mode)
{
	
	int i = 0;
	int getCenterX = 0;
	int getCenterY = 0;
	long getR = 0;

	int getCenterX2 = 0;
	int getCenterY2 = 0;
	long getR2 = 0;
	long betwwen = 0;

	//shapeList[n]번째에 있는 도형의 center 좌표와 반지름
	getCenterX = shapeList[n]->GetPointCenterX();
	getCenterY = shapeList[n]->GetPointCenterY();
	getR = shapeList[n]->GetPointR();

	

	if (getCenterX - getR <= rt.top)
	{
		switch (m_moveDirection)
		{

		case enum_Left:
			m_moveDirection = enum_Right;
			break;
		case enum_DownLeft:
			m_moveDirection = enum_DownRight;
			break;
		case enum_UpLeft:
			m_moveDirection = enum_UpRight;
			break;

		default:
			break;
		}
	}
	else if (getCenterY - getR <= rt.left)
	{
		switch (m_moveDirection)
		{
		case enum_Up:
			m_moveDirection = enum_Down;
			break;
		case enum_UpLeft:
			m_moveDirection = enum_DownLeft;
			break;
		case enum_UpRight:
			m_moveDirection = enum_DownRight;
			break;
		default:
			break;
		}
	}
	else if (getCenterX + getR >= rt.right)
	{
		switch (m_moveDirection)
		{
		case enum_Right:
			m_moveDirection = enum_Left;
			break;
		case enum_UpRight:
			m_moveDirection = enum_UpLeft;
			break;
		case enum_DownRight:
			m_moveDirection = enum_DownLeft;
			break;
		default:
			break;
		}
	}
	else if (getCenterY + getR >= rt.bottom)
	{
		switch (m_moveDirection)
		{
		case enum_Down:
			m_moveDirection = enum_Up;
			break;
		case enum_DownRight:
			m_moveDirection = enum_UpRight;
			break;
		case enum_DownLeft:
			m_moveDirection = enum_UpLeft;
		default:
			break;
		}

	}

	switch (mode)
	{
	//튕기기
	case 1:
		for (i = n + 1; i < shapeList.size(); i++)
		{

			getCenterX2 = shapeList[i]->GetPointCenterX();
			getCenterY2 = shapeList[i]->GetPointCenterY();
			getR2 = shapeList[i]->GetPointR();

			betwwen = long(sqrt(pow(getCenterX2 - getCenterX, 2) + pow(getCenterY2 - getCenterY, 2)));
			

			//두 도형의 충돌
			if (betwwen < getR + getR2)
			{
				
				if (shapeList[n]->GetMoveDirection() == shapeList[i]->GetMoveDirection())
				{
					shapeList[n]->SetMoveDirection(enum_Right);
					shapeList[i]->SetMoveDirection(enum_UpLeft);
				}
				

				//move 좌표 체인지
				int tempX;
				int tempY;
				tempX = shapeList[n]->GetMoveX();
				tempY = shapeList[n]->GetMoveY();
				shapeList[n]->SetMove(shapeList[i]->GetMoveX(), shapeList[i]->GetMoveY());
				shapeList[i]->SetMove(tempX, tempY);

				//방향 체인지
				int temp_enum;
				temp_enum = shapeList[n]->GetMoveDirection();
				shapeList[n]->SetMoveDirection(shapeList[i]->GetMoveDirection());
				shapeList[i]->SetMoveDirection(temp_enum);

			}

		}
		break;

	//충돌시 합치기
	case 2:
		for (i = n + 1; i < shapeList.size(); i++) 
		{
			getCenterX2 = shapeList[i]->GetPointCenterX();
			getCenterY2 = shapeList[i]->GetPointCenterY();
			getR2 = shapeList[i]->GetPointR();

			betwwen = long(sqrt(pow(getCenterX2 - getCenterX, 2) + pow(getCenterY2 - getCenterY, 2)));

			
			//두 도형의 충돌
			if (betwwen < getR + getR2)
			{
				if (shapeList[n]->GetShapes() == shapeList[i]->GetShapes()) //서로 같은 도형이면 충돌로 판정하고 튕겨내기
				{
					if (shapeList[n]->GetMoveDirection() == shapeList[i]->GetMoveDirection())
					{
						shapeList[n]->SetMoveDirection(enum_Right);
						shapeList[i]->SetMoveDirection(enum_UpLeft);
					}


					//move 좌표 체인지
					int tempX;
					int tempY;
					tempX = shapeList[n]->GetMoveX();
					tempY = shapeList[n]->GetMoveY();
					shapeList[n]->SetMove(shapeList[i]->GetMoveX(), shapeList[i]->GetMoveY());
					shapeList[i]->SetMove(tempX, tempY);

					//방향 체인지
					int temp_enum;
					temp_enum = shapeList[n]->GetMoveDirection();
					shapeList[n]->SetMoveDirection(shapeList[i]->GetMoveDirection());
					shapeList[i]->SetMoveDirection(temp_enum);
				}
				
				else if (shapeList[i]->GetShapes() == 2)//사갹형이면
				{
					shapeList[n]->SetR();
					delete(shapeList[i]);
					shapeList.erase(shapeList.begin() + i);
					return 1;	
				}

				else if (shapeList[i]->GetShapes() == 3)  //별인 경우
				{

					shapeList[i]->SetR();
					delete(shapeList[n]);
					shapeList.erase(shapeList.begin() + n);
					return 1;

				}
				
			}
		}

		break;
	case 3:
	
		for (i = n + 1; i < shapeList.size(); i++) 
		{
			getCenterX2 = shapeList[i]->GetPointCenterX();
			getCenterY2 = shapeList[i]->GetPointCenterY();
			getR2 = shapeList[i]->GetPointR();

			betwwen = long(sqrt(pow(getCenterX2 - getCenterX, 2) + pow(getCenterY2 - getCenterY, 2)));

			
			//두 도형의 충돌
			if (betwwen < getR + getR2)
			{
				if (shapeList[n]->GetShapes() == shapeList[i]->GetShapes()) //서로 같은 도형이면 충돌로 판정하고 튕겨내기
				{
					if (shapeList[n]->GetMoveDirection() == shapeList[i]->GetMoveDirection())
					{
						shapeList[n]->SetMoveDirection(enum_Right);
						shapeList[i]->SetMoveDirection(enum_UpLeft);
					}


					//move 좌표 체인지
					int tempX;
					int tempY;
					tempX = shapeList[n]->GetMoveX();
					tempY = shapeList[n]->GetMoveY();
					shapeList[n]->SetMove(shapeList[i]->GetMoveX(), shapeList[i]->GetMoveY());
					shapeList[i]->SetMove(tempX, tempY);

					//방향 체인지
					int temp_enum;
					temp_enum = shapeList[n]->GetMoveDirection();
					shapeList[n]->SetMoveDirection(shapeList[i]->GetMoveDirection());
					shapeList[i]->SetMoveDirection(temp_enum);
				}
				
				else if (shapeList[i]->GetShapes() == 2)//사갹형이면
				{
					//지워질 도형의 좌표
					int ix = shapeList[i]->GetPointCenterX();
					int iy = shapeList[i]->GetPointCenterY();
					long ir = shapeList[i]->GetPointR();
					int iMoveDirect = shapeList[i]->GetMoveDirection();

					//long plus = ir * 2;

					if (ir >10) 
					{
						if (shapeList[n]->GetMoveDirection() == enum_Right) //다가온 원의 방향
						{
							shapeList[n]->SetMoveDirection(enum_Left);
							cRect* newcRect1 = new cRect(ix + ir, iy - ir, ir - 10, enum_UpRight);
							shapeList.push_back(newcRect1);

							cRect* newcRect2 = new cRect(ix + ir, iy + ir, ir - 10, enum_DownRight);
							shapeList.push_back(newcRect2);
						}

						else if (shapeList[n]->GetMoveDirection() == enum_Left)
						{
							shapeList[n]->SetMoveDirection(enum_Right);
							cRect* newcRect1 = new cRect(ix - ir, iy - ir, ir - 10, enum_UpLeft);
							shapeList.push_back(newcRect1);

							cRect* newcRect2 = new cRect(ix - ir, iy + ir, ir - 10, enum_DownLeft);
							shapeList.push_back(newcRect2);
						}

						else if (shapeList[n]->GetMoveDirection() == enum_Down)
						{
							shapeList[n]->SetMoveDirection(enum_Up);
							cRect* newcRect1 = new cRect(ix + ir, iy + ir, ir - 10, enum_DownRight);
							shapeList.push_back(newcRect1);

							cRect* newcRect2 = new cRect(ix - ir, iy + ir, ir - 10, enum_DownLeft);
							shapeList.push_back(newcRect2);
						}

						else if (shapeList[n]->GetMoveDirection() == enum_Up)
						{
							shapeList[n]->SetMoveDirection(enum_Down);
							cRect* newcRect1 = new cRect(ix + ir, iy - ir, ir - 10, enum_UpRight);
							shapeList.push_back(newcRect1);

							cRect* newcRect2 = new cRect(ix - ir, iy - ir, ir - 10, enum_UpLeft);
							shapeList.push_back(newcRect2);
						}

						else if (shapeList[n]->GetMoveDirection() == enum_UpRight)
						{
							shapeList[n]->SetMoveDirection(enum_DownRight);
							cRect* newcRect1 = new cRect(ix - ir, iy - ir, ir - 10, enum_Up);
							shapeList.push_back(newcRect1);

							cRect* newcRect2 = new cRect(ix + ir, iy - ir, ir - 10, enum_UpRight);
							shapeList.push_back(newcRect2);
						}

						else if (shapeList[n]->GetMoveDirection() == enum_DownRight)
						{
							shapeList[n]->SetMoveDirection(enum_UpRight);
							cRect* newcRect1 = new cRect(ix + ir, iy + ir, ir - 10, enum_DownRight);
							shapeList.push_back(newcRect1);

							cRect* newcRect2 = new cRect(ix - ir, iy + ir, ir - 10, enum_Down);
							shapeList.push_back(newcRect2);
						}

						else if (shapeList[n]->GetMoveDirection() == enum_DownLeft)
						{
							shapeList[n]->SetMoveDirection(enum_UpLeft);
							cRect* newcRect1 = new cRect(ix - ir, iy + ir, ir - 10, enum_DownLeft);
							shapeList.push_back(newcRect1);

							cRect* newcRect2 = new cRect(ix + ir, iy + ir, ir - 10, enum_Down);
							shapeList.push_back(newcRect2);
						}

						else if (shapeList[n]->GetMoveDirection() == enum_UpLeft)
						{
							shapeList[n]->SetMoveDirection(enum_DownLeft);
							cRect* newcRect1 = new cRect(ix - ir, iy - ir, ir - 10, enum_UpLeft);
							shapeList.push_back(newcRect1);

							cRect* newcRect2 = new cRect(ix + ir, iy - ir, ir - 10, enum_Up);
							shapeList.push_back(newcRect2);
						}

					}
					delete(shapeList[i]);
					shapeList.erase(shapeList.begin() + i);

					return 1;
					
					
				}
				
				else if (shapeList[i]->GetShapes() == 3)  //별인 경우
				{
					
					//원 n 이 쪼개지고 별 i 는 튕기기
					int nx = shapeList[n]->GetPointCenterX();
					int ny = shapeList[n]->GetPointCenterY();
					long nr = shapeList[n]->GetPointR();
					int nMoveDirect = shapeList[n]->GetMoveDirection();

					 
					if (nr > 10) 
					{


						if (shapeList[i]->GetMoveDirection() == enum_Right) 
						{
							shapeList[i]->SetMoveDirection(enum_Left);
							cCircle* newCircle1 = new cCircle(nx + nr, ny - nr, nr - 10, enum_UpRight);
							shapeList.push_back(newCircle1);

							cCircle* newCircle2 = new cCircle(nx + nr, ny + nr, nr - 10, enum_DownRight);
							shapeList.push_back(newCircle2);
						}
						else if (shapeList[i]->GetMoveDirection() == enum_Left)
						{
							shapeList[i]->SetMoveDirection(enum_Right);
							cCircle* newCircle1 = new cCircle(nx - nr, ny - nr, nr - 10, enum_UpLeft);
							shapeList.push_back(newCircle1);

							cCircle* newCircle2 = new cCircle(nx - nr, ny + nr, nr - 10, enum_DownLeft);
							shapeList.push_back(newCircle2);
						}
						else if (shapeList[i]->GetMoveDirection() == enum_Down)
						{
							shapeList[i]->SetMoveDirection(enum_Up);
							cCircle* newCircle1 = new cCircle(nx + nr, ny + nr, nr - 10, enum_DownRight);
							shapeList.push_back(newCircle1);

							cCircle* newCircle2 = new cCircle(nx - nr, ny + nr, nr - 10, enum_DownLeft);
							shapeList.push_back(newCircle2);
						}
						else if (shapeList[i]->GetMoveDirection() == enum_Up)
						{
							shapeList[i]->SetMoveDirection(enum_Down);
							cCircle* newCircle1 = new cCircle(nx + nr, ny - nr, nr - 10, enum_UpRight);
							shapeList.push_back(newCircle1);

							cCircle* newCircle2 = new cCircle(nx - nr, ny - nr, nr - 10, enum_UpLeft);
							shapeList.push_back(newCircle2);
						}
						else if (shapeList[i]->GetMoveDirection() == enum_UpRight)
						{
							shapeList[i]->SetMoveDirection(enum_DownRight);
							cCircle* newCircle1 = new cCircle(nx - nr, ny - nr, nr - 10, enum_Up);
							shapeList.push_back(newCircle1);

							cCircle* newCircle2 = new cCircle(nx + nr, ny - nr, nr - 10, enum_UpRight);
							shapeList.push_back(newCircle2);
						}
						else if (shapeList[i]->GetMoveDirection() == enum_DownRight)
						{
							shapeList[i]->SetMoveDirection(enum_UpRight);
							cCircle* newCircle1 = new cCircle(nx + nr, ny + nr, nr - 10, enum_DownRight);
							shapeList.push_back(newCircle1);

							cCircle* newCircle2 = new cCircle(nx - nr, ny + nr, nr - 10, enum_Down);
							shapeList.push_back(newCircle2);
						}
						else if (shapeList[i]->GetMoveDirection() == enum_DownLeft)
						{
							shapeList[i]->SetMoveDirection(enum_UpLeft);
							cCircle* newCircle1 = new cCircle(nx - nr, ny + nr, nr - 10, enum_DownLeft);
							shapeList.push_back(newCircle1);

							cCircle* newCircle2 = new cCircle(nx + nr, ny + nr, nr - 10, enum_Down);
							shapeList.push_back(newCircle2);
						}
						else if (shapeList[i]->GetMoveDirection() == enum_UpLeft)
						{
							shapeList[i]->SetMoveDirection(enum_DownLeft);
							cCircle* newCircle1 = new cCircle(nx - nr, ny + nr, nr - 10, enum_UpLeft);
							shapeList.push_back(newCircle1);

							cCircle* newCircle2 = new cCircle(nx + nr, ny + nr, nr - 10, enum_Up);
							shapeList.push_back(newCircle2);
						}

					}//(nr>10)

					delete(shapeList[n]);
					shapeList.erase(shapeList.begin() + n);
					return 1;
		
				}//(shapeList[i]->GetShapes() == 3)
				
			}// 충돌 체크 if(ir >10) 

		}//for문
		break;

	default:
		break;
	}
	
	
	return 0;
}

int cCircle::GetPointCenterX()
{
	return m_centerX;
}

int cCircle::GetPointCenterY()
{
	return m_centerY;
}

long cCircle::GetPointR()
{
	return m_rSize;
}

int cCircle::GetMoveDirection()
{
	return m_moveDirection;
}

void cCircle::SetMoveDirection(int enum_num)
{
	m_moveDirection = enum_num;
}

int cCircle::GetMoveX()
{
	return m_moveX;
}

int cCircle::GetMoveY()
{
	return m_moveY;
}

void cCircle::SetMove(int enum_numX, int enum_numY)
{
	m_moveX = enum_numX;
	m_moveY = enum_numY;
}

int cCircle::GetShapes()
{
	return m_Shapes;
}

void cCircle::SetR()
{
	m_rSize += 10;
}




cRect::cRect()
{
}

cRect::cRect(int x, int y, int r)
{
	m_centerX = x;
	m_centerY = y;
	m_rSize = r;
	m_spin = 0;
	m_Shapes = 2;


	for (int i = 0; i < 4; i++) 
	{
		rectPoint[i].x = long(m_centerX + m_rSize * sin((90 * i + 45) * M_PI / 180));
		rectPoint[i].y = long(m_centerY - m_rSize * cos((90 * i + 45) * M_PI / 180));
	}

	srand((unsigned int)time(NULL));
	int random = rand() % 10;

	switch (random)
	{
	case 0:
	case 1:
		m_moveDirection = enum_Right;
		break;

	case 2:
		m_moveDirection = enum_Left;
		break;

	case 3:
		m_moveDirection = enum_Down;
		break;

	case 4:
		m_moveDirection = enum_Up;
		break;

	case 5:
		m_moveDirection = enum_UpRight;
		break;

	case 6:
		m_moveDirection = enum_DownRight;
		break;

	case 7:
		m_moveDirection = enum_DownLeft;
		break;

	case 8:
	case 9:
		m_moveDirection = enum_UpLeft;
		break;

	default:
		break;
	}
	

}

cRect::cRect(int x, int y, int r, int z)
{
	m_centerX = x;
	m_centerY = y;
	m_rSize = r;
	m_spin = 0;
	m_Shapes = 2;
	m_moveDirection = z;

	for (int i = 0; i < 4; i++)
	{
		rectPoint[i].x = long(m_centerX + m_rSize * sin((90 * i + 45) * M_PI / 180));
		rectPoint[i].y = long(m_centerY - m_rSize * cos((90 * i + 45) * M_PI / 180));
	}

	


}

cRect::~cRect()
{
}

void cRect::Draw(HDC hdc)
{
	Polygon(hdc, rectPoint, 4);
}

void cRect::Move()
{
	int i = 0;
	
	switch (m_moveDirection)
	{
	case enum_Right:
		m_centerX += m_moveX;

		for (i = 0; i < 4; i++) 
		{
			rectPoint[i].x = m_centerX - m_rSize;
			rectPoint[i].y = m_centerY - m_rSize;
			rectPoint[i].x = m_centerX + m_rSize;
			rectPoint[i].y = m_centerY + m_rSize;
		}
		break;

	case enum_Left:
		m_centerX -= m_moveX;

		for (i = 0; i < 4; i++)
		{
			rectPoint[i].x = m_centerX - m_rSize;
			rectPoint[i].y = m_centerY - m_rSize;
			rectPoint[i].x = m_centerX + m_rSize;
			rectPoint[i].y = m_centerY + m_rSize;
		}
		break;

	case enum_Down:
		m_centerY += m_moveY;

		for (i = 0; i < 4; i++)
		{
			rectPoint[i].x = m_centerX - m_rSize;
			rectPoint[i].y = m_centerY - m_rSize;
			rectPoint[i].x = m_centerX + m_rSize;
			rectPoint[i].y = m_centerY + m_rSize;
		}
		break;

	case enum_Up:
		m_centerY -= m_moveY;

		for (i = 0; i < 4; i++)
		{
			rectPoint[i].x = m_centerX - m_rSize;
			rectPoint[i].y = m_centerY - m_rSize;
			rectPoint[i].x = m_centerX + m_rSize;
			rectPoint[i].y = m_centerY + m_rSize;
		}
		break;

	case enum_UpRight:
		m_centerX += m_moveX;
		m_centerY -= m_moveY;

		for (i = 0; i < 4; i++)
		{
			rectPoint[i].x = m_centerX - m_rSize;
			rectPoint[i].y = m_centerY - m_rSize;
			rectPoint[i].x = m_centerX + m_rSize;
			rectPoint[i].y = m_centerY + m_rSize;
		}
		break;

	case enum_DownRight:
		m_centerX += m_moveX;
		m_centerY += m_moveY;

		for (i = 0; i < 4; i++)
		{
			rectPoint[i].x = m_centerX - m_rSize;
			rectPoint[i].y = m_centerY - m_rSize;
			rectPoint[i].x = m_centerX + m_rSize;
			rectPoint[i].y = m_centerY + m_rSize;
		}
		break;

	case enum_DownLeft:
		m_centerX -= m_moveX;
		m_centerY += m_moveY;

		for (i = 0; i < 4; i++)
		{
			rectPoint[i].x = m_centerX - m_rSize;
			rectPoint[i].y = m_centerY - m_rSize;
			rectPoint[i].x = m_centerX + m_rSize;
			rectPoint[i].y = m_centerY + m_rSize;
		}

		break;

	case enum_UpLeft:
		m_centerX -= m_moveX;
		m_centerY -= m_moveY;

		for (i = 0; i < 4; i++)
		{
			rectPoint[i].x = m_centerX - m_rSize;
			rectPoint[i].y = m_centerY - m_rSize;
			rectPoint[i].x = m_centerX + m_rSize;
			rectPoint[i].y = m_centerY + m_rSize;
		}
		break;



	default:
		break;
	}
	
}

void cRect::Spin()
{

	for (int i = 0; i < 4; i++)
	{
		rectPoint[i].x = long(m_centerX + m_rSize * sin((90 * i + 45 + m_spin) * M_PI / 180));
		rectPoint[i].y = long(m_centerY - m_rSize * cos((90 * i + 45 + m_spin) * M_PI / 180));
	}
	m_spin += 15;
	if (m_spin == 360)
	{
		m_spin = 0;
	}

}

int cRect::Collision(vector<cShape*> &shapeList, int n, RECT rt, int mode)
{
	int getCenterX = 0;
	int getCenterY = 0;
	long getR = 0;

	getCenterX = shapeList[n]->GetPointCenterX();
	getCenterY = shapeList[n]->GetPointCenterY();
	getR = shapeList[n]->GetPointR();

	if (getCenterX - getR <= rt.top)
	{
		switch (m_moveDirection)
		{

		case enum_Left:
			m_moveDirection = enum_Right;
			break;


		case enum_DownLeft:
			m_moveDirection = enum_DownRight;
			break;
		case enum_UpLeft:
			m_moveDirection = enum_UpRight;
			break;

		default:
			break;
		}
	}
	else if (getCenterY - getR <= rt.left)
	{
		switch (m_moveDirection)
		{
		case enum_Up:
			m_moveDirection = enum_Down;
			break;
		case enum_UpLeft:
			m_moveDirection = enum_DownLeft;
			break;
		case enum_UpRight:
			m_moveDirection = enum_DownRight;
			break;
		default:
			break;
		}
	}
	else if (getCenterX + getR >= rt.right)
	{
		switch (m_moveDirection)
		{
		case enum_Right:
			m_moveDirection = enum_Left;
			break;
		case enum_UpRight:
			m_moveDirection = enum_UpLeft;
			break;
		case enum_DownRight:
			m_moveDirection = enum_DownLeft;
			break;
		default:
			break;
		}
	}
	else if (getCenterY + getR >= rt.bottom)
	{
		switch (m_moveDirection)
		{
		case enum_Down:
			m_moveDirection = enum_Up;
			break;
		case enum_DownRight:
			m_moveDirection = enum_UpRight;
			break;
		case enum_DownLeft:
			m_moveDirection = enum_UpLeft;
		default:
			break;
		}

	}

	int getCenterX2 = 0;
	int getCenterY2 = 0;
	long getR2 = 0;
	long betwwen = 0;
	int i = 0;

	switch (mode)
	{
		//튕기기
	case 1:
		for (i = n + 1; i < shapeList.size(); i++)
		{

			getCenterX2 = shapeList[i]->GetPointCenterX();
			getCenterY2 = shapeList[i]->GetPointCenterY();
			getR2 = shapeList[i]->GetPointR();

			betwwen = long(sqrt(pow(getCenterX2 - getCenterX, 2) + pow(getCenterY2 - getCenterY, 2)));


			//두 도형의 충돌
			if (betwwen < getR + getR2)
			{

				if (shapeList[n]->GetMoveDirection() == shapeList[i]->GetMoveDirection())
				{
					shapeList[n]->SetMoveDirection(enum_Right);
					shapeList[i]->SetMoveDirection(enum_UpLeft);
				}


				//move 좌표 체인지
				int tempX;
				int tempY;
				tempX = shapeList[n]->GetMoveX();
				tempY = shapeList[n]->GetMoveY();
				shapeList[n]->SetMove(shapeList[i]->GetMoveX(), shapeList[i]->GetMoveY());
				shapeList[i]->SetMove(tempX, tempY);

				//방향 체인지
				int temp_enum;
				temp_enum = shapeList[n]->GetMoveDirection();
				shapeList[n]->SetMoveDirection(shapeList[i]->GetMoveDirection());
				shapeList[i]->SetMoveDirection(temp_enum);

			}

		}
		break;
		//충돌시 합치기
	case 2:
		for (i = n + 1; i < shapeList.size(); i++)
		{
			getCenterX2 = shapeList[i]->GetPointCenterX();
			getCenterY2 = shapeList[i]->GetPointCenterY();
			getR2 = shapeList[i]->GetPointR();

			betwwen = long(sqrt(pow(getCenterX2 - getCenterX, 2) + pow(getCenterY2 - getCenterY, 2)));


			//두 도형의 충돌
			if (betwwen < getR + getR2)
			{
				if (shapeList[n]->GetShapes() == shapeList[i]->GetShapes()) //서로 같은 도형이면 충돌로 판정하고 튕겨내기
				{
					if (shapeList[n]->GetMoveDirection() == shapeList[i]->GetMoveDirection())
					{
						shapeList[n]->SetMoveDirection(enum_Right);
						shapeList[i]->SetMoveDirection(enum_UpLeft);
					}


					//move 좌표 체인지
					int tempX;
					int tempY;
					tempX = shapeList[n]->GetMoveX();
					tempY = shapeList[n]->GetMoveY();
					shapeList[n]->SetMove(shapeList[i]->GetMoveX(), shapeList[i]->GetMoveY());
					shapeList[i]->SetMove(tempX, tempY);

					//방향 체인지
					int temp_enum;
					temp_enum = shapeList[n]->GetMoveDirection();
					shapeList[n]->SetMoveDirection(shapeList[i]->GetMoveDirection());
					shapeList[i]->SetMoveDirection(temp_enum);
				}

				else if (shapeList[i]->GetShapes() == 1) //상대가 원인 경우
				{
					shapeList[i]->SetR();
					delete(shapeList[n]);
					shapeList.erase(shapeList.begin() + n);
					return 1;
				}

				else if (shapeList[i]->GetShapes() == 3) // 상대가 별인 경우
				{
					shapeList[n]->SetR();
					delete(shapeList[i]);
					shapeList.erase(shapeList.begin() + i);
					return 1;
				}
			}
		}

		break;
	case 3:
		
		for (i = n + 1; i < shapeList.size(); i++)
		{
			getCenterX2 = shapeList[i]->GetPointCenterX();
			getCenterY2 = shapeList[i]->GetPointCenterY();
			getR2 = shapeList[i]->GetPointR();

			betwwen = long(sqrt(pow(getCenterX2 - getCenterX, 2) + pow(getCenterY2 - getCenterY, 2)));


			//두 도형의 충돌
			if (betwwen < getR + getR2)
			{
				if (shapeList[n]->GetShapes() == shapeList[i]->GetShapes()) //서로 같은 도형이면 충돌로 판정하고 튕겨내기
				{
					if (shapeList[n]->GetMoveDirection() == shapeList[i]->GetMoveDirection())
					{
						shapeList[n]->SetMoveDirection(enum_Right);
						shapeList[i]->SetMoveDirection(enum_UpLeft);
					}


					//move 좌표 체인지
					int tempX;
					int tempY;
					tempX = shapeList[n]->GetMoveX();
					tempY = shapeList[n]->GetMoveY();
					shapeList[n]->SetMove(shapeList[i]->GetMoveX(), shapeList[i]->GetMoveY());
					shapeList[i]->SetMove(tempX, tempY);

					//방향 체인지
					int temp_enum;
					temp_enum = shapeList[n]->GetMoveDirection();
					shapeList[n]->SetMoveDirection(shapeList[i]->GetMoveDirection());
					shapeList[i]->SetMoveDirection(temp_enum);
				}

				else if (shapeList[i]->GetShapes() == 3)//별이면
				{
					//지워질 도형의 좌표
					int ix = shapeList[i]->GetPointCenterX();
					int iy = shapeList[i]->GetPointCenterY();
					long ir = shapeList[i]->GetPointR();
					int iMoveDirect = shapeList[i]->GetMoveDirection();

					//long plus = ir * 2;


					if (ir > 10)//자신은 사각형
					{
						if (shapeList[n]->GetMoveDirection() == enum_Right) //다가온 사각형의 방향
						{
							shapeList[n]->SetMoveDirection(enum_Left);
							cStar* newcStar1 = new cStar(ix + ir, iy - ir, ir - 10, enum_UpRight);
							shapeList.push_back(newcStar1);

							cStar* newcStar2 = new cStar(ix + ir, iy + ir, ir - 10, enum_DownRight);
							shapeList.push_back(newcStar2);
						}

						else if (shapeList[n]->GetMoveDirection() == enum_Left)
						{
							shapeList[n]->SetMoveDirection(enum_Right);
							cStar* newcStar1 = new cStar(ix - ir, iy - ir, ir - 10, enum_UpLeft);
							shapeList.push_back(newcStar1);

							cStar* newcStar2 = new cStar(ix - ir, iy + ir, ir - 10, enum_DownLeft);
							shapeList.push_back(newcStar2);
						}

						else if (shapeList[n]->GetMoveDirection() == enum_Down)
						{
							shapeList[n]->SetMoveDirection(enum_Up);
							cStar* newcStar1 = new cStar(ix + ir, iy + ir, ir - 10, enum_DownRight);
							shapeList.push_back(newcStar1);

							cStar* newcStar2 = new cStar(ix - ir, iy + ir, ir - 10, enum_DownLeft);
							shapeList.push_back(newcStar2);
						}

						else if (shapeList[n]->GetMoveDirection() == enum_Up)
						{
							shapeList[n]->SetMoveDirection(enum_Down);
							cStar* newcStar1 = new cStar(ix + ir, iy - ir, ir - 10, enum_UpRight);
							shapeList.push_back(newcStar1);

							cStar* newcStar2 = new cStar(ix - ir, iy - ir, ir - 10, enum_UpLeft);
							shapeList.push_back(newcStar2);
						}

						else if (shapeList[n]->GetMoveDirection() == enum_UpRight)
						{
							shapeList[n]->SetMoveDirection(enum_DownRight);
							cStar* newcStar1 = new cStar(ix - ir, iy - ir, ir - 10, enum_Up);
							shapeList.push_back(newcStar1);

							cStar* newcStar2 = new cStar(ix + ir, iy - ir, ir - 10, enum_UpRight);
							shapeList.push_back(newcStar2);
						}

						else if (shapeList[n]->GetMoveDirection() == enum_DownRight)
						{
							shapeList[n]->SetMoveDirection(enum_UpRight);
							cStar* newcStar1 = new cStar(ix + ir, iy + ir, ir - 10, enum_DownRight);
							shapeList.push_back(newcStar1);

							cStar* newcStar2 = new cStar(ix - ir, iy + ir, ir - 10, enum_Down);
							shapeList.push_back(newcStar2);
						}

						else if (shapeList[n]->GetMoveDirection() == enum_DownLeft)
						{
							shapeList[n]->SetMoveDirection(enum_UpLeft);
							cStar* newcStar1 = new cStar(ix - ir, iy + ir, ir - 10, enum_DownLeft);
							shapeList.push_back(newcStar1);

							cStar* newcStar2 = new cStar(ix + ir, iy + ir, ir - 10, enum_Down);
							shapeList.push_back(newcStar2);
						}

						else if (shapeList[n]->GetMoveDirection() == enum_UpLeft)
						{
							shapeList[n]->SetMoveDirection(enum_DownLeft);
							cStar* newcStar1 = new cStar(ix - ir, iy - ir, ir - 10, enum_UpLeft);
							shapeList.push_back(newcStar1);

							cStar* newcStar2 = new cStar(ix + ir, iy - ir, ir - 10, enum_Up);
							shapeList.push_back(newcStar2);
						}

					}
					delete(shapeList[i]);
					shapeList.erase(shapeList.begin() + i);

					return 1;


				}

				else if (shapeList[i]->GetShapes() == 1)  //원인 경우
				{

					//사각형 n이 쪼개지고 원 i가 튕겨야함
					int nx = shapeList[n]->GetPointCenterX();
					int ny = shapeList[n]->GetPointCenterY();
					long nr = shapeList[n]->GetPointR();
					int nMoveDirect = shapeList[n]->GetMoveDirection();

					if (nr > 10)
					{


						if (shapeList[i]->GetMoveDirection() == enum_Right)
						{
							shapeList[i]->SetMoveDirection(enum_Left);
							cRect* newRect1 = new cRect(nx + nr, ny - nr, nr - 10, enum_UpRight);
							shapeList.push_back(newRect1);

							cRect* newRect2 = new cRect(nx + nr, ny + nr, nr - 10, enum_DownRight);
							shapeList.push_back(newRect2);
						}
						else if (shapeList[i]->GetMoveDirection() == enum_Left)
						{
							shapeList[i]->SetMoveDirection(enum_Right);
							cRect* newRect1 = new cRect(nx - nr, ny - nr, nr - 10, enum_UpLeft);
							shapeList.push_back(newRect1);

							cRect* newRect2 = new cRect(nx - nr, ny + nr, nr - 10, enum_DownLeft);
							shapeList.push_back(newRect2);
						}
						else if (shapeList[i]->GetMoveDirection() == enum_Down)
						{
							shapeList[i]->SetMoveDirection(enum_Up);
							cRect* newRect1 = new cRect(nx + nr, ny + nr, nr - 10, enum_DownRight);
							shapeList.push_back(newRect1);

							cRect* newRect2 = new cRect(nx - nr, ny + nr, nr - 10, enum_DownLeft);
							shapeList.push_back(newRect2);
						}
						else if (shapeList[i]->GetMoveDirection() == enum_Up)
						{
							shapeList[i]->SetMoveDirection(enum_Down);
							cRect* newRect1 = new cRect(nx + nr, ny - nr, nr - 10, enum_UpRight);
							shapeList.push_back(newRect1);

							cRect* newRect2 = new cRect(nx - nr, ny - nr, nr - 10, enum_UpLeft);
							shapeList.push_back(newRect2);
						}
						else if (shapeList[i]->GetMoveDirection() == enum_UpRight)
						{
							shapeList[i]->SetMoveDirection(enum_DownRight);
							cRect* newRect1 = new cRect(nx - nr, ny - nr, nr - 10, enum_Up);
							shapeList.push_back(newRect1);

							cRect* newRect2 = new cRect(nx + nr, ny - nr, nr - 10, enum_UpRight);
							shapeList.push_back(newRect2);
						}
						else if (shapeList[i]->GetMoveDirection() == enum_DownRight)
						{
							shapeList[i]->SetMoveDirection(enum_UpRight);
							cRect* newRect1 = new cRect(nx + nr, ny + nr, nr - 10, enum_DownRight);
							shapeList.push_back(newRect1);

							cRect* newRect2 = new cRect(nx - nr, ny + nr, nr - 10, enum_Down);
							shapeList.push_back(newRect2);
						}
						else if (shapeList[i]->GetMoveDirection() == enum_DownLeft)
						{
							shapeList[i]->SetMoveDirection(enum_UpLeft);
							cRect* newRect1 = new cRect(nx - nr, ny + nr, nr - 10, enum_DownLeft);
							shapeList.push_back(newRect1);

							cRect* newRect2 = new cRect(nx + nr, ny + nr, nr - 10, enum_Down);
							shapeList.push_back(newRect2);
						}
						else if (shapeList[i]->GetMoveDirection() == enum_UpLeft)
						{
							shapeList[i]->SetMoveDirection(enum_DownLeft);
							cRect* newRect1 = new cRect(nx - nr, ny + nr, nr - 10, enum_UpLeft);
							shapeList.push_back(newRect1);

							cRect* newRect2 = new cRect(nx + nr, ny + nr, nr - 10, enum_Up);
							shapeList.push_back(newRect2);
						}

						delete(shapeList[n]);
						shapeList.erase(shapeList.begin() + n);

					}//(nr>10)
					return 1;

				}//(shapeList[i]->GetShapes() == 3)

			}
		}
		

		break;

	default:
		break;
	}
	return 0;
}

int cRect::GetPointCenterX()
{
	return m_centerX;
}

int cRect::GetPointCenterY()
{
	return m_centerY;
}

long cRect::GetPointR()
{
	return m_rSize;
}

int cRect::GetMoveDirection()
{
	return m_moveDirection;
}

void cRect::SetMoveDirection(int enum_num)
{
	m_moveDirection = enum_num;
}

int cRect::GetMoveX()
{
	return m_moveX;
}

int cRect::GetMoveY()
{
	return m_moveY;
}

void cRect::SetMove(int enum_numX, int enum_numY)
{
	m_moveX = enum_numX;
	m_moveY = enum_numY;
}

int cRect::GetShapes()
{
	return m_Shapes;
}

void cRect::SetR()
{
	m_rSize += 10;
}


cStar::cStar()
{
}

cStar::cStar(int x, int y, int r)
{
	m_centerX = x;
	m_centerY = y;
	m_rSize = r;
	int i = 0;
	m_Shapes = 3;

	srand((unsigned int)time(NULL));
	int random = rand() %10;

	switch (random)
	{
	case 0:
	case 1:
		m_moveDirection = enum_Right;
		break;

	case 2:
		m_moveDirection = enum_Left;
		break;

	case 3:
		m_moveDirection = enum_Down;
		break;

	case 4:
		m_moveDirection = enum_Up;
		break;

	case 5:
		m_moveDirection = enum_UpRight;
		break;

	case 6:
		m_moveDirection = enum_DownRight;
		break;

	case 7:
		m_moveDirection = enum_DownLeft;
		break;

	case 8:
	case 9:
		m_moveDirection = enum_UpLeft;
		break;

	default:
		break;
	}



	for (i = 0; i <5; i++) 
	{

		point[2 * i].x = long(m_centerX + m_rSize * sin((72 * i) * M_PI / 180));
		point[2 * i].y = long(m_centerY - m_rSize * cos((72 * i) * M_PI / 180));
	}
	a = point[4].y - point[0].y;
	b = point[0].x - point[4].x;
	c = point[2].y - point[8].y;
	d = point[8].x - point[2].x;
	e = a*point[0].x + b*point[0].y;
	f = c*point[2].x + d*point[2].y;

	k = a*d - b * c;

	s_x = (e*d - b*f) / k;
	s_y = (a*f - e*c) / k;

	s_r2 = long(sqrt(pow(s_x - m_centerX, 2) + pow(s_y - m_centerY, 2)));

	for (i = 0; i < 5; i++) 
	{
		point[2 * i + 1].x = long(m_centerX + s_r2 * sin((72 * i + 32) * M_PI / 180));
		point[2 * i + 1].y = long(m_centerY - s_r2 * cos((72 * i + 32) * M_PI / 180));
	}

}

cStar::cStar(int x, int y, int r, int z)
{
	m_centerX = x;
	m_centerY = y;
	m_rSize = r ;
	int i = 0;
	m_Shapes = 3;
	m_moveDirection = z;


	for (i = 0; i <5; i++)
	{

		point[2 * i].x = long(m_centerX + m_rSize * sin((72 * i) * M_PI / 180));
		point[2 * i].y = long(m_centerY - m_rSize * cos((72 * i) * M_PI / 180));
	}
	a = point[4].y - point[0].y;
	b = point[0].x - point[4].x;
	c = point[2].y - point[8].y;
	d = point[8].x - point[2].x;
	e = a*point[0].x + b*point[0].y;
	f = c*point[2].x + d*point[2].y;

	k = a*d - b * c;

	s_x = (e*d - b*f) / k;
	s_y = (a*f - e*c) / k;

	s_r2 = long(sqrt(pow(s_x - m_centerX, 2) + pow(s_y - m_centerY, 2)));

	for (i = 0; i < 5; i++)
	{
		point[2 * i + 1].x = long(m_centerX + s_r2 * sin((72 * i + 32) * M_PI / 180));
		point[2 * i + 1].y = long(m_centerY - s_r2 * cos((72 * i + 32) * M_PI / 180));
	}


}

cStar::~cStar()
{
}

void cStar::Draw(HDC hdc)
{
	Polygon(hdc, point, 10);
}

void cStar::Move()
{
	
	switch (m_moveDirection)
	{
	case enum_Right:
		m_centerX += m_moveX;
		break;

	case enum_Left:
		m_centerX -= m_moveX;
		break;

	case enum_Down:
		m_centerY += m_moveY;
		break;

	case enum_Up:
		m_centerY -= m_moveY;
		break;

	case enum_UpRight:
		m_centerX += m_moveX;
		m_centerY -= m_moveY;
		break;

	case enum_DownRight:
		m_centerX += m_moveX;
		m_centerY += m_moveY;
		break;

	case enum_DownLeft:
		m_centerX -= m_moveX;
		m_centerY += m_moveY;
		break;

	case enum_UpLeft:
		m_centerX -= m_moveX;
		m_centerY -= m_moveY;
		break;

	default:
		break;
	}
	star();

	

}

void cStar::star()
{
	int i = 0;
	for (i = 0; i <5; i++)
	{

		point[2 * i].x = long(m_centerX + m_rSize * sin((72 * i) * M_PI / 180));
		point[2 * i].y = long(m_centerY - m_rSize * cos((72 * i) * M_PI / 180));
	}
	
	a = point[4].y - point[0].y;
	b = point[0].x - point[4].x;
	c = point[2].y - point[8].y;
	d = point[8].x - point[2].x;
	e = a*point[0].x + b*point[0].y;
	f = c*point[2].x + d*point[2].y;
	
	k = a*d - b * c;

	s_x = (e*d - b*f) / k;
	s_y = (a*f - e*c) / k;

	s_r2 = long(sqrt(pow(s_x - m_centerX, 2) + pow(s_y - m_centerY, 2)));

	for (i = 0; i < 5; i++)
	{
		point[2 * i + 1].x = long(m_centerX + s_r2 * sin((72 * i + 32) * M_PI / 180));
		point[2 * i + 1].y = long(m_centerY - s_r2 * cos((72 * i + 32) * M_PI / 180));
	}
}

void cStar::Spin()
{
	int i = 0;
	for (i = 0; i <5; i++) 
	{
		point[2 * i].x = long(m_centerX + m_rSize * sin((72 * i + m_spin) * M_PI / 180));
		point[2 * i].y = long(m_centerY - m_rSize * cos((72 * i + m_spin) * M_PI / 180));
	}

	
	a = point[4].y - point[0].y;
	b = point[0].x - point[4].x;
	c = point[2].y - point[8].y;
	d = point[8].x - point[2].x;
	e = a*point[0].x + b*point[0].y;
	f = c*point[2].x + d*point[2].y;


	k = a*d - b * c;

	s_x = (e*d - b*f) / k;
	s_y = (a*f - e*c) / k;



	s_r2 = long(sqrt(pow(s_x - m_centerX, 2) + pow(s_y - m_centerY, 2)));



	for (i = 0; i < 5; i++) 
	{
		point[2 * i + 1].x = long(m_centerX + s_r2 * sin((72 * i + 32 + m_spin) * M_PI / 180));
		point[2 * i + 1].y = long(m_centerY - s_r2 * cos((72 * i + 32 + m_spin) * M_PI / 180));
	}
	
	m_spin += 15;

	if (m_spin == 360) 
	{
		m_spin = 0;
	}
	
}

int cStar::Collision(vector<cShape*> &shapeList, int n, RECT rt, int mode)
{
	int getCenterX = 0;
	int getCenterY = 0;
	long getR = 0;

	getCenterX = shapeList[n]->GetPointCenterX();
	getCenterY = shapeList[n]->GetPointCenterY();
	getR = shapeList[n]->GetPointR();

	if (getCenterX - getR <= rt.top)
	{
		switch (m_moveDirection)
		{

		case enum_Left:
			m_moveDirection = enum_Right;
			break;


		case enum_DownLeft:
			m_moveDirection = enum_DownRight;
			break;
		case enum_UpLeft:
			m_moveDirection = enum_UpRight;
			break;

		default:
			break;
		}
	}
	else if (getCenterY - getR <= rt.left)
	{
		switch (m_moveDirection)
		{
		case enum_Up:
			m_moveDirection = enum_Down;
			break;
		case enum_UpLeft:
			m_moveDirection = enum_DownLeft;
			break;
		case enum_UpRight:
			m_moveDirection = enum_DownRight;
			break;
		default:
			break;
		}
	}
	else if (getCenterX + getR >= rt.right)
	{
		switch (m_moveDirection)
		{
		case enum_Right:
			m_moveDirection = enum_Left;
			break;
		case enum_UpRight:
			m_moveDirection = enum_UpLeft;
			break;
		case enum_DownRight:
			m_moveDirection = enum_DownLeft;
			break;
		default:
			break;
		}
	}
	else if (getCenterY + getR >= rt.bottom)
	{
		switch (m_moveDirection)
		{
		case enum_Down:
			m_moveDirection = enum_Up;
			break;
		case enum_DownRight:
			m_moveDirection = enum_UpRight;
			break;
		case enum_DownLeft:
			m_moveDirection = enum_UpLeft;
		default:
			break;
		}

	}

	int getCenterX2 = 0;
	int getCenterY2 = 0;
	long getR2 = 0;
	long betwwen = 0;
	int i = 0;

	switch (mode)
	{
		//튕기기
	case 1:
		for (i = n + 1; i < shapeList.size(); i++)
		{

			getCenterX2 = shapeList[i]->GetPointCenterX();
			getCenterY2 = shapeList[i]->GetPointCenterY();
			getR2 = shapeList[i]->GetPointR();

			betwwen = long(sqrt(pow(getCenterX2 - getCenterX, 2) + pow(getCenterY2 - getCenterY, 2)));


			//두 도형의 충돌
			if (betwwen < getR + getR2)
			{

				if (shapeList[n]->GetMoveDirection() == shapeList[i]->GetMoveDirection())
				{
					shapeList[n]->SetMoveDirection(enum_Right);
					shapeList[i]->SetMoveDirection(enum_UpLeft);
				}


				//move 좌표 체인지
				int tempX;
				int tempY;
				tempX = shapeList[n]->GetMoveX();
				tempY = shapeList[n]->GetMoveY();
				shapeList[n]->SetMove(shapeList[i]->GetMoveX(), shapeList[i]->GetMoveY());
				shapeList[i]->SetMove(tempX, tempY);

				//방향 체인지
				int temp_enum;
				temp_enum = shapeList[n]->GetMoveDirection();
				shapeList[n]->SetMoveDirection(shapeList[i]->GetMoveDirection());
				shapeList[i]->SetMoveDirection(temp_enum);

			}

		}
		break;
		//충돌시 합치기
	case 2:
		for (i = n + 1; i < shapeList.size(); i++)
		{
			getCenterX2 = shapeList[i]->GetPointCenterX();
			getCenterY2 = shapeList[i]->GetPointCenterY();
			getR2 = shapeList[i]->GetPointR();

			betwwen = long(sqrt(pow(getCenterX2 - getCenterX, 2) + pow(getCenterY2 - getCenterY, 2)));


			//두 도형의 충돌
			if (betwwen < getR + getR2)
			{
				if (shapeList[n]->GetShapes() == shapeList[i]->GetShapes()) //서로 같은 도형이면 충돌로 판정하고 튕겨내기
				{
					if (shapeList[n]->GetMoveDirection() == shapeList[i]->GetMoveDirection())
					{
						shapeList[n]->SetMoveDirection(enum_Right);
						shapeList[i]->SetMoveDirection(enum_UpLeft);
					}


					//move 좌표 체인지
					int tempX;
					int tempY;
					tempX = shapeList[n]->GetMoveX();
					tempY = shapeList[n]->GetMoveY();
					shapeList[n]->SetMove(shapeList[i]->GetMoveX(), shapeList[i]->GetMoveY());
					shapeList[i]->SetMove(tempX, tempY);

					//방향 체인지
					int temp_enum;
					temp_enum = shapeList[n]->GetMoveDirection();
					shapeList[n]->SetMoveDirection(shapeList[i]->GetMoveDirection());
					shapeList[i]->SetMoveDirection(temp_enum);
				}

				else if (shapeList[i]->GetShapes() == 1)//원이면
				{


					shapeList[n]->SetR();
					delete(shapeList[i]);
					shapeList.erase(shapeList.begin() + i);
					return 1;



				}

				else if (shapeList[i]->GetShapes() == 2)  //사각형인 경우
				{

					shapeList[i]->SetR();
					delete(shapeList[n]);
					shapeList.erase(shapeList.begin() + n);
					return 1;

				}

			}
		}

		break;
	case 3:
		for (i = n + 1; i < shapeList.size(); i++)
		{
			getCenterX2 = shapeList[i]->GetPointCenterX();
			getCenterY2 = shapeList[i]->GetPointCenterY();
			getR2 = shapeList[i]->GetPointR();

			betwwen = long(sqrt(pow(getCenterX2 - getCenterX, 2) + pow(getCenterY2 - getCenterY, 2)));


			//두 도형의 충돌
			if (betwwen < getR + getR2)
			{
				if (shapeList[n]->GetShapes() == shapeList[i]->GetShapes()) //서로 같은 도형이면 충돌로 판정하고 튕겨내기
				{
					if (shapeList[n]->GetMoveDirection() == shapeList[i]->GetMoveDirection())
					{
						shapeList[n]->SetMoveDirection(enum_Right);
						shapeList[i]->SetMoveDirection(enum_UpLeft);
					}


					//move 좌표 체인지
					int tempX;
					int tempY;
					tempX = shapeList[n]->GetMoveX();
					tempY = shapeList[n]->GetMoveY();
					shapeList[n]->SetMove(shapeList[i]->GetMoveX(), shapeList[i]->GetMoveY());
					shapeList[i]->SetMove(tempX, tempY);

					//방향 체인지
					int temp_enum;
					temp_enum = shapeList[n]->GetMoveDirection();
					shapeList[n]->SetMoveDirection(shapeList[i]->GetMoveDirection());
					shapeList[i]->SetMoveDirection(temp_enum);
				}

				else if (shapeList[i]->GetShapes() == 1)//상대가 원 일경우
				{
					//지워질 도형의 좌표
					int ix = shapeList[i]->GetPointCenterX();
					int iy = shapeList[i]->GetPointCenterY();
					long ir = shapeList[i]->GetPointR();
					int iMoveDirect = shapeList[i]->GetMoveDirection();
					
					if (ir >10)
					{
						if (shapeList[n]->GetMoveDirection() == enum_Right) //다가온 별의 방향
						{
							shapeList[n]->SetMoveDirection(enum_Left);
							cCircle* newcCircle1 = new cCircle(ix + ir, iy - ir, ir - 10, enum_UpRight);
							shapeList.push_back(newcCircle1);

							cCircle* newcCircle2 = new cCircle(ix + ir, iy + ir, ir - 10, enum_DownRight);
							shapeList.push_back(newcCircle2);
						}

						else if (shapeList[n]->GetMoveDirection() == enum_Left)
						{
							shapeList[n]->SetMoveDirection(enum_Right);
							cCircle* newcCircle1 = new cCircle(ix - ir, iy - ir, ir - 10, enum_UpLeft);
							shapeList.push_back(newcCircle1);

							cCircle* newcCircle2 = new cCircle(ix - ir, iy + ir, ir - 10, enum_DownLeft);
							shapeList.push_back(newcCircle2);
						}

						else if (shapeList[n]->GetMoveDirection() == enum_Down)
						{
							shapeList[n]->SetMoveDirection(enum_Up);
							cCircle* newcCircle1 = new cCircle(ix + ir, iy + ir, ir - 10, enum_DownRight);
							shapeList.push_back(newcCircle1);

							cCircle* newcCircle2 = new cCircle(ix - ir, iy + ir, ir - 10, enum_DownLeft);
							shapeList.push_back(newcCircle2);
						}

						else if (shapeList[n]->GetMoveDirection() == enum_Up)
						{
							shapeList[n]->SetMoveDirection(enum_Down);
							cCircle* newcCircle1 = new cCircle(ix + ir, iy - ir, ir - 10, enum_UpRight);
							shapeList.push_back(newcCircle1);

							cCircle* newcCircle2 = new cCircle(ix - ir, iy - ir, ir - 10, enum_UpLeft);
							shapeList.push_back(newcCircle2);
						}

						else if (shapeList[n]->GetMoveDirection() == enum_UpRight)
						{
							shapeList[n]->SetMoveDirection(enum_DownRight);
							cCircle* newcCircle1 = new cCircle(ix - ir, iy - ir, ir - 10, enum_Up);
							shapeList.push_back(newcCircle1);

							cCircle* newcCircle2 = new cCircle(ix + ir, iy - ir, ir - 10, enum_UpRight);
							shapeList.push_back(newcCircle2);
						}

						else if (shapeList[n]->GetMoveDirection() == enum_DownRight)
						{
							shapeList[n]->SetMoveDirection(enum_UpRight);
							cCircle* newcCircle1 = new cCircle(ix + ir, iy + ir, ir - 10, enum_DownRight);
							shapeList.push_back(newcCircle1);

							cCircle* newcCircle2 = new cCircle(ix - ir, iy + ir, ir - 10, enum_Down);
							shapeList.push_back(newcCircle2);
						}

						else if (shapeList[n]->GetMoveDirection() == enum_DownLeft)
						{
							shapeList[n]->SetMoveDirection(enum_UpLeft);
							cCircle* newcCircle1 = new cCircle(ix - ir, iy + ir, ir - 10, enum_DownLeft);
							shapeList.push_back(newcCircle1);

							cCircle* newcCircle2 = new cCircle(ix + ir, iy + ir, ir - 10, enum_Down);
							shapeList.push_back(newcCircle2);
						}

						else if (shapeList[n]->GetMoveDirection() == enum_UpLeft)
						{
							shapeList[n]->SetMoveDirection(enum_DownLeft);
							cCircle* newcCircle1 = new cCircle(ix - ir, iy - ir, ir - 10, enum_UpLeft);
							shapeList.push_back(newcCircle1);

							cCircle* newcCircle2 = new cCircle(ix + ir, iy - ir, ir - 10, enum_Up);
							shapeList.push_back(newcCircle2);
						}

					}
					delete(shapeList[i]);
					shapeList.erase(shapeList.begin() + i);

					return 1;


				}

				else if (shapeList[i]->GetShapes() == 2)  //사각인 경우
				{

					//원 n 이 쪼개지고 별 i 는 튕기기
					int nx = shapeList[n]->GetPointCenterX();
					int ny = shapeList[n]->GetPointCenterY();
					long nr = shapeList[n]->GetPointR();
					int nMoveDirect = shapeList[n]->GetMoveDirection();


					if (nr > 10)
					{


						if (shapeList[i]->GetMoveDirection() == enum_Right)
						{
							shapeList[i]->SetMoveDirection(enum_Left);
							cRect* newcRect1 = new cRect(nx + nr, ny - nr, nr - 10, enum_UpRight);
							shapeList.push_back(newcRect1);

							cRect* newcRect2 = new cRect(nx + nr, ny + nr, nr - 10, enum_DownRight);
							shapeList.push_back(newcRect2);
						}
						else if (shapeList[i]->GetMoveDirection() == enum_Left)
						{
							shapeList[i]->SetMoveDirection(enum_Right);
							cRect* newcRect1 = new cRect(nx - nr, ny - nr, nr - 10, enum_UpLeft);
							shapeList.push_back(newcRect1);

							cRect* newcRect2 = new cRect(nx - nr, ny + nr, nr - 10, enum_DownLeft);
							shapeList.push_back(newcRect2);
						}
						else if (shapeList[i]->GetMoveDirection() == enum_Down)
						{
							shapeList[i]->SetMoveDirection(enum_Up);
							cRect* newcRect1 = new cRect(nx + nr, ny + nr, nr - 10, enum_DownRight);
							shapeList.push_back(newcRect1);

							cRect* newcRect2 = new cRect(nx - nr, ny + nr, nr - 10, enum_DownLeft);
							shapeList.push_back(newcRect2);
						}
						else if (shapeList[i]->GetMoveDirection() == enum_Up)
						{
							shapeList[i]->SetMoveDirection(enum_Down);
							cRect* newcRect1 = new cRect(nx + nr, ny - nr, nr - 10, enum_UpRight);
							shapeList.push_back(newcRect1);

							cRect* newcRect2 = new cRect(nx - nr, ny - nr, nr - 10, enum_UpLeft);
							shapeList.push_back(newcRect2);
						}
						else if (shapeList[i]->GetMoveDirection() == enum_UpRight)
						{
							shapeList[i]->SetMoveDirection(enum_DownRight);
							cRect* newcRect1 = new cRect(nx - nr, ny - nr, nr - 10, enum_Up);
							shapeList.push_back(newcRect1);

							cRect* newcRect2 = new cRect(nx + nr, ny - nr, nr - 10, enum_UpRight);
							shapeList.push_back(newcRect2);
						}
						else if (shapeList[i]->GetMoveDirection() == enum_DownRight)
						{
							shapeList[i]->SetMoveDirection(enum_UpRight);
							cRect* newcRect1 = new cRect(nx + nr, ny + nr, nr - 10, enum_DownRight);
							shapeList.push_back(newcRect1);

							cRect* newcRect2 = new cRect(nx - nr, ny + nr, nr - 10, enum_Down);
							shapeList.push_back(newcRect2);
						}
						else if (shapeList[i]->GetMoveDirection() == enum_DownLeft)
						{
							shapeList[i]->SetMoveDirection(enum_UpLeft);
							cRect* newcRect1 = new cRect(nx - nr, ny + nr, nr - 10, enum_DownLeft);
							shapeList.push_back(newcRect1);

							cRect* newcRect2 = new cRect(nx + nr, ny + nr, nr - 10, enum_Down);
							shapeList.push_back(newcRect2);
						}
						else if (shapeList[i]->GetMoveDirection() == enum_UpLeft)
						{
							shapeList[i]->SetMoveDirection(enum_DownLeft);
							cRect* newcRect1 = new cRect(nx - nr, ny + nr, nr - 10, enum_UpLeft);
							shapeList.push_back(newcRect1);

							cRect* newcRect2 = new cRect(nx + nr, ny + nr, nr - 10, enum_Up);
							shapeList.push_back(newcRect2);
						}

					}//(nr>10)

					delete(shapeList[n]);
					shapeList.erase(shapeList.begin() + n);
					return 1;

				}//(shapeList[i]->GetShapes() == 3)

			}// 충돌 체크 if(ir >10) 

		}//for문



		break;
	default:
		break;
	}
	return 0;
}

int cStar::GetPointCenterX()
{
	return m_centerX;
}

int cStar::GetPointCenterY()
{
	return m_centerY;
}

long cStar::GetPointR()
{
	return m_rSize;
}

int cStar::GetMoveDirection()
{
	return m_moveDirection;
}

void cStar::SetMoveDirection(int enum_num)
{
	m_moveDirection = enum_num;
}

int cStar::GetMoveX()
{
	return m_moveX;
}

int cStar::GetMoveY()
{
	return m_moveY;
}

void cStar::SetMove(int enum_numX, int enum_numY)
{
	m_moveX = enum_numX;
	m_moveY = enum_numY;
}

int cStar::GetShapes()
{
	return m_Shapes;
}

void cStar::SetR()
{
	m_rSize += 10;
}


