#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void main(void) {

	struct tm *ptime = { 0 };
	time_t t = 0;

	t = time(NULL);
	ptime = localtime(&t);

	printf("%d\n", t);
	printf("%s", ctime(&t));

	printf("%04d-02d-%02d\n", ptime->tm_year + 1900, ptime->tm_mon+1, ptime->tm_mday);



}