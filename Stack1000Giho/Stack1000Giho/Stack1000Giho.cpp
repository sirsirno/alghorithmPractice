// Stack1000Giho.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 20208 서선호

#include <iostream>
#include <stack>
#define SIZE 10

char c_arr[SIZE];
using namespace std;
stack<char> s;
void PrintStack() {
    for (int i = 0; i < SIZE; i++)
    {
        cout << s.top()<<"\n";
        s.pop();
    }
   
}
int main()
{
    char strNum[SIZE];
    char* strNumArr;
    cin >> strNum;
    strNumArr = strNum;
    for (int i = 0; i < SIZE; i++)
    {
        if (i == 0) {
            s.push(*strNumArr);
            //걍 숫자 출력 1
        }
        if (i % 3 == 0 && i>0) {
            s.push(*strNumArr);
            s.push(',');
            //천단위 구분기호
        }
        else {
            s.push(*strNumArr);
            //걍 숫자출력 2
        }
        *strNumArr++; //->배열의 다음주소로 ㄱㄱ
    }
    PrintStack();
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
