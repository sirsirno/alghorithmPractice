// googooDan.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 20208 서선호 

#include <iostream>
using namespace std;
int GogoDan(int i, int m) {
    
    if (i <= 9) {
        cout << i << " x " << m << " = " << i * m << "\n";

        if (m < 9) {
            GogoDan(i, m + 1); // 안쪽 for 
        }
        else {
            GogoDan(i + 1, 2); //바깥 for 느낌 
        }

    }
    return 0;

}
int main()
{
    int i;
    cout << "2을 누르면 시작합니다. ( 2단부터 시작함. , n * 1 은 넣지 않음, 1단도 넣지 않음. )\n ";
    cin >> i;
    if (i != 2) {
        cout << "종료.";
    }
    GogoDan(i, 2);
}

