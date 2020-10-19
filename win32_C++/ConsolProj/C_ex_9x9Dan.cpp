
#include "stdafx.h"
#include <conio.h>

//개인 과제 제출
/*구구단 작성
2단 3단 4단

5단 6단 7단

8단 9단

형식으로 만들기
*/
int main(void) {

	int x = 0;
	int y = 0;
	int z = 0;


	for (z = 0; z <3; ++z) {

		if (z == 2) {
			printf("  %d\t  %d\t\t\n", 2 * 3 + 2, z * 3 + 3);
			printf("===============\n");
		}
		else {
			printf("  %d\t  %d\t  %d\n", z * 3 + 2, z * 3 + 3, z * 3 + 4);
			printf("========================\n");
		}
		for (x = 1; x < 10; ++x) {

			if (z == 2) {

				for (y = z * 3 + 2; y <= z * 3 + 3; ++y) {
					printf("%d*%d=%d\t", y, x, x*y);
				}

			}
			else

				for (y = z * 3 + 2; y <= z * 3 + 4; ++y) {
					printf("%d*%d=%d\t", y, x, x*y);
				}

			putchar('\n');

		}
		putchar('\n');


	}


	return 0;


}