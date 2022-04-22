#pragma once
#include"../DataStructures/Node.h"
template<typename T>
class Stack     // Inheirt from the Abstract class
{
private:
	Node <T>* TopHead;
	int size = 0;


public:

	Stack();
	bool isEmpty() const;
	//bool isFull();
	bool push(T& newEntry);
	bool pop(T& TopEntry);
	//bool peek(T& TopEntry) const;
	int StackSize();
	//void ChangeElement(int position, T value);
	//void Display();
	~Stack();
};


template<typename T>
int Stack <T> ::StackSize()
{
	return size;
}

template<typename T>

Stack <T> ::Stack()
{
	TopHead = nullptr;
}  // end default constructor

template<typename T>

bool Stack <T> ::isEmpty() const
{
	return (TopHead == nullptr);
}  // end 


template<typename T>
bool Stack <T> ::push(T& newEntry)
{
	Node<T>* newNode = new Node<T>(newEntry);
	newNode = TopHead->getNext();
	TopHead = newNode;
	size++;
	return true;
}  // end push

template<typename T>
bool Stack <T> ::pop(T& TopEntry)   // TopEntry is the element 
{
	Node <T>* tempPtr = TopHead;
	TopHead = TopHead->next;
	delete tempPtr;
	size--;            // As I have subtrac the value of top , the element will not be found again but , I have saved it
	return true;
}  // end pop

template <typename T>
Stack <T> :: ~Stack()
{};