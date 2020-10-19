#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void main(void) {

	int arr[6] = {1, 1, 1, 0, 1, 0};
	int divide[6] = {0};
	int i = 0;
	int k = 1;
	int n = 0;
	int h = 0;
	int hour = 0;
	int arrSize = sizeof(arr) / sizeof(arr[0]);
	int num = 0;
	int flag = 0;
	

	cout << "¸î ½Ã°£ ºÐ¿­: ";
	cin >> hour;
	cout << endl;

	for (h = 0; h < hour; h++) 
	{
		switch (flag)
		{
		case 0:

			for (i = 0; i < 6; i++)
			{
				if (arr[i] > 0)
				{

					if (i == 0)
					{
						for (k = 0; k < 6; k++)
						{
							divide[k] += arr[i];
						}
					}
					else
					{
						divide[i] += arr[i];
						num = i + 1;
						for (k = 2; k < 7; k++)
						{
							if (num * k - 1 > 6)
							{
								break;
							}
							divide[num * k - 1] += arr[i];
						}

					}
				}

			}

			for (i = 0; i < 6; i++)
			{
				cout << divide[i] << "  ";
			}
			cout << endl;
			cout << endl;

			for (i = 0; i < 6; i++) 
			{
				arr[i] = 0;
			}
			flag = 1;
			break;
		case 1:

			for (i = 0; i < 6; i++) 
			{
				if (divide[i] > 0) 
				{
					if (i == 0)
					{
						for (k = 0; k <6; k++) 
						{
							arr[k] += divide[i];
						}
					}
					else
					{
						arr[i] += divide[i];
						num = i + 1;
						for (k = 2; k < 6; k++)
						{
							if (num * k - 1 > 6)
							{
								break;
							}
							arr[num * k - 1] += divide[i];
						}
					}
				}
			}


			for (i = 0; i < 6; i++)
			{
				cout << arr[i] << "  ";
			}
			cout << endl;

			for (i = 0; i < 6; i++)
			{
				divide[i] = 0;
			}

			
			flag = 0;
			break;

		default:
			break;
		}
	}


	int reNum = 0;// Á¢½Ã °¹¼ö
	int nuclear = 0;
	vector<int> v;

	cout << "Á¢½Ã °¹¼ö ÀÔ·Â: " << endl;
	cin >> reNum;


	for (i = 0; i < reNum; i++) 
	{
		cout << i + 1 << "¹ø¤Š Á¢½Ã ÇÙ °¹¼ö";
		cin >> nuclear;
		v.push_back(nuclear);
	}
	
	

	
}