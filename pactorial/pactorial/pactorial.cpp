
//20208 서선호
#include <iostream>

using namespace std;




int Factorial(int i) 
{
	if (i == 0) {
			
		return 1;
	}
	else {
		return(i * Factorial(i-1));
	}
	
}

int main() {

	int i;
	cout << "팩토리얼 함수의 입력 값을 써주세욧. " << "\n";
	cin >> i;
	cout << "팩트로얼 함수의 1부터 " << i << " 입력해 주신 값까지의 곱은 " << Factorial(i) << "입니다.\n";
}