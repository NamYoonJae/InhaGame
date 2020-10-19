// Calculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// >> : 
bool IsOperand(string s)
{
	if (s == string("+") ||
		s == string("-") ||
		s == string("*") ||
		s == string("/") ||
		s == string("(") ||
		s == string(")")
		)
		return false;
	return true;
}

bool IsOperator(string sInfix, int &n)
{
	if (sInfix[n] == '(' ||
		sInfix[n] == ')' ||
		sInfix[n] == '+' ||
		//sInfix[n] == '-' ||
		sInfix[n] == '*' ||
		sInfix[n] == '/'
		)
		return true;

	if (sInfix[n] == '-' && sInfix[n - 1] != '(')
		return true;

	return false;
}

string GetToken(string sInfix, int &n)
{
	string sToken;
	while (true)
	{
		if (IsOperator(sInfix, n))
		{
			if (sToken.length() == 0)
				sToken = sInfix[n++];
			break;
		}
		else
		{
			char szTemp[] = { sInfix[n++] , '\0' };
			sToken += string(szTemp);
		}
	}
	return sToken;
}

int main()
{
	char szTemp[1024];
	FILE* fp = NULL;
	fopen_s(&fp, "calc.txt", "r");
	fgets(szTemp, 1024, fp);
	fclose(fp);

	string sInfix(szTemp);
	sInfix = string("(") + sInfix + string(")");
	cout << "Infix Notation : " << sInfix << endl;

	// : 
	map<string, int > mapOperatorPriority;
	mapOperatorPriority["("] = 0;
	mapOperatorPriority["*"] = 2;
	mapOperatorPriority["/"] = 2;
	mapOperatorPriority["+"] = 1;
	mapOperatorPriority["-"] = 1;


	vector<string> vecPostFixQueue;
	vector<string> vecOperatorStack;

	int nIndex = 0;
	while (nIndex < sInfix.length())
	{
		string sToken = GetToken(sInfix, nIndex);
		if (IsOperand(sToken))
		{
			vecPostFixQueue.push_back(sToken);
		}
		else
		{
			if (sToken == "(")
			{
				vecOperatorStack.push_back(sToken);
			}
			else if (sToken == ")")
			{
				while (true)
				{
					string sTop = vecOperatorStack.back();
					vecOperatorStack.pop_back();
					if (sTop == "(")
						break;

					vecPostFixQueue.push_back(sTop);
				}
			}
			else
			{
				int nPriority = mapOperatorPriority[sToken];
				while (true)
				{
					string sTop = vecOperatorStack.back();
					if (mapOperatorPriority[sTop] < nPriority)
						break;
					vecPostFixQueue.push_back(sTop);
					vecOperatorStack.pop_back();
				}
				vecOperatorStack.push_back(sToken);
			} // << else 
		} // << <: if else
	} // << while

	cout << "Postfix Notation : ";
	for (int i = 0; i < vecPostFixQueue.size(); ++i)
	{
		cout << vecPostFixQueue[i] << " ";
	}
	cout << endl;

	vector<float> vecOperandStack;
	for (size_t i = 0; i < vecPostFixQueue.size(); ++i)
	{
		if (IsOperand(vecPostFixQueue[i]))
		{
			float f = (float)atof(vecPostFixQueue[i].c_str());
			vecOperandStack.push_back(f);
		}
		else
		{
			float f2 = vecOperandStack.back();
			vecOperandStack.pop_back();
			float f1 = vecOperandStack.back();
			vecOperandStack.pop_back();
			if (vecPostFixQueue[i] == "+")
			{
				vecOperandStack.push_back(f1 + f2);
			}
			else if (vecPostFixQueue[i] == "-")
			{
				vecOperandStack.push_back(f1 - f2);
			}
			else if (vecPostFixQueue[i] == "*")
			{
				vecOperandStack.push_back(f1 * f2);
			}
			else if (vecPostFixQueue[i] == "/")
			{
				vecOperandStack.push_back(f1 / f2);
			} // << : else if
		} // << : if  else
	} // << : for


	cout << "계산 결과 : " << vecOperandStack.front() << endl;


	return 0;
}

