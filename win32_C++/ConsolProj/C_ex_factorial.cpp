
#include "stdafx.h"
#include <conio.h>


//5! ±¸ÇÏ±â
int main(void) {

	int nInput = 0;
	int i = 0;
	int result = 1;

	scanf("%d", &nInput);

	for (i = 1; i <= nInput; i++) {

		result *= i;
	}
	printf("%d\n", result);

	return 0;


}