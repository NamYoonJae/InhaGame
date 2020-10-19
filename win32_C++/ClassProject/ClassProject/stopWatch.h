#pragma once
#include <time.h>
#include <vector>
const int maxSize = 100000;
class stopWatch 
{

private:

	int arr[maxSize] = { 0 };

	clock_t m_startTime;
	clock_t m_endTime;


public:

	stopWatch();
	stopWatch(clock_t s, clock_t e)
	{
		m_startTime = s;
		m_endTime = e;
	}
	~stopWatch();
	
	void inNumber();

	void start();
	void end();

	void bubbleSort();
	void choiceSort();
	void insertSort();
	void shellSort();
	void partition(int leftIndex, int rightIndex);
	void mercy(int leftIndex, int rightIndex);

	void timeCal();
};