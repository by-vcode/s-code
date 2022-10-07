#include "main.h"
#include <utility>

int main()
{
	for (char c = 'a'; c <= 'e'; ++c) // char 루프
		cout << c << "\n";

	//*** 포인터
	int *iptr;    // int형 포인터
	double *dptr; // double형 포인터
	int *iptr2, *iptr3; // int형 두 개의 포인터 선언
	
	// 복사 초기화
	int a = 5;
	int *iptr4 = &a;

	// 직접 초기화 권장
	int x(3);
	int x2{ 7 };

	cout << typeid(&x).name() << endl; // int * __ptr64 (32, 64bit에 따른 표기) typeid는 인수의 자료형을 반환한다.

	int value(5);
	cout << &value << endl; // value의 주소를 출력한다.
	cout << value << endl;  // value의 값을 출력한다.

	int *ptr = &value; // ptr은 value를 가리킨다.
	
	*ptr = 10;
	// *&x2 = 1234567890; // 이렇게 사용할 시 추후 문제가 발생 될 수 있다. (프로그램 다운현상)

	cout << ptr << endl;  // ptr이 가리키는 주소를 출력한다. (=&value)
	cout << *ptr << endl; // ptr을 역참조한다. (ptr이 가리키는 주소의 값을 출력한다. =value)

	// swapAnd(x, x1); // 3, 7
	swapT(x, x2);

	cout << "x 값 : " << x << " /// x1 값 : " << x2 << endl;
	return 0;
}