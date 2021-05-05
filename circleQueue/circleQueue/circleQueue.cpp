// circleQueue.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//20208 서선호

#include <iostream>
using namespace std;
#define NEXT(index,QSIZE) ((index+1)%QSIZE) //큐에서 인덱스를 변경

typedef struct Queue
{
    int* buf;
    int qsize;
    int front;
    int rear;
    int count;
}Queue;

void InitQueue(Queue* queue, int qsize);
int IsFull(Queue* queue);
int IsEmpty(Queue* queue);
void Enqueue(Queue* queue, int data);
int Dequeue(Queue* queue);
int main()
{
    int size;
    int select = -1;

    Queue queue;
    cout << "큐의 크기를 입력하세요 :";
    cin >> size;

    InitQueue(&queue, size); // 큐 초기화 
    while (true)
    {
        cout << " 1. Enqueue 2. Dequeue\n";
        cout << ">>";
        cin >> select;

        switch (select)
                   {
        case 1:
            int value;
            cout << "input data :";
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

    
   
    return 0;
}
void InitQueue(Queue* queue, int qsize)
{
    queue->buf = new int[qsize];
    queue->qsize = qsize;
    queue->front = queue->rear = 0;
    queue->count = 0;
}
int IsFull(Queue* queue) {
    return queue->count == queue->qsize;
}
int IsEmpty(Queue* queue) {
    return queue->count == 0;
}
void Enqueue(Queue* queue, int data) {
    if (IsFull(queue))
    {
        cout << " 큐가 꽉차버림.";
            return;
    }
    queue->buf[queue->rear];
    queue->rear = NEXT(queue->rear, queue->qsize);
    queue->count++;
}
int Dequeue(Queue* queue) {
    int re = 0;
    if (IsEmpty(queue))
    {
        cout << "큐가 비어버림";
        return re;
    }
    re=queue->buf[queue->front];
    queue->front = NEXT(queue->front, queue->qsize);
    cout << "Dequeue : " << re;
    queue->count--;
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
