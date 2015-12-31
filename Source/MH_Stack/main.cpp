#include <iostream>
#include <algorithm>
#include "MH_Stack.h"

using namespace std;

void main()
{
	// 캐릭터 스택 테스트
	MH_Stack<char> charStack(10);
	charStack.Push('A');
	cout<<*charStack.Top()<<endl;

	// 인트 스택 테스트
	MH_Stack<int> intStack(2);
	
	for (int i = 0; i < 3; i++)
	{
		// 스택 풀 테스트
		intStack.Push(i);
	}
	for (int i = 0; i < 3; i++)
	{
		// 스택 엠티 테스트
		intStack.Pop();
	}

	for (int i = 0; i < 2; i++)
	{
		intStack.Push(i);
	}
	
	// 현재 스택 사이즈 테스트
	cout<<intStack.StackSize()<<endl;

	intStack.StackClear();
	 
	// 클리어 후 빼보기
	intStack.Pop();

	// 현재 스택 사이즈 테스트
	cout<<intStack.StackSize()<<endl;		

	return;
} 