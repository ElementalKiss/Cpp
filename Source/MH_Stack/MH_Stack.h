/*
작성자 : 조민혁
작성일: 2015.06.04
작성내용
: 스택 만들기

*/

#pragma once
#include <iostream>
#define STACKMIN -1

// 스택
template <typename T>
class MH_Stack
{
private:
	// 탁 스택
	int m_topStack;
	// 스택별 한계치
	int m_maxStack;
	// 스택 포인터
	T* m_stackPointer;

public:
	// 생성자
	MH_Stack(int count);
	// 소멸자
	~MH_Stack();

	// 푸쉬
	void Push(const T& pushValue);
	// 팝
	void Pop();
	// Top
	T* Top();

	// 사이즈 얻기
	inline int StackSize() { return m_topStack; } 
	// 스택 클리어
	void StackClear();
};

// 생성자
template <typename T>
MH_Stack<T>::MH_Stack(int stackSize)
{
	// 탑 스택이 -1이면 비어있는 상태
	m_topStack = STACKMIN;
	// 스택 최대 값을 저장한다
	m_maxStack = stackSize;
	// 스택 포인터 초기화
	m_stackPointer = new T[stackSize];
}

// 소멸자
template <typename T>
MH_Stack<T>::~MH_Stack()
{
	// 스택 삭제
	delete [] m_stackPointer;
}

// 푸쉬
template <typename T>
void MH_Stack<T>::Push(const T& tValue)
{
	// 스택이 가득찼다면 포인터를 탑 스택을 증가시키지 않는다.
	if (m_topStack  == m_maxStack - 1)
	{
		cout<<"Stack is Full"<<endl;
		return;
	}

	// 스택 포인터 증가시키고 값 넣기
	m_topStack++;
	m_stackPointer[m_topStack] = tValue;
}

// 팝
template <typename T>
void MH_Stack<T>::Pop()
{
	// 스택에서 뺄것이 없다면 -1(에러)리턴
	if (m_topStack == STACKMIN)
	{
		cout<<"Stack is Empty"<<endl;
		return;
	}

	m_stackPointer[m_topStack--] = 0;

	return;
}

// Top
template <typename T>
T* MH_Stack<T>::Top()
{
	if (m_topStack == STACKMIN)
	{
		return nullptr;
	}

	return &m_stackPointer[m_topStack];
}

// 스택 클리어
template <typename T>
void MH_Stack<T>::StackClear()
{
	// 파워 팝
	while (this->m_topStack != STACKMIN) { this->Pop(); }
	cout<<"Stack Clear."<<endl;
	return ;
}