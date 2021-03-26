// Hanoyee.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 20208 서선호 

#include <iostream>

using namespace std;

int Hanoyee(int number , char first, char cross, char destination) {
	
	// 원반의 수, 꽃혀있는 원반의 위치. , 도착하는 위치, 지나가는 위치. 
	if (number == 1) {
		cout << "맨 밑 원반을 " << first << "에서" << destination << "으로 이동하였습니다~\n";
		return 0;
	}
	else {
		
		Hanoyee(number - 1, first, destination, cross); // A -> C로 맨 밑원반을 제외한 모든 원반들이 이동함. 
		cout << "원반 " <<number<<"개 를"<< first << "에서" << destination << "으로 이동하였습니다~\n";
		Hanoyee(number - 1, cross, first, destination);
	}
	
}
int main()
{
	// 원반의 수 , 각 원반의 이름. 의 매개변수.
	int num;
	cin >> num;
	Hanoyee(num, 'A', 'B', 'C');
}

