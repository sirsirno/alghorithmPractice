// BinaryTree.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
// 20208 서선호

#include <iostream>
#include "header.h"
using namespace std;
// (1) 자료형의 정의



// (2) 트리구조를 만들기 위해 필요한 기능의 구현
// (2-1) 선언된 자료형으로 변수 생성
BTreeNode* MakeBTreeNode()
{
    BTreeNode* nd = new BTreeNode;

    nd->left = NULL;
    nd->right = NULL;
    return nd;
}
//(2-2) 메모리 삭제 함수 생성
void DeleteBTreeNode(BTreeNode* bt)
{
    delete bt;
}
BTData GetData(BTreeNode* bt) {
    return bt->data;
}
// (3) 변수에 값 설정
void SetData(BTreeNode* bt, BTData data)
{
    bt->data = data;
}
BTreeNode* GetLeftSubTree(BTreeNode* bt) {
    return bt->left;
}
BTreeNode* GetRightSubTree(BTreeNode* bt) {
    return bt->right;
}
// (4) 이진트리의 관계설정
void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub)
{
    if (main->left != NULL)
    {
        delete main->left;
    }
    main->left = sub;
}
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub)
{
    if (main->right != NULL)
    {
        delete main->right;
    }
    main->right = sub;
}


void PreorderTraverse(BTreeNode* bt) {
    if (bt == NULL)
    {
        return;
    }
    cout << bt->data << endl;

    PreorderTraverse(bt->left);
    PreorderTraverse(bt->right);
}

void MiddleorderTraverse(BTreeNode* bt) {
    if (bt == NULL)
    {
        return;
    }

    MiddleorderTraverse(bt->left);
    cout << bt->data << endl;
    MiddleorderTraverse(bt->right);
}

void LastorderTraverse(BTreeNode* bt) {
    if (bt == NULL)
    {
        return;
    }


    LastorderTraverse(bt->left);
    LastorderTraverse(bt->right);
    cout << bt->data << endl;
}