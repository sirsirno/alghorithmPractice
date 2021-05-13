﻿//
// 20208 서선호
#include <iostream>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

struct oper {
    int p; // 연산자 우선순위
    string o; // 연산자
};

stack<int> num; // 숫자 스택
stack<oper> op; // 연산자 스택

void calc() {
    int a, b, result;

    b = num.top();
    num.pop();
    a = num.top();
    num.pop();
    string oper = op.top().o;
    op.pop();

    if (oper == "*")
        result = a * b;
    else if (oper == "/")
        result = a / b;
    else if (oper == "+")
        result = a + b;
    else if (oper == "-")
        result = a - b;
    // 결과 값 스택에 다시 저장
    num.push(result);
}

int main() {
    string input; //= "15 + 32 * ( 1 - 8 ) / 2"; // -97
    getline(cin, input);
    int prior = 0; // 연산자 우선순위로 쓸 변수 

    stringstream ss(input);
    string tok;
    while (ss >> tok) {
        // ( 는 무조건 연산자 스택에 push
        if (tok == "(") {
            op.push({ 0, tok });
        } // ) 가 나오면 ( 가 나올 때 까지 계산
        else if (tok == ")") {
            while (op.top().o != "(")
                calc();
            op.pop();
        }
        else if (tok == "*" || tok == "/" || tok == "+" || tok == "-") {
            // 연산자 우선순위
            if (tok == "*")
                prior = 2;
            else if (tok == "/")
                prior = 2;
            else if (tok == "+")
                prior = 1;
            else if (tok == "-")
                prior = 1;

            // 연산자 우선 순위 낮은게 top으로 올 때까지 계산
            while (!op.empty() && prior <= op.top().p)
                calc();
            // 스택에 연산자 push
            op.push({ prior, tok });
        }
        else {
            num.push(stoi(tok));
        }// 숫자만 걸러줌 
    }
    // 남은 연산자 계산
    while (!op.empty())
        calc();

    std::cout << num.top();

    return 0;
}