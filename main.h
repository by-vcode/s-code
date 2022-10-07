#include <iostream>
#include <stdio.h>
#include <stdarg.h> // 가변인자 함수 헤더
#include <algorithm> // sort 정렬 함수 헤더
#include <vector>
#include <sstream> // iss, getline

using namespace std;

//*** 함수 오버로드 :: 함수 내부의 처리 방법이 달라도 관계없는 경우
//*** 함수 템플릿 :: 함수 내부의 처리 방법이 같아야 하는 경우
//*** 아래와 같이 오버로드와 템플릿을 동시에 선언할 경우 템플릿에는 타지 않고 오버로드 함수를 탐
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

// & 권장
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