#include <iostream>
using namespace std;
#define MAXNUMBER 7
typedef struct node* nodePtr;
typedef struct node
{
	int data;
	nodePtr left, right;
	int level = 0;
	
}node;

int num = 0;

void Preorder(nodePtr ptr)
{
	if (ptr !=NULL)
	{
		cout << ptr->data << endl;
		Preorder(ptr->left);
		Preorder(ptr->right);
	}
}
int main()
{
	node nodes[MAXNUMBER+1];

	cin >> num;
	if (num < 1 || num> (2*2*2)- 1)
	{
		cout << "숫자 넘어갔듬";
		return 0;
	}
	nodes[0].data = num;
	//nodes[0].level = 0;
	//nodes[0].left->level = 1;
	//nodes[0].right->level = 1;
	//nodes[0].left->left->level = 2;
	//nodes[0].left->right->level = 2;
	//nodes[0].right->left->level = 2;
	//nodes[0].right->right->level = 2;

	for (int i = 1; i < sizeof(&nodes); i++)
	{
		nodes[i].data = rand();
		if (nodes[i].data == 0)
		{
			nodes[i].data = 1;
		}
		
	}


	for (int i = 0; i < MAXNUMBER; i++)
	{
		if (i % 2 == 0) nodes[i / 2].left = &nodes[i];
		else nodes[i / 2].right = &nodes[i];
	}

	return 0;
}