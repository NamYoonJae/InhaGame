#include "stdafx.h"
#include <iostream>
#include <string>
#include "rectangle.h"

/*
���簢���� ��Ÿ���� Rectangle�̶� �̸��� Ŭ������ �����϶�.
Ŭ������ ������ �����Ѵ�.
1. ���簢���� ���� ���̸� ��Ÿ���� width, height ��� �̸��� double ������ �ʵ�
2. width �� height�� ���� 1�� ���簢���� �����ϴ� �μ� ���� ������
3. ������ width�� height�� ���� �⺻ ���簢���� �����ϴ� ������
4. ��� ������ �ʵ忡 ���� �����ڿ� ������ �Լ�
setWidth(), setHeight(),
getWidth(), getHight()
5. ���簢���� ���� ���� ��ȯ�ϴ� getArea() �Լ�
6. �ѷ� ���̸� ��ȯ�ϴ� getPerimeter() �Լ�

ex) �� ���� Retangle ��ü�� �����ϴ� �׽�Ʈ ���α׷��� �ۼ��ϰ�,
ù ��° ��ü���� width = 4, height = 40
�� ��° ��ü���� width = 3.5 height = 35.9
���� �Ҵ��ϰ�, �� ��ü�� �Ӽ��� ǥ���ϰ� ������ �ѷ� ���̸� ����϶�.
ex ) W : 4, H = 30, Area = 160, Per..= 88

*/
using namespace std;

void main(void) 
{
	rectangle rect1;
	rect1.setWidth(4);
	rect1.setHeght(40);
	rect1.getWidth();
	rect1.getHeight();
	rect1.area();
	rect1.circumference();
	cout << endl;

	rectangle rect2;
	rect1.setWidth(3.5);
	rect1.setHeght(35.9);
	rect1.getWidth();
	rect1.getHeight();
	rect1.area();
	rect1.circumference();
	cout << endl;



}


