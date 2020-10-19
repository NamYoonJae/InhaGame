#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

/*
ī�� �մ��� ���Ḧ �ֹ��� �ð��� �־��� ��, K�� ���� �ֹ��� �ִ� �� �� ���Դ��� ���Ϸ� �մϴ�.

���� ��� ���Ḧ �ֹ��� �ð��� ["12:10", "12:"20", "12:40", "12:40", "12:50", "13:00", "13:20"]�̰�,
k = 20�� ���, "12:40"���� "13:00"������ 20�� ���� �ֹ��� ���� ���� ���� ���̸�, 
�̶� ���� �ֹ��� 4���Դϴ�.

���� �ֹ��� ���� �ð��� ����ִ� �迭 order_times�� �ڿ��� k�� �Ű������� �־��� ��,
k�е��� �ֹ��� �ִ� �� �� ���Դ��� return �ϵ��� solution �Լ��� �ϼ����ּ���.

���ѻ���
1. order_time�� ���̴� 1�̻� 1,000 ���� �Դϴ�
2. order_time�� ���Ҵ� �ð��� ��Ÿ���� ���ڿ��Դϴ�.
	�ð��� "HH:MM" ������ ���ڿ��Դϴ�.
	HH:MM�� HH�� MM���� ��Ÿ����, 24�ð� ǥ������� ��Ÿ���ϴ�.
3. �ð��� 05:00 ���� 23:59���� �Ϸ絿���� �ð��� ���������, �������� ���ĵǾ� �ֽ��ϴ�.
4. �ߺ��Ǵ� �ð��� ���� �� ������, �̴� ���� �ð��� ���� �ֹ��� ���� �� ���� ���� �ǹ��մϴ�.
5. k�� 1�̻� 120 ������ �ڿ����Դϴ�.
6. k���� �����ϴ� ������ ������ ������ ���� �ֹ��� �����ؼ� ���� �˴ϴ�.

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
		double Share = num_time[i] / 100; //�� - �ð�
		double rest = num_time[i] % 100; //������ - ��
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
	
	cout <<k << "�� ���� �ִ� "<< maxCnt <<"�ֹ� ���Խ��ϴ�"<< endl;
}