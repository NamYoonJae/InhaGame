#include <stdio.h>
#include "stdafx.h"

void main() 
{
	FILE *fp = NULL;
	char szBuffer[512] = { 0 }; 
	
	//만약 szBuffer2[512]를 하나 더 생성한다면 ?
	
	fp = fopen("Test.txt", "w");
	fputs("Test\n", fp); //Test 는 szBuffer에 들어가고
	fputs("String\n", fp); //String은 szBuffer2에 들어간다
	fputs("Data\n", fp);
	fclose(fp);

	fp = fopen("Test.txt", "r");
	
	if (fp == NULL)
		return;

	
	while (fgets(szBuffer, sizeof(szBuffer), fp)) 
	{
		printf("%s", szBuffer);
		memset(szBuffer, 0, sizeof(szBuffer));
	}
	//글자 모두 출력하고 문자 끝을 표현하는 마지막 NULL문자가 나오는데
	//그때 NULL값을 반환하면서 while문을 빠져나온다

	fclose(fp);

}