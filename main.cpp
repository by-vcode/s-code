#include "main.h"
#include <utility>

int main()
{
	for (char c = 'a'; c <= 'e'; ++c) // char ����
		cout << c << "\n";

	//*** ������
	int *iptr;    // int�� ������
	double *dptr; // double�� ������
	int *iptr2, *iptr3; // int�� �� ���� ������ ����
	
	// ���� �ʱ�ȭ
	int a = 5;
	int *iptr4 = &a;

	// ���� �ʱ�ȭ ����
	int x(3);
	int x2{ 7 };

	cout << typeid(&x).name() << endl; // int * __ptr64 (32, 64bit�� ���� ǥ��) typeid�� �μ��� �ڷ����� ��ȯ�Ѵ�.

	int value(5);
	cout << &value << endl; // value�� �ּҸ� ����Ѵ�.
	cout << value << endl;  // value�� ���� ����Ѵ�.

	int *ptr = &value; // ptr�� value�� ����Ų��.
	
	*ptr = 10;
	// *&x2 = 1234567890; // �̷��� ����� �� ���� ������ �߻� �� �� �ִ�. (���α׷� �ٿ�����)

	cout << ptr << endl;  // ptr�� ����Ű�� �ּҸ� ����Ѵ�. (=&value)
	cout << *ptr << endl; // ptr�� �������Ѵ�. (ptr�� ����Ű�� �ּ��� ���� ����Ѵ�. =value)

	// swapAnd(x, x1); // 3, 7
	swapT(x, x2);

	cout << "x �� : " << x << " /// x1 �� : " << x2 << endl;
	return 0;
}