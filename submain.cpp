#include <iostream>
#include <stdio.h>
#include <stdarg.h> // 가변인자 함수 헤더
#include <algorithm> // sort 정렬 함수 헤더
#include <vector>

#include <sstream> // iss, getline

using namespace std;

// 템플릿 함수
template <typename T>
T maxt(T x, T y)
{
	if (x > y)
		return x;
	else
		return y;
}

//* 가변 함수
template <typename T>
int mysum(T arg) // 인자가 하나만 남아 싱글일때
{
	return arg;
}

template <typename T, typename ... types>
int mysum(T arg, types... args) // 인자가 두개 이상일때
{
	return arg + mysum(args...); // args... 인자 개수 마지막에만 실행
}

template <typename... args> /*  mysum처럼 재귀호출을 하는게 아니므로 템플릿에 타입 종류도 하나 */
double myaverage(args... nums) /* 함수 인자 종류도 하나도 하나로 했다 */
{
	return mysum(nums...) / sizeof...(nums); // sizeof... 인자 개수를 알려준다
}

//* 포인터 값 전달 (일반 함수에서는 계산함수를 호출 후 대입해줘야 하지만 포인터를 사용하면 자동 대입된다.)
void swap(int* pX, int* pY)
{
	int tmp;

	tmp = *pX;
	*pX = *pY;
	*pY = tmp;

	// return 값이 없고 바로 대입
}

//* 레퍼런스 (포인트 처럼 값을 바로 변경 할 수 있음)
// int a = 5;
// int& rA = a; // a의 주소 값을 넘김
void swap(int& pX, int& pY, int tx)
{
	int tmp;

	tmp = pX;
	pX = pY;
	pY = tmp;

	// return 값이 없고 바로 대입
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
// 코드 최적화 검색

void submain()
{

	return;

	// 예외 처리
	try
	{
		throw NULL; // (...) 으로 캐치됨
		//throw "user exception"; // (...) 으로 캐치됨
	}
	catch (exception& e)
	{
		cout << "Error : " << e.what() << endl;
	}
	catch (...)
	{
		cout << "Error Throw NULL : " << __LINE__ << endl;
	}

	// 구구단 최적 완성본
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

	// 오름차순
	sort(arr, arr + sizeof(arr) / sizeof(arr[0]));

	// 내림차순
	sort(arr, arr + sizeof(arr) / sizeof(arr[0]), greater<>());

	//* 백터 배열1
	vector<int> vArr = { 1,2,3,4,5,6,7,8,9,10 };

	copy(vArr.begin(), vArr.end(), ostream_iterator<int>(cout, "; "));
	cout << endl;

	// 벡터 문자열 Split
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
	for (size_t i = 0; strx[i] != '\0'; i++) // 조건식이기때문에 \0만나면 루프 종료
	{
		//vector<int> v(3);  // 크기가 3 인 벡터 만듦
		//cout << v.at(4);   // ?? 강제에러

		cout << "i 값 : " << i << endl;
		if (strx[i] == '\0')
		{
			int bbb = 1;
		}
	}


	// 역순
	copy(vArr.rbegin(), vArr.rend(), ostream_iterator<int>(cout, "; "));
	cout << endl;

	// 개별 출력
	for_each(vArr.begin(), vArr.end(), [&](int& n) {
		cout << n << endl;        //output : 1 2 3 4
		});

	// 역순
	for_each(vArr.rbegin(), vArr.rend(), [&](int& n) {
		cout << n << endl;        //output : 10, 9, 8, 7
		});

	for (auto const& value : vArr)
		cout << value << "; ";
	cout << endl;

	auto custom_func = [](auto& i) { cout << i << "; "; };
	for_each(vArr.begin(), vArr.end(), custom_func);
	cout << endl;

	//* 백터 배열2
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

	// 오름차순 a index에 5번(4,3,2,1순으로) roof를 돌고 최고 높은 숫자를 a index에 넣음
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

	// 9단까지 row == 1
	// Print the table
	for (int row = 1, rowplus = 1; row < numRows; ++row)
	{
		// 2단부터 9단까지 col == 2
		// 세로 정렬
		for (int col = 2, colplus = 2; col < numCols; ++col)
		{
			cout << colplus << " x " << rowplus << " = " << product[rowplus][colplus] << "\t";
			colplus++;
		}
		rowplus++;

		// 가로 정렬
		//for (int col = 1; col < numCols; ++col)
		//{
		//	std::cout << row << " x " << col << " = " << product[row][col] << "\t";
		//}

		cout << '\n';
	}


	cout << "a값 : " << LLONG_MAX << " pa값 : " << arr[1] << endl;

	cout << mysum(3, 5, 7) << endl;
	cout << myaverage(10, 10, 10) << endl;
	cout << maxt(7.1233, 5.342434) << endl;

	int bb = 5 > 3 ? 77 : 88;
	cout << bb << "\n";
	cout << (5 > 3 ? 1 : 0) << '\n';
	//printf("%d %f \f" , maxt(5, 9), maxt(5.5, 9.9));
}

// vector 사용하기