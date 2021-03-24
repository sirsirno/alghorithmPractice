// 20208 서선호
#include <iostream>

using namespace std;

int main() {
	int arr[10][10] = { 0, };
	int value1, value2;

	for (value1 = 0; value1 < 10; value1++) {
		arr[value1][0] = 1;
	}
	for (value1 = 0; value1 < 10; value1++) {
		for (value2 = 0; value2 < 10; value2++) {
			if (value2 > 0 && value1 > 0) {
				arr[value1][value2] = arr[value1 - 1][value2] + arr[value1 - 1][value2 - 1];
				if (arr[value1][value2] > 0)
					cout << arr[value1][value2] << " ";
			}
	
		}
		cout << endl;
}
	return 0;
}
