// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main()
{
    char value[14];
    int strSave = 0;
    char strYear[5] = {0};
    cout << "주민번호 판별 프로그램"; 
    cout << "입력하세요 ( - 붙이지 않고 입력하시오. )\n";
    cin >> value;
    strSave = strlen(value);
    strncpy(strYear, value, 2);
    int birth = atoi(strYear);
    int A = (value[0]-48) * 2;
    int B = (value[1] - 48) * 3;
    int C = (value[2] - 48) * 4;
    int D = (value[3] - 48) * 5;
    int E = (value[4] - 48) * 6;
    int F = (value[5] - 48) * 7;
    int G = (value[6] - 48) * 8;
    int H = (value[7] - 48) * 9;
    int I = (value[8] - 48) * 2;
    int J = (value[9] - 48) * 3;
    int K = (value[10] - 48) * 4;
    int L = (value[11] - 48) * 5;
    int M = (value[12] - 48);

    if (M == (11-((A+B+C+D+E+F+G+H+I+J+K+L)%11)%10)){
        
        cout << "이 주민등록번호는 유효합니다.\n";
        
    }
    else {
        cout << "이 주민등록번호는 유효하지 않습니다.\n";
        return 0;
    }
    if (value[6] <= 2)
    {
        cout << " 나이는 만으로 " << 2021 - birth - 1900 << "\n";
    }
    else
    cout << " 나이는 만으로 " << -1*(2021 - birth - 2000)<<"\n";

    if (value[6] == '2' || value[6] == '1') {
        cout << "당신은" << "19" << value[0]<<value[1]<<"년생 이시군요!?\n";
    }
    else {
        
        cout << "당신은" << "20" << value[0] << value[1] << "년생 이시군요!?\n";
    }

    if (value[6] % 2 == 1) {
        cout << "삐빅 남자입니다.\n";
    }
    else {
        cout << "삐빅 여자입니다.\n";
    }
    switch ( value[7])
    {
    case '0':
        switch (value[8])
        {
        case '9': cout << "부산 지역출신입니다.\n";
            break;
        default: cout << "서울 지역출신입니다.\n"; 
            break;
        }
        break;
    case '1':
        switch (value[8]) {
        case '0': cout << "부산 지역출신입니다.\n"; break;
        case '1': cout << "부산 지역출신입니다.\n"; break;
        case '2': cout << "부산 지역출신입니다.\n"; break;
        case '3': cout << "인천 지역출신입니다.\n"; break;
        case '4': cout << "인천 지역출신입니다.\n"; break;
        case '5': cout << "인천 지역출신입니다.\n"; break;
        case '6': cout << "경기도 주요 지역출신입니다.\n"; break;
        case '7': cout << "경기도 주요 지역출신입니다.\n"; break;
        case '8': cout << "경기도 주요 지역출신입니다.\n"; break;
        default: cout << "그 밖에 경기도 지역 출신입니다.\n"; break;
        }
        break;
    case '2':
        switch (value[8]) {
        case '0': cout << "그 밖에 경기도 지역 출신입니다.\n"; break;
        case '1': cout << "그 밖에 경기도 지역 출신입니다.\n"; break;
        case '2': cout << "그 밖에 경기도 지역 출신입니다.\n"; break;
        case '3': cout << "그 밖에 경기도 지역 출신입니다.\n"; break;
        case '4': cout << "그 밖에 경기도 지역 출신입니다.\n"; break;
        case '5': cout << "그 밖에 경기도 지역 출신입니다.\n"; break;
        default: cout << "강원도 지역 출신입니다.\n"; break;

        }
            break;
    case '3': 
        switch (value[8])
        {
        case '0': cout << "강원도 지역 출신입니다.\n"; break;
        case '1': cout << "강원도 지역 출신입니다.\n"; break;
        case '2': cout << "강원도 지역 출신입니다.\n"; break;
        case '3': cout << "강원도 지역 출신입니다.\n"; break;
        case '4': cout << "강원도 지역 출신입니다.\n"; break;
        default: cout << "충정북도 지역 출신입니다.\n"; break;
        }
        break;
    case '4':
        switch (value[8])
        {
        case '8': cout << "전라북도 지역 출신입니다.\n"; break;
        case '9': cout << "전라북도 지역 출신입니다.\n"; break;
        default: cout << "충청남도 지역 출신입니다.\n"; break;
        }
        break;
    case '5':
        switch (value[8])
        {
        case '0': cout << "전라북도 지역 출신입니다.\n"; break;
        case '1': cout << "전라북도 지역 출신입니다.\n"; break;
        case '2': cout << "전라북도 지역 출신입니다.\n"; break;
        case '3': cout << "전라북도 지역 출신입니다.\n"; break;
        case '4': cout << "전라북도 지역 출신입니다.\n"; break;
        default: cout << "전라남도 지역 출신입니다.\n"; break;
        }
        break;
    case '6':
        switch (value[8]) {
            case '7': cout << "경상도 지역 출신입니다.\n"; break;
            case '8': cout << "경상도 지역 출신입니다.\n"; break;
            case '9': cout << "경상도 지역 출신입니다.\n"; break;
            default: cout << "전라남도 지역 출신입니다.\n"; break;
        }
        break;
    default: cout << "경상도 지역 출신입니다.\n"; break;
    }
    return 0;
    //for문으로 지역번호 적기
}



