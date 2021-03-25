// gaussSolve.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//20208 서선호 

#include <iostream>

using namespace std;

int Gauss(int i) {

	if (i == 0) {
		return 1;
	}
	else {
		i = ((1 + i) * i) / 2;
		return i;
	}
		
	
}
		
int main()
{
	int i;
	cout << "가우스 계산법을 이용할 값을 입력해주십시오. \n";
	cin >> i;
	cout << "가우스 계산법을 이용한 입력하신 값은. " << Gauss(i) << " 입니다. \n";
	return 0;
}
