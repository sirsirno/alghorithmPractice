
//20208 서선호 
#include <iostream>

using namespace std;

int Fibonacci(int n) {

	if (n == 1 || n == 2) {
		return 1 ;// 첫째항 과 두번째 항은 1이므로 리턴 시켜준다.
	}
	else { 
		return(Fibonacci(n - 1) + Fibonacci(n - 2));  // 다음 항은 전의 두항의 합이다.
	}
	
	
	
}
int main()
{
	int i;
	int count;
	cout << "정해주신 카운트 값까지 피보나치 수열을 사용하겠습니다.";
	cin >> count;
	for (i = 1; i <= count; i++) {
		cout << Fibonacci(i) << "\n";
	}
		
	
	
	return 0;

}

