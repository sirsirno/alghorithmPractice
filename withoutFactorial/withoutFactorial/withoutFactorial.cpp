// withoutFactorial.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//20208 서선호
#include <iostream>

using namespace std;
int WithoutFacto(int in)
{
	int sum = 1;
	
	for (int i = in; i > 0; i--)
	{
		sum *= i;
	}
	return sum;
}
int main()
{
	int a = 0;
	cout << "재귀함수 없는 팩토리얼 함수의 사용을 위한 수를 입력하세욧.\n";
	cin >> a;
	cout << WithoutFacto(a);
}