#include "stdafx.h"
#include <string>
#include <stack>
#include <queue>
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <cstdlib>

using namespace std;
queue<string> Queue;
stack<string> Stack;
stack<double> DoubleStack;

void main(void)
{
	unsigned int i = 0;

	ifstream fp;
	fp.open("calc2.txt");
	vector<string> v;
	string read; read.erase(0);
	string num; num.erase(0);
	string ceremony; ceremony.erase(0);
	int nCount = 0;

	if (fp.is_open())
	{
		fp >> read;
	}
	else
	{
		cout << "파일을 찾을 수 없습니다." << endl;
	}
	fp.close();


	for (i = 0; i < read.size(); i++)
	{

		if (read[i] >= 48 && read[i] <= 57)
		{
			num += read[i];
			nCount++;
		}
		else
		{
			if (nCount <= 0)
			{
				ceremony.push_back(read[i]);
				v.push_back(ceremony);
				ceremony.clear();
			}
			else
			{
				v.push_back(num);

				ceremony.push_back(read[i]);
				v.push_back(ceremony);

				ceremony.clear();
				num.erase(0);
				nCount = 0;

			}
		}
	}


	for (i = 0; i < v.size(); i++)
	{
		if (v[i] == "(")
		{
			Stack.push(v[i]);
		}

		else if (v[i] == "*")
		{
			Stack.push(v[i]);
		}

		else if (v[i] == "/")
		{
			Stack.push(v[i]);
		}

		else if (v[i] == "+" || v[i] == "-")
		{

			while (Stack.top() != "(" || Stack.empty() == true)
			{
				Queue.push(Stack.top());
				Stack.pop();
			}

			Stack.push(v[i]);
		}

		else if (v[i] == ")")
		{

			while (1)
			{
				if (Stack.top() == "(")
				{
					Stack.pop();
					break;
				}
				else
				{
					Queue.push(Stack.top());
					Stack.pop();

				}
			}

		}

		else//문자형 숫자 일 경우 큐에 저장
		{
			Queue.push(v[i]);
		}

	}


	//Queue 값 확인
	
	string temp;
	while (!Queue.empty())
	{
	temp = Queue.front();
	Queue.pop();
	cout << temp << endl;
	}
	

	/*
	double num1;
	double num2;

	while (!Queue.empty())
	{
		if (Queue.front() == "*")
		{
			num2 = DoubleStack.top();
			DoubleStack.pop();
			num1 = DoubleStack.top();
			DoubleStack.pop();

			DoubleStack.push(num1 * num2);
			Queue.pop();
		}
		else if (Queue.front() == "/")
		{
			num2 = DoubleStack.top();
			DoubleStack.pop();
			num1 = DoubleStack.top();
			DoubleStack.pop();

			DoubleStack.push(num1 / num2);
			Queue.pop();
		}
		else if (Queue.front() == "+")
		{
			num2 = DoubleStack.top();
			DoubleStack.pop();
			num1 = DoubleStack.top();
			DoubleStack.pop();

			DoubleStack.push(num1 + num2);
			Queue.pop();
		}
		else if (Queue.front() == "-")
		{
			num2 = DoubleStack.top();
			DoubleStack.pop();
			num1 = DoubleStack.top();
			DoubleStack.pop();

			DoubleStack.push(num1 - num2);
			Queue.pop();
		}
		else
		{
			double temp = atof(Queue.front().c_str());
			DoubleStack.push(temp);
			Queue.pop();
		}
	}

	cout << DoubleStack.top() << endl;
	*/
}