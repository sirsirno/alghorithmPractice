#include <iostream>
using namespace std;

int maze[21][21] = { 0, };

int start_x = 0, start_y = 1;
int exit_x, exit_y; // 미로가 끝나는 곳의 좌표.
int size_x, size_y; // 미로의 크기 ->cin을 이용하여 받을 예정임.
int block_side;  //블록 생성의 방향

int visit_x[1000], visit_y[1000]; //방문한 위치를 저장하는 스택
int short_path_x[400], short_path_y[400]; //최단 경로를 저장하기 위한 스택, 최대값 = 가로x세로
int sp = 0, success; //스택포인터, 성공확인 플래그

int min_path_cnt = 400; //임의의 가장 먼 경로길이


int find_route(int, int); //출구의 좌표를 인자로 받아 길을 찾는다.
void maze_init(void);  //미로를 만들기 위한 초기화
void maze_make_left(void); //출구부분에 대한 생성
void maze_complete(void); //나머지 부분에 대한 완료
void shortest_path(void); //최단 경로를 생성한다.
void display_maze(void); //미로를 출력한다.

void maze_complete(void)
{
    //나머지 y축에 대해 벽을 임의로 만든다.
    //이때 서쪽벽은 생성하지 아니한다.
    for (int y = 4; y <= size_y; y += 2) {
        for (int x = 2; x <= size_x; x += 2) {
            block_side = rand() % 3;
            switch (block_side) {
                //이미 막힌 블럭에 대해선 해상 세로줄을 건너뛴다.
                //건너 뜀으로서 출구에 대한 경로가 하나 이상 생성된다.
            case 0: //북쪽을 막는다.
             //if(maze[x-1][y] == 0) continue;
                maze[x - 1][y] = 0;
                break;

            case 1: //동쪽을 막는다.
             //if(maze[x][y+1] == 0) continue;
                maze[x][y + 1] = 0;
                break;

            case 2: //남쪽을 막는다.
             //if(maze[x+1][y] == 0) continue;
                maze[x + 1][y] = 0;
                break;
            default:
                break;
            }
        }
    }
}


void maze_make_left(void)
{
    //가장 좌측의 점중에서 임의의 방향으로 벽을 하나씩 만든다.
    int y = 2;
    for (int x = 2; x <= size_x; x += 2) {
        block_side = rand() % 4;
        switch (block_side) {
        case 0: //북쪽을 막는다.
            maze[x - 1][y] = 0;
            break;

        case 1: //동쪽을 막는다.
            maze[x][y + 1] = 0;
            break;

        case 2: //남쪽을 막는다.
            maze[x + 1][y] = 0;
            break;

        case 3: //서쪽을 막는다.
            maze[x][y - 1] = 0;
            break;
        default:
            break;
        }
    }
}

void maze_init(void)
{
    //미로 구조의 기본이 되는 십자구조를 생성한다.
    for (int x = 1; x <= size_x; x++) {
        for (int y = 1; y <= size_y; y++) {
            if (x % 2 != 0) maze[x][y] = 1; //짝수 위치에 대해
            if (y % 2 != 0) maze[x][y] = 1; //기본이 되는 벽을 생성한다.
        }
    }
}

void display_maze(void)
{
    for (int x = 0; x < size_x + 2; x++) {
        for (int y = 0; y < size_y + 2; y++) {
            if (maze[x][y] == 0) printf("+ ");   //0인 경우 벽
            else if (maze[x][y] == 1) printf("  "); //1인 경우 통로
            else if (maze[x][y] == 2) printf(". "); //2인 경우 최단 경로
        }
        puts("");
    }
    puts("");
}

int find_route(int curr_x, int curr_y)
{
    //지나간 위치를 스택에 저장한다.
    maze[curr_x][curr_y] = 0; //이동한 지역은 벽으로 변경한다.
    visit_x[sp] = curr_x;
    visit_y[sp] = curr_y;
    sp++;

    if (curr_x == exit_x && curr_y == exit_y) { //출구에 도달 했을 경우
        if (sp < min_path_cnt) { //스택 포인터, 즉 패스의 길이가 최단거리일 경우
            for (int i = 0; i < sp; i++) {
                short_path_x[i] = visit_x[i]; //이를 저장한다.
                short_path_y[i] = visit_y[i];
                min_path_cnt = sp; //최단 거리를 갱신한다.
            }
        }
        success = 1;
    }
    if (maze[curr_x][curr_y + 1] == 1) find_route(curr_x, curr_y + 1); //동쪽
    if (maze[curr_x + 1][curr_y] == 1) find_route(curr_x + 1, curr_y); //남쪽
    if (maze[curr_x][curr_y - 1] == 1) find_route(curr_x, curr_y - 1); //서쪽
    if (maze[curr_x - 1][curr_y] == 1) find_route(curr_x - 1, curr_y); //북쪽

    sp--; //스택에서 팝
    maze[curr_x][curr_y] = 1; //재탐색을 위해 다시 길로 변경한다.

    return success;
}

void shortest_path(void)
{
    for (int i = 0; i < min_path_cnt; i++) {
        maze[short_path_x[i]][short_path_y[i]] = 2;
    }
}

int main(void)
{
    while (1) {
        printf("Input ROW size (min 3, max 19) : ");
        cin>> size_x;
        if (size_x <= 19 && size_x >= 3)
            break;
        else
            printf("out of range\n");
    }
    while (1) {
        printf("Input COLUMN size (min 3, max 19) : ");
        cin >> size_y;
        if (size_y <= 19 && size_y >= 3)
            break;
        else
            printf("out of range\n");
    }
    exit_x = size_x + 1; //미로내부의 최우측
    exit_y = size_y;  //하단을 출구로 입력

    //미로를 생성한다.
    maze_init();
    maze_make_left();
    maze_complete();

    //출구와 입구를 설정한다.
    start_x = 0, start_y = 1;
    maze[start_x][start_y] = 1;
    maze[exit_x][exit_y] = 1;

    //세로가 짝수일경우 출구가 막히기 때문에 그 위칸을 통로로 지정한다.
    if (size_x % 2 == 0) maze[exit_x - 1][exit_y] = 1;

    display_maze();

    if (find_route(start_x, start_y) == 0)
        puts("can not find route");
    else
        puts("");

    shortest_path();
    display_maze();

    return 0;
}