#pragma once


class AStar
{
protected:
	int as_centerX, as_centerY, as_r;
	int as_g;
	int as_h;
	int as_f;
	int as_state; //���̳� ����̳ĸ� ��Ÿ���� ���� 0 = �� 1 = ��

	int *left_top;
	int *top;
	int *right_top;
	int *right;
	int *right_bottom;
	int *bottom;
	int *left_bottom;
	int *left;

public:
	AStar();
	AStar(int x,int y);
	~AStar();

	void DrawAMap(HDC hdc);
	void ChangeState();
	int GetState();
	int GetCenterX();
	int GetCenterY();

};