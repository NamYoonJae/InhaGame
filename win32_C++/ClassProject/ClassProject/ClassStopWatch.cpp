#include "stdafx.h"
#include <iostream>
#include <string>
#include "stopWatch.h"

/*
	stopwatch class�� �����϶�.

	1. get �Լ��� ���� ���� ������ �ʵ� startTime �� endTime
	2. startTime�� ���� �ð����� �ʱ�ȭ�ϴ� �μ����� ������
	3. startTime�� ���� �ð����� �缳���ϴ� start() �Լ�
	4. endTime�� ���� �ð����� �����ϴ� stop() �Լ�
	5. �����ġ�� ��� �ð��� millisecond�� ��ȯ�ϴ� getElapsedTime() �Լ�

	�ش� Ŭ������ ���� UML ���̾�׷��� �׸���, 
	���� ���İ� ���� ������ ����Ͽ� 
	100,000���� ���ڸ� �����ϴµ� �ɸ� ���� �ð��� ���� ���ϴ� ���α׷��� �ۼ�.
*/


using namespace std;

void main(void) 
{
	//���� �迭�� 10���� ���ڵ��� ����
	/*
	stopWatch bubble;
	bubble.inNumber();
	cout << "=====��������=====" << endl;
	bubble.start();
	bubble.bubbleSort();
	bubble.end();
	bubble.timeCal();
	
	
	stopWatch choice;
	choice.inNumber();
	cout << "=====��������=====" << endl;
	choice.start();
	choice.choiceSort();
	choice.end();
	choice.timeCal();
	
	
	stopWatch insert;
	insert.inNumber();
	cout << "====��������====" << endl;
	insert.start();
	insert.insertSort();
	insert.end();
	insert.timeCal();
	

	stopWatch shell;
	shell.inNumber();
	cout << "====�� ����====" << endl;
	shell.start();
	shell.shellSort();
	shell.end();
	shell.timeCal();
	*/

	stopWatch mercy;
	mercy.inNumber();
	cout << "====���� ����====" << endl;
	mercy.start();
	mercy.partition(0, maxSize);
	mercy.end();
	mercy.timeCal();



}