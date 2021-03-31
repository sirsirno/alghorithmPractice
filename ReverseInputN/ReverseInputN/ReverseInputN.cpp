// ReverseInputN.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 20208 서선호 

#include <iostream>

using namespace std; 

int Reverse(int i)
{
	if (i < 2) {
		return 1;
	}
	else {
		cout << i - 1;
		i = i - 1;
		return Reverse(i);
	}
	
}

int main()
{
	int c = 0;
	cin >> c;
	Reverse(c);



	return 0;
}


