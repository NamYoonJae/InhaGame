#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
	총 무게 10까지 담을 수 있는 인벤토리가 있다.
	아이템마다 중요도가 있고 무게가 다르다.
	중요도가 제일 높게 다음의 무기를 담을 수 있도록 프로그램을 작성하라.

	이름			중요도		무게
	kar98k		7			4
	후라이팬		10			2
	스코프		7			4
	뚝배기		6			6
	라이플		2			10
	지도			3			5

	출력 >	중요도 순으로 출력 할 수 있도록 할 것
			중요도 1순위 : 24
			kar98k		7	4
			후라이팬		10	2
			스코프		7	4


*/
struct weponList 
{
	char name[32];
	int importance;
	int weight;
};


void main(void) {

	struct weponList wepon[6] = { "", 0, 0};
	int i = 0;
	int j = 0;
	int impSum = 0;
	strcpy(wepon[0].name, "kar98k");
	strcpy(wepon[1].name, "후라이팬");
	strcpy(wepon[2].name, "스코프");
	strcpy(wepon[3].name, "뚝배기");
	strcpy(wepon[4].name, "라이플");
	strcpy(wepon[5].name, "지도");
	
	wepon[0].importance = 7;
	wepon[1].importance = 10;
	wepon[2].importance = 7;
	wepon[3].importance = 6;
	wepon[4].importance = 2;
	wepon[5].importance = 3;

	wepon[0].weight = 4;
	wepon[1].weight = 2;
	wepon[2].weight = 4;
	wepon[3].weight = 6;
	wepon[4].weight = 10;
	wepon[5].weight = 5;


	for (i = 0; i < 6; i++) 
	{
		printf("%s %d %d\n", wepon[i].name, wepon[i].importance, wepon[i].weight);
	}

	char nameTemp[32];
	int impTemp = 0;
	int weightTemp = 0;


	for (i = 0; i < 6; i++) 
	{
		for (j=i+1; j <6; j++) 
		{
			if (wepon[i].importance < wepon[j].importance) 
			{
				impTemp = wepon[i].importance;
				wepon[i].importance = wepon[j].importance;
				wepon[j].importance = impTemp;

				weightTemp = wepon[i].weight;
				wepon[i].weight = wepon[j].weight;
				wepon[j].weight = weightTemp;

				strcpy(nameTemp,wepon[i].name);
				strcpy(wepon[i].name, wepon[j].name);
				strcpy(wepon[j].name, nameTemp);
			}
		}
	}

	putchar('\n');
	putchar('\n');


	for (i = 0; i < 3; i++) 
	{
		impSum += wepon[i].importance;
	}

	printf("총 중요도 %d\n\n", impSum);

	for (i = 0; i < 3; i++)
	{
		printf("%s %d %d\n", wepon[i].name, wepon[i].importance, wepon[i].weight);
	}

}