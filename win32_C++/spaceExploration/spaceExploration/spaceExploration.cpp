// spaceExploration.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>

using namespace std;





int main()
{
	int block = 9999999999999999999;
	int map[7][8] = 
	{
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
		NULL, block, block, block, NULL, block, block, NULL,
		NULL, NULL, NULL, NULL, NULL, block, block, NULL,
		NULL, NULL, NULL, block, NULL, block, block, NULL,
		NULL, NULL, NULL, block, NULL, NULL, NULL, NULL,
		NULL, NULL, NULL, block, NULL, NULL, NULL, NULL,
		NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
	
	};

	int inputX = 0;
	int inputY = 0;
	int count = 0;
	int x = 0;
	int y = 0;
	

	cout << "���� ���� ��ǥ�� �Է� ���ּ���" << endl;
	cout << "x: ";
	cin >> inputX;

	cout << "y: ";
	cin >> inputY;
	cout << endl;

	//��� ���� ��ǥ
	x = 3;
	y = 1;

	map[x][y] = count++;
	
	//search();


	//���� �˻�
	if (y > 0)
	{
		
		//�̵��� ������ ���� �� Ŭ���  -> �̵��ϰ� �� ����
		if (map[x][y] < map[x][y-1]) //
		{
			if (map[x][y] == NULL || map[x][y] > count)
			{
				map[x][y] = count++;

				//search();
			}
		}
		else 
		{
			//���� �˻�

		}
		
		
		
	}
	else//���� �˻� �Ұ��ɽ�
	{
		//y�� �� ���� ����̴�
		//���� �˻� ����
		if (x < 7) 
		{
			x++;
			if (map[x][y] == NULL || map[x][y] > count)
			{
				map[x][y] = count++;
				//search();
			}

		}
		else//���� �˻� �Ұ��ɽ�
		{
			//���� �˻�
			if (y <6) 
			{
				y++;
				if (map[x][y] == NULL || map[x][y] > count) 
				{
					map[x][y] = count++;
					//search();
				}

			}
			else //���� �˻� �Ұ��� ��
			{
			
			}
		}

	}

	
	


    return 0;
}

