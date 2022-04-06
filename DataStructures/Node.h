#pragma once
#ifndef _NODE
#define _NODE
template <typename T>
class Node
{
private:
	T data; // A data item
	Node<T>* next; // Pointer to next node
public:
	Node();
	Node(const T& DATA);
	Node(const T& DATA, Node<T>* NEXT);
	void setdata(const T& DATA);
	void setNext(Node<T>* NEXT);
	T getdata() const;
	Node<T>* getNext() const;
}; // end Node
#endif
