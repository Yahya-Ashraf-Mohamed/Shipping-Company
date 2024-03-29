#pragma once
#include"../DataStructures/Node.h"
#include<iostream>
using namespace std;

template <typename T>
class PriorityQueue
{
private:
	Node <T>* Front;
	 int Size = 0;
public:
	Node<T>*Rear;
	PriorityQueue();
	bool isEmpty() const;
	bool enqueue(const T& newEntry);
	/*bool dequeue();*/
	bool dequeue(T& frntEntry);
	bool peek(T& frntEntry)  const;
	int getSize();
	bool Display() ;
	~PriorityQueue();
};


template<typename T>
bool PriorityQueue<T> ::  dequeue(T& frntEntry)
{
	//Node* TEMP;
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
		Size--;
		return true;
	}
}
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
		while (Temp->getNext() != nullptr && Temp->getPriority() < newNodePtr->getPriority())
		{
			Rear->setNext(newNodePtr);
		}
	}
	Rear = newNodePtr;
	Size++;
	return true;
}

//template <typename T>
//bool PriorityQueue< T > ::dequeue(T& frntEntry)
//{
//	Node* TEMP;
//	if (isEmpty())
//		return false;
//	else
//	{
//		Node<T>* nodeToDeletePtr = Front;
//		frntEntry = Front->getdata();
//		Front = Front->getNext();
//		// Queue is not empty; remove front
//		if (nodeToDeletePtr == Rear)	 // Special case: last node in the queue
//			Rear = nullptr;
//		// Free memory reserved for the dequeued node
//		delete nodeToDeletePtr;
//		Size--;
//		return true;
//	}
//}

template <typename T>
bool PriorityQueue< T > ::peek(T& frntEntry)  const
{
	if (isEmpty())
		return false;

	frntEntry = Front->getdata();
	return true;
}

template <typename T>
int PriorityQueue<T> ::getSize()
{
	return Size;
}

template <typename T>
bool PriorityQueue<T> ::Display()
{
	if (isEmpty() == true)
		return false;
	else
	{
		Node<Cargo*>* p = Front;
		Cargo* pCargo;		
		while (p)
		{
			pCargo = p->getdata();
			TYP CargoType = pCargo->getCargo_Type();
			if (CargoType == NORMAL)
			{
				cout << "[";
				cout << pCargo->getCargoID();
				cout << "] ";
			}

			if (CargoType == SPECIAL)
			{
				cout << "(";
				cout << pCargo->getCargoID();
				cout << ") ";
			}

			if (CargoType == VIP)
			{
				cout << "{";
				cout << pCargo->getCargoID();
				cout << "} ";
			}
			p = p->getNext();
		}
		//switch (CargoType)
		//{
		//case(NORMAL):
		//	while (p)
		//	{
		//		cout << "[" << pCargo->getCargoID();
		//		p = p->getNext();
		//		if (p != nullptr)
		//			cout << ",";
		//	}
		//	cout << "]";
		//	break;
		//case(VIP):
		//	while (p)
		//	{
		//		cout << "{" << pCargo->getCargoID();
		//		p = p->getNext();
		//		if (p != nullptr)
		//			cout << ",";
		//	}
		//	cout << "}";
		//	break;
		//case(SPECIAL):
		//	while (p)
		//	{
		//		cout << "(" << pCargo->getCargoID();
		//		p = p->getNext();
		//		if (p != nullptr)
		//			cout << ",";
		//	}
		//	cout << ")";
		//	break;
		//default:
		//	break;
		//}

		cout << "\n---------------------------------------------------------------------------------------------------\n";
		
		return true;
	}
}
template <typename T>
PriorityQueue< T > :: ~PriorityQueue()
{}