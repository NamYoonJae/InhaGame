#include "stdafx.h"
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define _MSGTEST_//�̰��� �̸� �����ϸ� I am a boy ���
				//���ϸ� You are a girl ���

#ifdef _MSGTEST_
#define MYMESSAGE "I am a boy."
#else
#define MYMESSAGE "You are a girl."
#endif



void main(void) {
	puts(MYMESSAGE);

}