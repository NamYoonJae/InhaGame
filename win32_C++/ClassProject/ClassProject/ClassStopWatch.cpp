#include "stdafx.h"
#include <iostream>
#include <string>
#include "stopWatch.h"

/*
	stopwatch class를 설계하라.

	1. get 함수를 갖는 전용 데이터 필드 startTime 과 endTime
	2. startTime을 현재 시간으로 초기화하는 인수없는 생성자
	3. startTime을 현재 시간으로 재설정하는 start() 함수
	4. endTime을 현재 시간으로 설정하는 stop() 함수
	5. 스톱워치의 경과 시간을 millisecond로 반환하는 getElapsedTime() 함수

	해당 클래스에 대한 UML 다이어그램을 그리고, 
	버블 정렬과 선택 정렬을 사용하여 
	100,000개의 숫자를 정렬하는데 걸린 실행 시간을 측정 비교하는 프로그램을 작성.
*/


using namespace std;

void main(void) 
{
	//먼저 배열에 10만의 숫자들을 대입
	/*
	stopWatch bubble;
	bubble.inNumber();
	cout << "=====버블정렬=====" << endl;
	bubble.start();
	bubble.bubbleSort();
	bubble.end();
	bubble.timeCal();
	
	
	stopWatch choice;
	choice.inNumber();
	cout << "=====선택정렬=====" << endl;
	choice.start();
	choice.choiceSort();
	choice.end();
	choice.timeCal();
	
	
	stopWatch insert;
	insert.inNumber();
	cout << "====삽입정렬====" << endl;
	insert.start();
	insert.insertSort();
	insert.end();
	insert.timeCal();
	

	stopWatch shell;
	shell.inNumber();
	cout << "====셀 정렬====" << endl;
	shell.start();
	shell.shellSort();
	shell.end();
	shell.timeCal();
	*/

	stopWatch mercy;
	mercy.inNumber();
	cout << "====병합 정렬====" << endl;
	mercy.start();
	mercy.partition(0, maxSize);
	mercy.end();
	mercy.timeCal();



}