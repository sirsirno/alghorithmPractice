// CreateQueue.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 20208 서선호

#include <iostream>
using namespace std;
#define QUEUE_SIZE 5
#define NEXT(index) ((index+1)%QUEUE_SIZE)

typedef struct Queue {
    int* buf; //저장 버퍼 
    int front; // 가장 오래전ㅇ 보관한거 있는 인덱스
    int near; // 보관할 인덱스
    int qsize;
    
}Queue;
void InitQueue(Queue* queue); // 큐 초기화 
int IsFull(Queue* queue); // 큐가 다 찻는지 확인
int IsEmpty(Queue* queue); // 큐가 비었는지 확인
void Enqueue(Queue* queue, int data); //큐에 보관하는 함수.
int Dequeue(Queue* queue); //큐에서 꺼냄

int main()
{
    int select = -1;
    Queue queue;
    InitQueue(&queue);//큐 초기화
    while (true)
    {
        cout << "1.Enqueue 2.Dequeue\n";
        cout << ">>";
        cin >> select;
        switch (select)
        {
        case 1: 
            int value;
            cout << " Input data: ";
            cin >> value;
            Enqueue(&queue, value);
            break;
            case 2:
                Dequeue(&queue);
                break;
        default:
            cout << "예외!";
            break;
        }
        cout << "\n";
    }
    for (int i = 0; i <=5; i++)
    {
        cout << i << "입력\n";
        Enqueue(&queue, i);
    }
    cout << "\n";
    return 0;
}
void InitQueue(Queue* queue, int qSize) {
   
    queue->front = queue->near = 0; //fronmt와 near를 0우ㅡ로 서설정
   
}

int IsFull(Queue* queue) {
    return NEXT(queue->near) == queue->front; 
    //원형큐에서 꽉 찻는지 체크할 숭맀게  near 다음공간은 빈 상태를 유지
    // 다음 near가 front와 같으면 꽉찬거임.

}
int IsEmpty(Queue* queue) {
    return queue->front == queue->near; 
    //froint과 near가 같으면 ㅂㄴ 상태.
}
void Enqueue(Queue* queue, int data) {
    if (IsFull(queue))// 큐가 꽉 찻을때
    {
        cout << "큐가 꽉찻음.\n";
        return;
    }
    queue->buf[queue->near] = data;//near 인덱스에 자료 보관
    queue->near = NEXT(queue->near);// near를 다음위치로 설정
    
}
int Dequeue(Queue* queue) {
    int re = 0;
    if (IsEmpty(queue)) //큐가 비었을 때
    {
        cout << "큐가 비었음.\n";
        return re;
    }
    re = queue->buf[queue->front]; // front 인덱스에 보관할 값을 re에 설정함.
    queue->front = NEXT(queue->front, queue->qsize);// front를 다음위치로 설정.
    cout << "dequeue :" << re;
    return re;
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
