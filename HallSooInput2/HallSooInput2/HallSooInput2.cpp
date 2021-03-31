// HallSooInput2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 20208 서선호 

#include <iostream>

using namespace std;
int Hallsoo(int start, int end) {

    if (start == end) {
        return 0;
    }
    if ( end % 2 ==1  && start % 2 ==1) {
        
        cout << start << "\n";
        return Hallsoo(start + 2, end);
       
    }
    else if (end % 2 == 1) {
        return Hallsoo(start + 1, end);
    }
    else {
        return Hallsoo(start, end + 1);
    }
     
    
}
int main()
{
    int a = 0, b = 0;
    cin >> a;
    cin >> b;
    Hallsoo(a, b);
    return 0;
}

