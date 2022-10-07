#include <iostream>
#include <stdio.h>
#include <stdarg.h> // �������� �Լ� ���
#include <algorithm> // sort ���� �Լ� ���
#include <vector>
#include <sstream> // iss, getline

using namespace std;

//*** �Լ� �����ε� :: �Լ� ������ ó�� ����� �޶� ������� ���
//*** �Լ� ���ø� :: �Լ� ������ ó�� ����� ���ƾ� �ϴ� ���
//*** �Ʒ��� ���� �����ε�� ���ø��� ���ÿ� ������ ��� ���ø����� Ÿ�� �ʰ� �����ε� �Լ��� Ž
template <class T>
T max(T x, T y)
{
	if (x > y)
		return x;
	else
		return y;
}

int max(int x, int y)
{
	if (x > y)
		return x;
	else
		return y;
}

double max(double x, double y)
{
	if (x > y)
		return x;
	else
		return y;
}

// & ����
void swapAnd(int& ipX, int& ipY)
{
	int tmp = ipX;
	ipX = ipY;
	ipY = tmp;
}

void swapPtr(int* ipX, int* ipY)
{
	int tmp = *ipX;
	*ipX = *ipY;
	*ipY = tmp;
}

template <typename T>
void swapT(T& x, T& y)
{
	T tmp = x;
	x = y;
	y = tmp;
}