
#include "stdafx.h"
#include <conio.h>
#include <windows.h>

//교재 234p 필습 실습 문제 07-02
int main (void){

	int x = 0;
	int y = 0;


	for (x = 0; x < 5; x++) {

		for (y = 0; y < 5; y++) {
			printf("*\t");
		}

		printf("\n");

	}

	
	return 0;
}