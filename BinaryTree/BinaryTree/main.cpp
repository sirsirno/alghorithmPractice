#include <iostream>
using namespace std;
#include "BinaryTree.h"
int main()
{
    BTreeNode* PreoderBt[3];
    BTreeNode* FinalBt[3];
    int countInput;
    int input1;
    int input2;
    int input3;
    int input4;
    int input5;
    int input6;


    cin >> countInput;
    cin >> input1;
    cin >> input2;
    cin >> input3;
    
            
    for (size_t i = 0; i < countInput; i++)
    {
        PreoderBt[i] = MakeBTreeNode();
    }
   
    SetData(PreoderBt[0], input1);
    SetData(PreoderBt[1], input2);
    SetData(PreoderBt[2], input3);
    MakeLeftSubTree(PreoderBt[0], PreoderBt[1]);
    MakeRightSubTree(PreoderBt[0], PreoderBt[2]);
    

   
 
    
   
   




    PreorderTraverse(PreoderBt[0]);
    cout << endl;
    
    MiddleorderTraverse(PreoderBt[0]);
    cout << endl;
    LastorderTraverse(PreoderBt[0]);
    cout << endl;


    DeleteBTreeNode(PreoderBt[0]);
    DeleteBTreeNode(PreoderBt[1]);
    DeleteBTreeNode(PreoderBt[2]);
   
    
}

