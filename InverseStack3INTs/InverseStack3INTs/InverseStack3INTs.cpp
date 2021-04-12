// InverseStack.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 20208 서선호
#include <stack>
#include <iostream>
#include <string.h>
using namespace std;


int main()
{
    string s1, s2, s3;

    cin >> s1;
    cin >> s2;
    cin >> s3;

    stack<string> stk;

    stk.push(s1);
    stk.push(s2);
    stk.push(s3);

    for (int i = 0; i < 3; i++) {
        cout << stk.top() << "\n";
        stk.pop();
    }

    return 0;

}

