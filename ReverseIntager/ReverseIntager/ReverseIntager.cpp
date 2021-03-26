// ReverseIntager.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//20208 서선호

#include <iostream>


using namespace std;

int ReverseInt(int num[],int c) {
	
	if (c == 0) {
		cout << num[c] << "\n";
		cout << "출력이 완료되었습니다.\n";
		return 0;
	}
	else {
		cout << num[c] << "\n";
		return(ReverseInt(num, c - 1));
	}
	
}
int main()
{
	int c = 2;
	int num[3];
	for (int i = 0; i < 3; i++) {
		cout << "거꾸로 정수형 출력에 사용할 값을 '하나씩' 입력해주세요.\n";
		cout << "\t\t3자릿수로 입력해주세요.\n";
		cout << "\t예 : 1 치고 엔터\n";
		cout << "\t예 : 5 치고 엔터\n";
		cout << "\t예 : 4 치고 엔터\n";
		cout << "입력 시도 첫번째   ( " << i << "번째  / 3번째 중 ) \n";
		cin >> num[i];
		if (i == 2) {
			cout << "────────────────────────────────────────────────────────\n";
		}
	}
	ReverseInt(num,c);
}
