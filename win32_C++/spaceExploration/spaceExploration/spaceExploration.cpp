// spaceExploration.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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
	

	cout << "도착 지점 좌표를 입력 해주세요" << endl;
	cout << "x: ";
	cin >> inputX;

	cout << "y: ";
	cin >> inputY;
	cout << endl;

	//출발 지점 좌표
	x = 3;
	y = 1;

	map[x][y] = count++;
	
	//search();


	//상측 검색
	if (y > 0)
	{
		
		//이동할 지점의 값이 더 클경우  -> 이동하고 값 수정
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
			//우측 검색

		}
		
		
		
	}
	else//상측 검색 불가능시
	{
		//y가 맨 위인 경우이다
		//우측 검색 실행
		if (x < 7) 
		{
			x++;
			if (map[x][y] == NULL || map[x][y] > count)
			{
				map[x][y] = count++;
				//search();
			}

		}
		else//우측 검색 불가능시
		{
			//하측 검색
			if (y <6) 
			{
				y++;
				if (map[x][y] == NULL || map[x][y] > count) 
				{
					map[x][y] = count++;
					//search();
				}

			}
			else //하측 검색 불가능 시
			{
			
			}
		}

	}

	
	


    return 0;
}

