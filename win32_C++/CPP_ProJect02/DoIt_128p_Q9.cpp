#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>

int int_cmp(const int *a, const int *b) 
{
	if (*a < *b)
		return -1;
	else if (*a > *b)
	{
		return 1;
	}
	else
		return 0;
}
void *besearchx(const void *key, const void *base, size_t nmemb, size_t size, int(*compar)(const void*, const void *));

void main(void) {

	int i = 0;
	int key = 0;
	int nx = 0;
	int *x;
	int *p;

	printf("요소 개수 입력 : ");
	scanf_s("%d",&nx);
	x = (int*)calloc(nx, sizeof(int));

	printf("오름차순으로 입력하세요.\n");
	printf("x[0] : ");
	scanf_s("%d",&x[0]);
	for (i = 1; i < nx; i++) 
	{
		do
		{
			printf("x[%d] : ", i);
			scanf_s("%d", &x[i]);
		} while ( x[i] < x[i-1] );
	}
	printf("검색값 : ");
	scanf_s("%d",&key);

	p = (int*)besearchx(&key, x, nx , sizeof(int), (int(*)(const void *, const void *)) int_cmp);

	
	if (p == NULL)
	{
		printf("검색에 실패했습니다");
	}
	else
	{
		printf("%d는 x[%d]에 있습니다\n", key, (int)(p - x));
	}
	

	free(x);
}

void * besearchx(const void * key, const void * base, size_t nmemb, size_t size, int(*compar)(const void *, const void *))
{
	/*
		key  -> 검색값
		nx -> 요소 갯수
		x -> 요소들
		compr 함수의 리턴값이 양수일 경우 오른쪽, 음수일 경우 왼쪽을 탐색
	*/

	int startIndex = 0;
	int endIndex = nmemb-1;
	int middleIndex = (startIndex + endIndex) / 2;

	char *x = (char*)base;

	if (nmemb > 0)
	{
		while (1) 
		{
			int comp = compar((const void*)&x[middleIndex * size], key);

			if (comp == 0)//검색 성공
			{
				for (; middleIndex > startIndex; middleIndex--) //key와 같은 요소를 찾는다
					if (compar((const void*)&x[(middleIndex - 1) * size], key))//가운데-1 인덱스 * size 와 key값
						break;
				return &x[middleIndex * size];
			}
			else if (startIndex == endIndex)
				break;
			else if (comp < 0)
				startIndex = middleIndex + 1;
			else
				endIndex = middleIndex - 1;
		}
	
	}

	return NULL;
}
