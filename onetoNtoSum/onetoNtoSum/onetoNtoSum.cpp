//20208 서선호
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
