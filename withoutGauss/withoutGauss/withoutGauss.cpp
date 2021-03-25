// withoutGauss.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 20208 서선호

#include <iostream>

using namespace std;

int WithoutGauss(int);
int main()
{
	int count = 0;

	cout << "V부터 1까지의 합을 구하는 알고리즘의 값을 입력하세요.\n";
	cin >> count;
	
	
	cout << WithoutGauss(count) << "\n";
	return 0;
}
int WithoutGauss(int v) {

	if (v <= 0)
		return 0;


	return v + WithoutGauss(v - 1);



}

