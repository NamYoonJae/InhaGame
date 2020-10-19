#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

/*
카페 손님이 음료를 주문한 시각이 주어질 때, K분 동안 주문이 최대 몇 건 들어왔는지 구하려 합니다.

예를 들어 음료를 주문한 시각이 ["12:10", "12:"20", "12:40", "12:40", "12:50", "13:00", "13:20"]이고,
k = 20인 경우, "12:40"부터 "13:00"까지가 20분 동안 주문이 가장 많이 들어온 때이며, 
이때 들어온 주문은 4건입니다.

음료 주문이 들어온 시각이 들어있는 배열 order_times와 자연수 k가 매개변수로 주어질 때,
k분동안 주문이 최대 몇 건 들어왔는지 return 하도록 solution 함수를 완성해주세요.

제한사항
1. order_time의 길이는 1이상 1,000 이하 입니다
2. order_time의 원소는 시각을 나타내는 문자열입니다.
	시각은 "HH:MM" 형식의 문자열입니다.
	HH:MM은 HH시 MM분을 나타내며, 24시간 표기법으로 나타냅니다.
3. 시각은 05:00 부터 23:59까지 하루동안의 시각만 들어있으며, 오름차순 정렬되어 있습니다.
4. 중복되는 시각이 있을 수 있으며, 이는 같은 시각에 음료 주문이 여러 건 들어온 것을 의미합니다.
5. k는 1이상 120 이하인 자연수입니다.
6. k분이 시작하는 순간과 끝나는 순간에 들어온 주문도 포함해서 세면 됩니다.

ex>
order_time														k		result
{"12:10", "12:20", "12:40", "12:50", "13:00", "13:20"}			20		4

*/

using namespace std;

void main(void) {

	
	vector <string> order_time;
	vector <string> temp_time;
	vector <int> num_time;
	string temp;
	int i = 0;
	int j = 0;
	int k = 20;
	int cnt = 0;
	int maxCnt = 0;

	/*
	order_time.push_back("12:10");
	order_time.push_back("12:20");
	order_time.push_back("12:40");
	order_time.push_back("12:40");
	order_time.push_back("12:50");
	order_time.push_back("13:00");
	order_time.push_back("13:05");
	order_time.push_back("13:06");
	order_time.push_back("13:07");
	order_time.push_back("13:08");
	order_time.push_back("13:20");
	*/

	order_time.push_back("14:10");
	order_time.push_back("14:11");
	order_time.push_back("14:15");
	order_time.push_back("14:20");
	order_time.push_back("14:20");
	order_time.push_back("14:40");
	order_time.push_back("15:40");
	order_time.push_back("17:00");
	order_time.push_back("17:00");
	order_time.push_back("17:00");
	order_time.push_back("17:00");
	order_time.push_back("17:00");
	order_time.push_back("17:00");
	order_time.push_back("17:00");
	order_time.push_back("17:20");


	int index = 0;

	for (i = 0; i < order_time.size(); i++)
	{
		for (j = 0; j < order_time[i].length(); j++)
		{
			if (order_time[i][j] != ':') 
			{
				temp.push_back(order_time[i][j]);
			}
		}
		temp.push_back('\0');
		int num = stoi(temp);
		num_time.push_back(num);
		temp.clear();
	}
	
	for (i = 0 ; i < num_time.size(); i++)
	{
		cout <<"temp_time : "<< num_time[i] << endl;
	}

	cout << endl;
	
	for (i = 0; i < num_time.size(); i++) 
	{
		double Share = num_time[i] / 100; //몫 - 시간
		double rest = num_time[i] % 100; //나머지 - 분
		num_time[i] = Share * 60 + rest;

	}

	for (i = 0; i < num_time.size(); i++)
	{
		cout << "temp_time : " << num_time[i] << endl;
	}


	for (i = 0; i < num_time.size(); i++) 
	{
		cnt = 0;
		for (j = i; j < num_time.size(); j++) 
		{
			if (num_time[i] <= num_time[j] && num_time[j] <= num_time[i] + k) 
			{
				cnt++;
			}

			if (cnt > maxCnt)
			{
				maxCnt = cnt;
			}
		}

	}
	
	cout <<k << "분 동안 최대 "<< maxCnt <<"주문 들어왔습니다"<< endl;
}