#include <stdio.h>
#define COLUMN 7 // 2���� �迭�� �����ټ��� 7�� ���� 
#define ROW 5 // 2���� �迭�� �����ټ��� 5�� ���� 

int main() {
	int array[ROW][COLUMN] = { 0, }; // 2���� �迭 ������ 0���� �ʱ�ȭ
	int i, j; // for ������ ������ ���� ���� ���� 
	int cnt = 1; // �ʱⰪ�� 1��.. 

	int x = 0, y = -1;
	enum { UP, DOWN } dir; // ������(enum)�� dir�� ���� UP, DOWN�� ���� ���� �� �ְ� ���� 
	dir = UP; //dir�� �ʱⰪ�� UP���� ���� 

	int total = COLUMN*ROW; // 2���� �迭�� ��ü ĭ �� 

	while (cnt <= total) {
		if (x == COLUMN - 1 && cnt <= total) { //2���� �迭�� ������ ���� �����ϴ� ��� 
			array[++y][x] = cnt++;
			dir = DOWN;
		}
		if (y == ROW - 1 && cnt <= total) { //2���� �迭�� �Ʒ��� ���� �����ϴ� ��� 
			array[y][++x] = cnt++;
			dir = UP;
		}
		if (y == 0 && cnt <= total) { //2���� �迭�� ���� ���� �����ϴ� ��� 
			array[y][++x] = cnt++;
			dir = DOWN;
		}
		if (x == 0 && cnt <= total) { //2���� �迭�� ���� ���� �����ϴ� ��� 
			array[++y][x] = cnt++;
			dir = UP;
		}
		if (dir == UP&&x != COLUMN - 1 && y != 0 && cnt <= total) array[--y][++x] = cnt++;  //�� �� dir�� UP�� ���
		if (dir == DOWN&&y != ROW - 1 && x != 0 && cnt <= total) array[++y][--x] = cnt++; //�� �� dir�� DOWN�� ���
	}
	//�迭�� ���� �Է�  

	for (i = 0; i<ROW; i++) {
		for (j = 0; j<COLUMN; j++) {
			printf("%2d ", array[i][j]);
		}
		printf("\n");
	}
	//�迭�� ǥ�� -������ ���� 

	return 0;
}