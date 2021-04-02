// Input4soo.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 20208 서선호 

#include <iostream>

using namespace std;
int Soo4(int a) {
	
	if (a == 0) {
		return 0;
	}
	else {
		return a % 10 + Soo4(a / 10);
	}
	

}
int main()
{
	int b = 0;
	

	cin >> b;

	cout<< Soo4(b);
	
}
