// StackPractice1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 20208 서선호

#include <iostream>

using namespace std;

#define SIZE 10

typedef struct {
    char stackArr[SIZE];    // 스택 기억장소
    int topIndex;           // 스택 톱 인덱스 
    char name;          // 스택 이름 
}stack;

typedef stack* pstack;

void init(pstack ps, char c);
//스택에 문자 삽입함.
void push(pstack ps, char ch);
// 스택에서 문자를 제거함. ( 하지만 스택상우론 제거지만 우리에겐 출력이 됨. * 출력이 됨으로서 삭제가 됨. 
char pop(pstack ps);

int main()
{
    stack s1, s2;
    int i;

    init(&s1,'A');
    init(&s2, 'B');
    cout << "\n";
    push(&s1, 'd');
    push(&s1, 'a');
    push(&s1, 't');
    push(&s1, 'a');

    push(&s2, 's');
    push(&s2, 't');
    push(&s2, 'a');
    push(&s2, 'c');
    push(&s2, 'k');

    for (i = 0; i < 5; i++) {
        cout << "Pop s1 : " << pop(&s1) << "\n";
    }
    cout << "\n";
    for (i = 0; i < 5; i++) {
        cout << "Pop s2: " << pop(&s2) << "\n";
    }
    return 0;
}

void init(pstack ps, char c){
    ps->topIndex = 0;
    ps->name = c;
    cout << "Constructing stack" << ps->name << "\n";

}

void push(pstack ps, char ch) {
    if (ps->topIndex == SIZE) { // 스택이 가득찬 상태. 
        cout << "Stack" << ps->name << " is full \n";
        return;
    }

    ps->stackArr[ps->topIndex] = ch;
    ps->topIndex++;
}

char pop(pstack ps) { // Top이 0이면 return함.
    if (ps->topIndex == 0) {
        cout << "Stack " << ps->name << " is empty \n";
        return 0; // 스택이 빈 경우에는 NULL 반환함.
    }
    ps->topIndex--;

    return ps->stackArr[ps->topIndex];
}
