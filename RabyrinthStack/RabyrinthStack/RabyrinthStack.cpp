//// RabyrinthStack.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//// 20208 서선호
#include <Windows.h>
#include <iostream>
using namespace std;
#define MAZESIZE_X 12
#define MAZESIZE_Y 22
#define EXIT_X 10  
#define EXIT_Y 8
typedef struct Position {
    int x;
    int y;
    int d;
}Position;
typedef struct Mtable {
    int x;
    int y;
}Mtable;
int Maze[MAZESIZE_X][MAZESIZE_Y] = {
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    1,0,1,1,1,1,1,0,0,0,0,1,0,1,1,1,1,1,0,0,1,1,1,1,1,0,
    1,0,1,1,1,1,1,0,1,1,0,1,0,1,1,1,1,1,0,0,1,1,1,1,1,0,
    1,0,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,
    1,0,1,0,0,1,0,1,0,1,1,1,1,0,0,1,0,1,0,1,0,0,1,0,1,0,
    1,0,1,1,1,1,0,1,0,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,
    1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    1,1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,1,0,1,0,1,0,1,
    1,1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,1,0,1,0,1,0,1,
    1,0,0,0
};

Mtable Move[4] = {
    {0,1},{1,0},{0,-1},{-1,0}
};
int Mark[MAZESIZE_X][MAZESIZE_Y];
int top;
Position Trace[(MAZESIZE_X - 2) * (MAZESIZE_Y - 2)];
void ShowMaze(Position);
void Push(Position);
void Pop(Position* P);
int main()
{
    bool isFound = false;
    int i, dir;
    //미로 입구 , 겁색 방향 초기화
    Position Now = { 1,1,0 };
    Position Next;
    Push(Now);

    while (!isFound && top > 0) {
        Pop(&Now);
        dir = Now.d;
        while (dir < 4) {
            Next.x = Now.x + Move[dir].x;
            Next.y = Now.y + Move[dir].y;
            if (Next.x == EXIT_X && Next.y == EXIT_Y) {
                Next.d = dir;
                Push(Next);
                isFound = true;
                break;
            }
            else if ((Maze[Next.x][Next.y] == 0 && (Mark[Next.x][Next.y] == 0))){
                Now.d = ++dir;
                    Push(Now);

                    Now.x = Next.x;
                    Now.y = Next.y;
                    dir = 0;
                    Mark[Next.x][Next.y] = 1;
            }
            else
            {
                dir++;
            }
            ShowMaze(Now);
        }
    }
    if (isFound == true) {
        for (i = 0; i < top; i++) {
            ShowMaze(Trace[i]);
        }
    }
    else {
        cout << "찾지 못했습니다.\n";
    }



    system("pause");
    return 0;
}
//미로 출력하는 함수임.
void ShowMaze(Position P) {
    int i,j;
    Sleep(50);
    system("cls");

    cout << "출구는" << EXIT_X << " , " << EXIT_Y << "입니다 \n";
    cout << "현재 좌표는 " << P.x << " " << P.y << " " << P.d << "입니다. \n";

    for (i = 0; i < MAZESIZE_X; i++) {
        for (j = 0; j < MAZESIZE_Y; j++) {
            if (Maze[i][j] == 1) {
                cout << "# ";
            }
            else if (P.x == i && P.y == j) {
                cout << "& ";
            }
            else cout << " ";
        }
        cout << "\n";
    }
}

void Push(Position P) {
    Trace[top].x = P.x;
    Trace[top].y = P.y;
    Trace[top].d = P.d;
}
void Pop(Position* P) {
    top--;
    P->x = Trace[top].x;
    P->y = Trace[top].y;
    P->d = Trace[top].d;
}
