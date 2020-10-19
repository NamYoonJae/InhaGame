#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define _MSGTEST_//이것을 미리 선언하면 I am a boy 출력
				//안하면 You are a girl 출력

#ifdef _MSGTEST_
#define MYMESSAGE "I am a boy."
#else
#define MYMESSAGE "You are a girl."
#endif



void main(void) {
	puts(MYMESSAGE);

}