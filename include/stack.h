// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// utmatrix.h - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (21.04.2015)
//
// Верхнетреугольная матрица - реализация на основе шаблона вектора

#ifndef __TSTACK_H__
#define __TSTACK_H__

#define MAX_STACK_SIZE 10000;

using namespace std;

template <typename T>
class TStack
{
	T* pMem;
	int top = -1;
	int size;
public:
	TStack(int s)
	{
		if (s > MAX_STACK_SIZE)
			throw "too large size";

		size = s;
		pMem = new T[size];
	}
	~TStack()
	{
		delete[] pMem;
	}

	void Push(T el)
	{
		if (IsFull())
			throw "Stack is full";

		top++;
		pMem[top] = el;
	}

	T Pop(T el)
	{
		if (IsEmpty())
			throw "Stack is empty";

		top--;
		return pMem[top + 1];
	}

	bool IsFull() { return top == size; }
	bool IsEmpty() { return top == -1; }



};

#endif
