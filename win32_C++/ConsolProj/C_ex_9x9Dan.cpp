
#include "stdafx.h"
#include <conio.h>

//���� ���� ����
/*������ �ۼ�
2�� 3�� 4��

5�� 6�� 7��

8�� 9��

�������� �����
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