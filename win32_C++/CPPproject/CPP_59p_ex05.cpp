#include "stdafx.h"
#include <iostream>

using namespace std;

double change(double input);

void main(void) {
	
	double input = 0;
	double result = 0;

	cout << "¼·¾¾ ¿Âµµ¸¦ ÀÔ·ÂÇÏ°í EnterÅ°¸¦ ´©¸£½Ê½Ã¿À" << endl;
	cin >> input;


	result = change(input);

	cout << "¼·¾¾" << input << "µµ´Â È­¾¾·Î" << result << "ÀÔ´Ï´Ù";


}

double change(double input)
{

	double result = 1.8*input + 32.0;


	return result;
}
