#include "stdafx.h"
#include <iostream>
#include <string>


using namespace std;

struct candyBar 
{
	string candyName;
	double weight;
	int kal;
};


void main(void) {

	candyBar snack = { "Mocha Munch", 2.3, 350 };

	cout << "상표명 : " << snack.candyName << "중량 : " << snack.weight << "칼로리 : " << snack.kal << endl;;

	candyBar snack1 = { "Peach Munch", 5.0, 400};
	candyBar snack2 = {"apple Munch", 6.0, 500};
	candyBar snack3 = {"mango Munch",7.0 ,600 };

	candyBar candyBarArr[3];
	candyBarArr[0] = snack1;
	candyBarArr[1] = snack2;
	candyBarArr[2] = snack3;

	cout << "복숭아 상표명" << candyBarArr[0].candyName << "중량" << candyBarArr[0].weight << "칼로리" << candyBarArr[0].kal << endl;
	cout << "사과 상표명" << candyBarArr[1].candyName << "중량" << candyBarArr[1].weight << "칼로리" << candyBarArr[1].kal << endl;;
	cout << "망고 상표명" << candyBarArr[2].candyName << "중량" << candyBarArr[2].weight << "칼로리" << candyBarArr[2].kal << endl;;


	
}