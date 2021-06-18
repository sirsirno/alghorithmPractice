//20208 ¼­¼±È£
#pragma once
typedef int BTData;
struct BTreeNode {
    BTData data;
    struct BTreeNode* left;
    struct BTreeNode* right;
};
BTreeNode* MakeBTreeNode();
void DeleteBTreeNode(BTreeNode* bt);
BTData GetData(BTreeNode* bt);
void SetData(BTreeNode* bt, BTData data);
BTreeNode* GetLeftSubTree(BTreeNode* bt);
BTreeNode* GetRightSubTree(BTreeNode* bt);
void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);

void PreorderTraverse(BTreeNode* bt);
void MiddleorderTraverse(BTreeNode* bt);
void LastorderTraverse(BTreeNode* bt);