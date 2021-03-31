// InputABS.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 20208 서선호 

#include <iostream>

using namespace std;


int Compare(int max, int num[],int p) {
	if (p == 5) {
		return 0;
	}
	if (max <= num[p]) {
		cout << num[p];	
	}
	return (Compare(max, (num + 1), (p + 1)));
	
}

int main()
{
	int p = 0;
	int num[5] = { 0, };
	int max = 0;
	for (int i = 0; i < 5; i++) {

		cin >> num[i];
		if (max < num[i])	
			max = num[i];
	}
	Compare(max, num,p);
	
}

