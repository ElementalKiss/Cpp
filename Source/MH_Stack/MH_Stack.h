/*
�ۼ��� : ������
�ۼ���: 2015.06.04
�ۼ�����
: ���� �����

*/

#pragma once
#include <iostream>
#define STACKMIN -1

// ����
template <typename T>
class MH_Stack
{
private:
	// Ź ����
	int m_topStack;
	// ���ú� �Ѱ�ġ
	int m_maxStack;
	// ���� ������
	T* m_stackPointer;

public:
	// ������
	MH_Stack(int count);
	// �Ҹ���
	~MH_Stack(void);

	// Ǫ��
	void Push(const T& pushValue);
	// ��
	T Pop(void);
	// ������ ���
	inline int StackSize(void) { return m_topStack; } 
	// ���� Ŭ����
	void StackClear(void);
};

// ������
template <typename T>
MH_Stack<T>::MH_Stack(int stackSize)
{
	// ž ������ -1�̸� ����ִ� ����
	m_topStack = STACKMIN;
	// ���� �ִ� ���� �����Ѵ�
	m_maxStack = stackSize;
	// ���� ������ �ʱ�ȭ
	m_stackPointer = new T[stackSize];
}

// �Ҹ���
template <typename T>
MH_Stack<T>::~MH_Stack(void)
{
	// ���� ����
	delete [] m_stackPointer;
}

// Ǫ��
template <typename T>
void MH_Stack<T>::Push(const T& tValue)
{
	// ������ ����á�ٸ� �����͸� ž ������ ������Ű�� �ʴ´�.
	if (m_topStack  == m_maxStack - 1)
	{
		cout<<"Stack is Full"<<endl;
		return;
	}

	// ���� ������ ������Ű�� �� �ֱ�
	m_topStack++;
	m_stackPointer[m_topStack] = tValue;
}

// ��
template <typename T>
T MH_Stack<T>::Pop(void)
{
	// ���ÿ��� ������ ���ٸ� -1(����)����
	if (m_topStack == STACKMIN)
	{
		cout<<"Stack is Empty"<<endl;
		return STACKMIN;
	}

	// �����ϰ� ���������� ����
	return m_stackPointer[m_topStack--];
}

// ���� Ŭ����
template <typename T>
void MH_Stack<T>::StackClear(void)
{
	// �Ŀ� ��
	while (this->m_topStack != STACKMIN) { this->Pop(); }
	cout<<"Stack Clear."<<endl;
	return ;
}