#include <iostream>
#include <algorithm>
#include "MH_Stack.h"

using namespace std;

void main()
{
	// ĳ���� ���� �׽�Ʈ
	MH_Stack<char> charStack(10);
	charStack.Push('A');
	cout<<*charStack.Top()<<endl;

	// ��Ʈ ���� �׽�Ʈ
	MH_Stack<int> intStack(2);
	
	for (int i = 0; i < 3; i++)
	{
		// ���� Ǯ �׽�Ʈ
		intStack.Push(i);
	}
	for (int i = 0; i < 3; i++)
	{
		// ���� ��Ƽ �׽�Ʈ
		intStack.Pop();
	}

	for (int i = 0; i < 2; i++)
	{
		intStack.Push(i);
	}
	
	// ���� ���� ������ �׽�Ʈ
	cout<<intStack.StackSize()<<endl;

	intStack.StackClear();
	 
	// Ŭ���� �� ������
	intStack.Pop();

	// ���� ���� ������ �׽�Ʈ
	cout<<intStack.StackSize()<<endl;		

	return;
} 