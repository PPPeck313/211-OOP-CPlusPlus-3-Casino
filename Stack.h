#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>

using namespace std;

template <class T>
class Stack
{
private:
	T* stack;
	int capacity;
	int size;
	bool isFull();
	bool isEmpty();
public:
	Stack();
	Stack(int cap);
	int getSize();
	bool push(T c);
	T pop();
	T peek();
	void display();
};

template <class T>
Stack<T>::Stack()
{
	capacity = 100;
	size = 0;
	stack = new T[capacity];
}

template <class T>
Stack<T>::Stack(int cap)
{
	capacity = cap;
	size = 0;
	stack = new T[capacity];
}

template <class T>
int Stack<T>::getSize()
{
	return size;
}

template <class T>
bool Stack<T>::push(T c)
{
	if (isFull())
	{
		cerr << "Stack is full!!!" << endl;
		return false;
	}

	stack[size] = c;
	size++;
	return true;
}

template <class T>
T Stack<T>::pop()
{
	if (isEmpty())
	{
		cerr << "Stack is empty!!!" << endl;
		return NULL;
	}

	size--;
	T temp =  stack[size];
	return temp;
}

template <class T>
T Stack<T>::peek()
{
	if (isEmpty())
	{
		cerr << "Stack is empty!!!" << endl;
		return NULL;
	}

	return stack[size-1];	
}

template <class T>
bool Stack<T>::isFull()
{
	return size == capacity;
}

template <class T>
bool Stack<T>::isEmpty()
{
	return size == 0;
}

template <class T>
void Stack<T>::display()
{
	for (int i = size-1; i >= 0; i--)
	{
		cout << *stack[i] << endl;
	}
}

#endif