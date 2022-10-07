#include <iostream>
#include <stdio.h>
#include <stdarg.h> // �������� �Լ� ���
#include <algorithm> // sort ���� �Լ� ���
#include <vector>

#include <sstream> // iss, getline

using namespace std;

// ���ø� �Լ�
template <typename T>
T maxt(T x, T y)
{
	if (x > y)
		return x;
	else
		return y;
}

//* ���� �Լ�
template <typename T>
int mysum(T arg) // ���ڰ� �ϳ��� ���� �̱��϶�
{
	return arg;
}

template <typename T, typename ... types>
int mysum(T arg, types... args) // ���ڰ� �ΰ� �̻��϶�
{
	return arg + mysum(args...); // args... ���� ���� ���������� ����
}

template <typename... args> /*  mysumó�� ���ȣ���� �ϴ°� �ƴϹǷ� ���ø��� Ÿ�� ������ �ϳ� */
double myaverage(args... nums) /* �Լ� ���� ������ �ϳ��� �ϳ��� �ߴ� */
{
	return mysum(nums...) / sizeof...(nums); // sizeof... ���� ������ �˷��ش�
}

//* ������ �� ���� (�Ϲ� �Լ������� ����Լ��� ȣ�� �� ��������� ������ �����͸� ����ϸ� �ڵ� ���Եȴ�.)
void swap(int* pX, int* pY)
{
	int tmp;

	tmp = *pX;
	*pX = *pY;
	*pY = tmp;

	// return ���� ���� �ٷ� ����
}

//* ���۷��� (����Ʈ ó�� ���� �ٷ� ���� �� �� ����)
// int a = 5;
// int& rA = a; // a�� �ּ� ���� �ѱ�
void swap(int& pX, int& pY, int tx)
{
	int tmp;

	tmp = pX;
	pX = pY;
	pY = tmp;

	// return ���� ���� �ٷ� ����
}

vector<string> vSplit(string str, char delimiter)
{
	vector<string> internal;
	stringstream ss(str);
	string temp;
	while (getline(ss, temp, delimiter))
	{
		internal.push_back(temp);
	}
	return internal;
}

//////////////////////////////////////////////////////
// �ڵ� ����ȭ �˻�

void submain()
{

	return;

	// ���� ó��
	try
	{
		throw NULL; // (...) ���� ĳġ��
		//throw "user exception"; // (...) ���� ĳġ��
	}
	catch (exception& e)
	{
		cout << "Error : " << e.what() << endl;
	}
	catch (...)
	{
		cout << "Error Throw NULL : " << __LINE__ << endl;
	}

	// ������ ���� �ϼ���
	const int arrayRow(10), arrayCol(10);
	int multiplication[arrayRow][arrayCol] = { 0 };

	for (size_t row(1); row < arrayRow; row++)
	{
		for (size_t col(2); col < arrayCol; col++)
			cout << col << " x " << row << " = " << (multiplication[row][col] = row * col) << "\t";
		cout << endl;
	}

	int a;
	int* pA;

	a = 5;
	pA = &a;
	*pA = 7;

	int num1 = 5, num2 = 10;
	swap(&num1, &num2);
	swap(num1, num2, 3);

	int arr[] = { 30, 80, 60, 70, 90, 40 };

	// ��������
	sort(arr, arr + sizeof(arr) / sizeof(arr[0]));

	// ��������
	sort(arr, arr + sizeof(arr) / sizeof(arr[0]), greater<>());

	//* ���� �迭1
	vector<int> vArr = { 1,2,3,4,5,6,7,8,9,10 };

	copy(vArr.begin(), vArr.end(), ostream_iterator<int>(cout, "; "));
	cout << endl;

	// ���� ���ڿ� Split
	string line = "Thank you for visiting my Blog.";
	vector<string> line_vector = vSplit(line, ' ');
	for (int i = 0; i < line_vector.size(); ++i)
		cout << line_vector[i] << endl;

	char strx[6];

	strx[0] = 'h';
	strx[1] = 'e';
	strx[2] = 'l';
	strx[3] = 'l';
	strx[4] = 'o';
	strx[5] = '\0';

	//for (size_t i = 0; i < sizeof(strx) / sizeof(strx[0]); i++)
	for (size_t i = 0; strx[i] != '\0'; i++) // ���ǽ��̱⶧���� \0������ ���� ����
	{
		//vector<int> v(3);  // ũ�Ⱑ 3 �� ���� ����
		//cout << v.at(4);   // ?? ��������

		cout << "i �� : " << i << endl;
		if (strx[i] == '\0')
		{
			int bbb = 1;
		}
	}


	// ����
	copy(vArr.rbegin(), vArr.rend(), ostream_iterator<int>(cout, "; "));
	cout << endl;

	// ���� ���
	for_each(vArr.begin(), vArr.end(), [&](int& n) {
		cout << n << endl;        //output : 1 2 3 4
		});

	// ����
	for_each(vArr.rbegin(), vArr.rend(), [&](int& n) {
		cout << n << endl;        //output : 10, 9, 8, 7
		});

	for (auto const& value : vArr)
		cout << value << "; ";
	cout << endl;

	auto custom_func = [](auto& i) { cout << i << "; "; };
	for_each(vArr.begin(), vArr.end(), custom_func);
	cout << endl;

	//* ���� �迭2
	vector<int> v;

	v.push_back(10);
	v.push_back(20);        //v = { 10, 20 }

	cout << v.at(1) << "\n";

	v.insert(v.begin() + 1, 100);     // v = { 10, 100, 20 }

	v.pop_back();        // v = { 10, 100 }

	v.emplace_back(1); //v = { 10, 100, 1 }
	v.emplace_back(2);    //v = { 10, 100, 1, 2 }
	v.emplace(v.begin() + 2, -50);    //v = { 1, 100, -50, 1, 2 }

	v.erase(v.begin() + 1); // v = { 1, -50, 1, 2 }
	v.resize(6);    // v = { 1, -50, 1, 2, 0, 0 }
	v.clear();    // v = empty()     

	// �������� a index�� 5��(4,3,2,1������) roof�� ���� �ְ� ���� ���ڸ� a index�� ����
	int test[] = { 50, 30, 20, 70, 10 };

	for (size_t index = 0; index < sizeof(test) / sizeof(test[0]); index++)
	{
		for (size_t value = 0; value < sizeof(test) / sizeof(test[0]); value++)
		{
			if (test[value] > test[index])
			{
				int tmp = test[value];
				test[value] = test[index];
				test[index] = tmp;
			}
		}
	}

	// Declare a 10x10 array
	const int numRows(10);
	const int numCols(10);
	int product[numRows][numCols] = { 0 };

	// Calculate a multiplication table
	for (int row = 0; row < numRows; ++row)
		for (int col = 0; col < numCols; ++col)
			product[row][col] = row * col;

	// 9�ܱ��� row == 1
	// Print the table
	for (int row = 1, rowplus = 1; row < numRows; ++row)
	{
		// 2�ܺ��� 9�ܱ��� col == 2
		// ���� ����
		for (int col = 2, colplus = 2; col < numCols; ++col)
		{
			cout << colplus << " x " << rowplus << " = " << product[rowplus][colplus] << "\t";
			colplus++;
		}
		rowplus++;

		// ���� ����
		//for (int col = 1; col < numCols; ++col)
		//{
		//	std::cout << row << " x " << col << " = " << product[row][col] << "\t";
		//}

		cout << '\n';
	}


	cout << "a�� : " << LLONG_MAX << " pa�� : " << arr[1] << endl;

	cout << mysum(3, 5, 7) << endl;
	cout << myaverage(10, 10, 10) << endl;
	cout << maxt(7.1233, 5.342434) << endl;

	int bb = 5 > 3 ? 77 : 88;
	cout << bb << "\n";
	cout << (5 > 3 ? 1 : 0) << '\n';
	//printf("%d %f \f" , maxt(5, 9), maxt(5.5, 9.9));
}

// vector ����ϱ�