#include "stdafx.h"
#include <iostream>
#include "hangman.h"
#include <string>
/*
임의의 한 단어를 생성하고, 사용자가 한번에 한 문자만을 추측하도록 하는 행맨 게임을 작성하라.
단어의 각 문자는 * 로 표시된다
사용자가 올바른 추측을 하였을 때는 실제 문자가 화면에 표시된다.
사용자가 단어를 맞추기를 끝냈을 때는 실수한 회수를 표시하고 다른 단어로 계속할 것인지를 묻는다

string words[] = {"writer", "hospital", ...}

ex> 단어중 한 글자를 입력하시오 ***** > w
단어중 한 글자를 입력하시오 w**** > p
p는 단어에 포함되지 않음.
단어 중 한글자를 입력하시오 w**** > w
w는 이미 포함된 단어입니다.
...
총 xx번 실패, xx 번만에 단어 완성.
*/

/*
//string words[] = {}단어가 있는 배열
//temp[words[i]] 배열
//입력 받을 input
//기회 체크 변수	static m_challengeCheck
//실패 체크 변수  static m_failCheck

먼저 첫번째 단어 길이만큼의 temp 를 생성

temp 길이만큼 * 출력

입력 받기

입력 길이가 1이면
초성이 있는지 확인하고 있다면 temp 의 그자리에 해당 초성 입력
초성 기회 증가



입력길이가 1이 아니면
단어와 비교해서 같으면
정답입니다 / 총 xx 번 실패 / xx번 만에 단어완성 출력

다른 단어로 계속 할것인가 ?
그렇다면 words[i] 증가시킨 단어로 다시 시작
아니면 종료

단어와 다르면
오답입니다 / 실패 횟수 증가


*/

using namespace std;

void main(void) 
{



}