#pragma once
#include"../DataStructures/Node.h"
template<typename T>
class Stack     // Inheirt from the Abstract class
{
private:
	T* items;		// Array of stack items
	int top;                   // Index to top of stack
	const int Size;      // size of stack is constant in this cas because we created it using array

public:

	Stack(int MaxSize);
	bool isEmpty() const;
	bool isFull();
	bool push(const T& newEntry);
	bool pop(T& TopEntry);
	bool peek(T& TopEntry) const;
	int StackCount();
	void ChangeElement(int position, T value);
	//void Display();
	~Stack();
};

template<typename T>
int Stack <T> ::StackCount()
{
	return (top + 1);
}

template<typename T>
bool Stack <T> ::peek(T& TopEntry) const
{
	if (isEmpty()) return false;

	TopEntry = items[top];
	return true;
}  // end peek

template<typename T>

Stack <T> ::Stack(int MaxSize)
{
	items = new T[MaxSize];
	top = -1;
}  // end default constructor

template<typename T>

bool Stack <T> ::isEmpty() const
{
	return top == -1;
}  // end 

template<typename T>
bool Stack <T> ::isFull()
{
	if (top == Size)
		return true;
	else
		return false;
}

template<typename T>
bool Stack <T> ::push(const T& newEntry)
{
	if (top == Size - 1) return false;	//Stack is FULL

	top++;
	items[top] = newEntry;
	return true;
}  // end push

template<typename T>
bool Stack <T> ::pop(T& TopEntry)
{
	if (isEmpty()) return false;

	TopEntry = items[top];
	top--;            // As I have subtrac the value of top , the element will not be found again but , I have saved it
	return true;
}  // end pop

template<typename T>
void Stack <T> ::ChangeElement(int position, T value)
{
	items[position] = value;
}


//template<typename T>
//void Stack <T> :: Display()
//{
//	cout << "All stack elemnts are ";
//	for (int i = 4; i >= 0; i--)
//		cout << items[i] << endl;
//}

template <typename T>
Stack <T> :: ~Stack()
{};