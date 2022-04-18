#pragma once
#include"../DataStructures/Node.h"

template <typename T>
class PriorityQueue
{
private:
	Node <T>* Front, * Rear;
public:
	PriorityQueue();
	bool isEmpty() const;
	bool enqueue(const T& newEntry);
	bool dequeue(T& frntEntry);
	bool peek(T& frntEntry)  const;
	~PriorityQueue();
};

template <typename T>
PriorityQueue< T > ::PriorityQueue()
{
	Front = nullptr;
	Rear = nullptr;
}

template <typename T>
bool PriorityQueue< T > ::isEmpty() const
{
	return (Front == nullptr);
}

template <typename T>
bool PriorityQueue< T > ::enqueue(const T& newEntry)
{
	Node<T>* newNodePtr = new Node<T>(newEntry);
	if (isEmpty() || newNodePtr->getPriority() < Front->getPriority())
	{
		Front = newNodePtr;
	}
	else
	{
		Node<T>* Temp = new Node<T>(newEntry);
		while (Temp->getNext() != NULL && Temp->getPriority() < newNodePtr->getPriority())
		{
			Rear->setNext(newNodePtr);
		}
	}
	Rear = newNodePtr;
}

template <typename T>
bool PriorityQueue< T > ::dequeue(T& frntEntry)
{
	Node* TEMP;
	if (isEmpty())
		return false;
	else
	{
		Node<T>* nodeToDeletePtr = Front;
		frntEntry = Front->getdata();
		Front = Front->getNext();
		// Queue is not empty; remove front
		if (nodeToDeletePtr == Rear)	 // Special case: last node in the queue
			Rear = nullptr;
		// Free memory reserved for the dequeued node
		delete nodeToDeletePtr;
		return true;
	}
}

template <typename T>
bool PriorityQueue< T > ::peek(T& frntEntry)  const
{
	if (isEmpty())
		return false;

	frntEntry = Front->getdata();
	return true;
}

template <typename T>
PriorityQueue< T > :: ~PriorityQueue()
{}
