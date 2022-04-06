#pragma once
#ifndef _QUEUE_
#define _QUEUE_

#include "Node.h"

template <typename T>
class Queue 
{
private:
	Node<T>* front;
	Node<T>* rear;
public:
	Queue();
	bool isEmpty() const;
	bool enqueue(const T& newEntry);
	bool dequeue(T& frntEntry);
	bool peek(T& frntEntry)  const;
	~Queue();
};
#endif