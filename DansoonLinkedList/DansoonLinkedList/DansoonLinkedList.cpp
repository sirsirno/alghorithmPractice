// DansoonLinkedList.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 20208 서선호 

#include <iostream>
using namespace std;

typedef struct linked {
    int data;
    struct linked* next;
}node;
node* head = NULL;
node* tail = NULL;

void Init();
void Add(node* ptr);
void PrintList(node* ptr);
void Modify(node* ptr);
void AddData(node* ptr);
void Delete(node* ptr);
int main()
{
    int menu = 0;
    Init();
    while (true)
    {
        cout << "1. 입력 2.출력 3. 수정 4. 삽입 5. 삭제 6. 종료 \n";
        cout << "Input menu :";
        cin >> menu;

        switch (menu)
        {
        case 1:
            Add(tail);
            break;
            case 2:
                PrintList(head);
                break;
            case 3:
                Modify(head);
                break;
            case 4:
                AddData(head);
                break;
            case 5:
                Delete(head);
                break;
            case 6:
                break;
        default:
            cout << "select menu error..\n";
            break;
        }
        if (menu == 6) {
            break;
        }
    }
    return 0;
}

void Init() {
    head = new node;
    head->data = 0;
    head->next = NULL;
    tail = head;
    return;
}
void Add(node* ptr) {
    node* newnode = new node;
    int num = 0;
    cout << " Input Manager :";
    cin >> num;
    newnode->data = num;
    newnode->next = NULL;
    ptr->next = newnode;
    tail = newnode; 
    return;
}
void PrintList(node* ptr) {
    node* view = ptr->next;
    while (view!=NULL)
    {
        cout << view->data;
        cout << "\n";
        view = view -> next;
    }
    cout << "\n";
    return;
}
void Modify(node* ptr) {
    int index = 0;
    int num = 0;

    cout << " Input Modify Index : ";
    cin >> index;
    cout << " Input Modify Data : ";
    cin >> num;
    for (int i = 0; i < index; i++)
    {
        ptr = ptr->next;
    }
    ptr->data = num;
    return;
}
void AddData(node* ptr) {
    node* newnode = new node;
    int index = 0, num = 0;
    cout << "Input AddData Index :";
    cin >> index;
    cout << "Input Data :";
    cin >> num;

    for (int i = 0; i < index; i++)
    {
        ptr = ptr->next;
        newnode->data = num;
        newnode->next = NULL;
        if (ptr->next == NULL) {
            ptr->next = newnode;
            tail = newnode;
        }
        else {
            newnode->next = ptr->next;
            ptr->next = newnode;
        }
        return;
    }
    
}
void Delete(node* ptr) {
    node* temp = 0;
    int index;
    if (head ==tail)
    {
        cout << " Not Found Data \n";
        return;
    }
    cout << " Input Delete Index :";
    cin >> index;

    for (int i = 0; i < index-1; i++)
    {
        ptr = ptr->next;
    }
    temp = ptr->next;
    if (temp->next ==NULL)
    {
        ptr->next = NULL;
        tail = ptr;
    }
    else {
        ptr->next = temp->next;
    }
    delete(temp);
    return;
}

