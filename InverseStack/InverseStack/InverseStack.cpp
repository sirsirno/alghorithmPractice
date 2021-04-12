// InverseStack.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 20208 서선호
#include <stack>
#include <iostream>
#include <string.h>
using namespace std;


int main()
{
    string s;
    
    cin >> s;
   

    stack<char> stk;

    stk.push(s.at(0));
    stk.push(s.at(1));
    stk.push(s.at(2));
    
    for (int i = 0; i < s.length(); i++) {
        cout << stk.top() << "\n";
        stk.pop();
    }

    return 0;
    
}

