#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <string>
#include <sstream>
#include <vector>
using namespace std;
#include "header.h"
int main()
{
	
	
	int x = 3;
	string str0 = "1 2 3";
	istringstream ss(str0);
	string stringBuffer;
	while (getline(ss, stringBuffer, ' ' ))
	{
		cout << stringBuffer << endl;
	}
	for (size_t i = 0; i < x; i++)
	{
		MakeBTreeNode();
	}

	//cin >> x;

    

}

