//
// 20208 서선호 백승환의 전적인 도움을 받았습니다.
//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <cstring>


using namespace std;

struct oper {
    int p; // 연산자 우선순위
    string o; // 연산자
};

stack<int> num; // 숫자 스택
stack<oper> op; // 연산자 스택

void Calc() {
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
    string gurInput;
  /*  char ch[100];*/
    getline(cin, input);

    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' )
        {
            gurInput += " ";
        }

        gurInput += input[i];

        if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' )
        {
            gurInput += " ";
        }
    }

    int prior = 0; // 연산자 우선순위로 쓸 변수 
    /*strcpy(ch, input.c_str());*/
   /* for (int i = 0; i < input.size(); i++)
    {
        switch (ch[i])
        {
            case (int)('+') :
                ch[i - 1] = ' ';
            break;

        case (int)('-'):
            ch[i - 1] = ' ';
            break;

            case (int)('/') :
                ch[i - 1] = ' ';
            break;

            case (int)('*') :
                ch[i - 1] = ' ';
            break;

        default:
            break;
        }
    }*/

    stringstream ss(gurInput);
    string tok;

    while (ss >> tok) {
        // ( 는 무조건 연산자 스택에 push
        if (tok == "(") {
            op.push({ 0, tok });
        } // ) 가 나오면 ( 가 나올 때 까지 계산
        else if (tok == ")") {
            while (op.top().o != "(")
                Calc();
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
                Calc();
            // 스택에 연산자 push
            op.push({ prior, tok });
        }
        else {
            num.push(stoi(tok));
        }// 숫자만 걸러줌 
    }
    // 왜 공백이 숫ㄱ자로 될까
    // 남은 연산자 계산
    while (!op.empty())
        Calc();
 /*   cout << input;*/
    std::cout << num.top();

    return 0;
    //리스트
}