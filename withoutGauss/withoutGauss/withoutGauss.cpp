// withoutGauss.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 20208 서선호

#include <iostream>

using namespace std;

int WithoutGauss(int);
int main()
{
	int count = 100;

	
	
	cout << WithoutGauss(100) << "\n";
	return 0;
}
int WithoutGauss(int v) {

	if (v <= 0)
		return 0;


	return v + WithoutGauss(v - 1);



}

