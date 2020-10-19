
#include "stdafx.h"
#include <conio.h>

//교재 78p	// 가볍게 넘어가기
int main(void) {

	long long int lldData = 4294967295LL;

	printf("%d\n", lldData);
	printf("%u\n", lldData);

	printf("%d\n", lldData + 1);
	printf("%d\n", lldData + 2);
	printf("%d\n", lldData + 3);

	printf("%lld\n", lldData + 1);
	printf("%lld\n", lldData + 2);
	printf("%lld\n", lldData + 3);

	return 0;
}
