//
//20208 서선호 

#include <iostream>
#include <stack>
using namespace std;

int main() {
	stack<int> s;
	int insert = 0;
	int input = 0;

	cin >> insert;

	for (int i = 0; i < insert; i++) {
		cin >> input;
		s.push(input);
	}

	for (int i = 0; i < insert; i++) {
		cout << s.top() << " ";
		s.pop();
	}
}

