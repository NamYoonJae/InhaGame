#include <stdio.h>
#define COLUMN 7 // 2차원 배열의 세로줄수를 7로 고정 
#define ROW 5 // 2차원 배열의 가로줄수를 5로 고정 

int main() {
	int array[ROW][COLUMN] = { 0, }; // 2차원 배열 생성후 0으로 초기화
	int i, j; // for 구문을 돌리기 위해 사용될 변수 
	int cnt = 1; // 초기값을 1로.. 

	int x = 0, y = -1;
	enum { UP, DOWN } dir; // 열거형(enum)은 dir이 오직 UP, DOWN의 값만 가질 수 있게 제한 
	dir = UP; //dir의 초기값을 UP으로 설정 

	int total = COLUMN*ROW; // 2차원 배열의 전체 칸 수 

	while (cnt <= total) {
		if (x == COLUMN - 1 && cnt <= total) { //2차원 배열의 오른쪽 끝에 도달하는 경우 
			array[++y][x] = cnt++;
			dir = DOWN;
		}
		if (y == ROW - 1 && cnt <= total) { //2차원 배열의 아래쪽 끝에 도달하는 경우 
			array[y][++x] = cnt++;
			dir = UP;
		}
		if (y == 0 && cnt <= total) { //2차원 배열의 위쪽 끝에 도달하는 경우 
			array[y][++x] = cnt++;
			dir = DOWN;
		}
		if (x == 0 && cnt <= total) { //2차원 배열의 왼쪽 끝에 도달하는 경우 
			array[++y][x] = cnt++;
			dir = UP;
		}
		if (dir == UP&&x != COLUMN - 1 && y != 0 && cnt <= total) array[--y][++x] = cnt++;  //그 외 dir이 UP인 경우
		if (dir == DOWN&&y != ROW - 1 && x != 0 && cnt <= total) array[++y][--x] = cnt++; //그 외 dir이 DOWN인 경우
	}
	//배열에 숫자 입력  

	for (i = 0; i<ROW; i++) {
		for (j = 0; j<COLUMN; j++) {
			printf("%2d ", array[i][j]);
		}
		printf("\n");
	}
	//배열을 표시 -이전과 동일 

	return 0;
}