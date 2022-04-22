#pragma once
#include "Node.h"

template <typename T>
class Queue
{
private:
	Node<T>* front;
	Node<T>* rear;
	int Size = 0;
public:
	Queue();
	bool isEmpty() const;
	bool enqueue(const T& newEntry);
	bool dequeue(T& frntEntry);
	bool peek(T& frntEntry)  const;
	int getSize();
	void Display() const;
	~Queue();
};

template <typename T>   //Constructor
Queue<T>::Queue()
{
	front = nullptr;
	rear = nullptr;
}

template <typename T>
int Queue<T>::getSize()
{
	return Size;
}

//Function: isEmpty Sees whether this queue is empty.
//Output: True if the queue is empty; otherwise false.

template <typename T>
bool Queue<T>::isEmpty() const
{
	return (front == nullptr);
}



//Function:enqueue Adds newEntry at the back of this queue.
//Output: True if the operation is successful; otherwise false.

template <typename T>
bool Queue<T>::enqueue(const T& newEntry)
{
	Node<T>* newNodePtr = new Node<T>(newEntry);
	// Insert the new node
	if (isEmpty())	//special case if this is the first node to insert
		front = newNodePtr; // The queue is empty
	else
		rear->setNext(newNodePtr); // The queue was not empty

	rear = newNodePtr; // New node is the last node now
	Size++;
	return true;
}



//Function: dequeue Removes the front of this queue. That is, removes the item that was added earliest.
//Output: True if the operation is successful; otherwise false.

template <typename T>
bool Queue<T>::dequeue(T& frntEntry)
{
	if (isEmpty())
		return false;

	Node<T>* nodeToDeletePtr = front;
	frntEntry = front->getdata();
	front = front->getNext();
	// Queue is not empty; remove front
	if (nodeToDeletePtr == rear)	 // Special case: last node in the queue
		rear = nullptr;

	// Free memory reserved for the dequeued node
	delete nodeToDeletePtr;
	Size--;
	return true;
}

//Function: peek copies the front of this queue to the passed param. The operation does not modify the queue.
//Output: The front of the queue.

template <typename T>
bool Queue<T>::peek(T& frntEntry) const
{
	if (isEmpty())
		return false;

	frntEntry = front->getdata();
	return true;

}

template <typename T>
void Queue <T> :: Display() const
{
	cout << getSize();
	cout << " Delivered Cargos:";
	Node<Cargo*>* p = front;
	Cargo* pCargo;
	TYP CargoType = pCargo->cargo_type;
	switch (CargoType)
	{
	case(NORMAL):
		while (p)
		{
			pCargo = p;
			cout << "[ " << pCargo->getCargoID();
			p = p->getNext();
			if (p != nullptr)
				cout << ",";
		}
		cout << " ]";
		break;
	case(VIP):
		while (p)
		{
			pCargo = p;
			cout << "{ " << pCargo->getCargoID();
			p = p->getNext();
			if (p != nullptr)
				cout << ",";
		}
		cout << " }";
		break;
	case(SPECIAL):
		while (p)
		{
			pCargo = p;
			cout << "( " << pCargo->getCargoID();
			p = p->getNext();
			if (p != nullptr)
				cout << ",";
		}
		cout << " )";
		break;
	default:
		break;
	}
	cout << "\n-------------------------------------------------------------------------------------------------\n";
}

template <typename T>   //Destructor
Queue<T>::~Queue()
{}