
//20208 서선호 
#include <iostream>
using namespace std;


void Print(char arr[])
{
    int counter, length = 0;
    while (arr[length] != 0) length++;

    for (counter = length - 1; counter >= 0; counter--) {
        cout << arr[counter];
    }
    cout << "\n";
}

int main()
{
    
    char word[3][10] = { 0, };
    for (int counter = 0; counter < 3; counter++)
    {
        cout << "문자열을 입력해주십시오 최대 10글자." <<"( "<< counter << "/ 3 )" << "\n";
        cin >> word[counter];
    }
    Print(word[0]);
    Print(word[1]);
    Print(word[2]);
}
