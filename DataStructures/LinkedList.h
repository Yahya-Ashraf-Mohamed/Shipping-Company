#pragma once
#ifndef _LINKEDLIST
#define _LINKEDLIST

#include "Node.h"
#include "..\Cargo\Cargo.h"
#include <iostream>
using namespace std;

//template <typename T>
class LinkedList
{
private:
	Node<Cargo*>* Head;
	Node<Cargo*>* Tail;

public:


	LinkedList()
	{
		Head = nullptr;

	}


	//List is being desturcted ==> delete all items in the list
	~LinkedList()
	{
		DeleteAll();
	}	

	//need to be further editted
	void PrintList()	const 
	{
		cout << "\nprinting list contents:\n\n";
		Node<Cargo*>* p = Head;
		Cargo* pCargo;
		while (p)
		{
			pCargo = p->getdata();
			cout << "[ " << pCargo->getCargoID() << " ]";
			cout << "--->";
			p = p->getNext();
		}
		cout << "*\n";
	}

	// Remove first node from list and return pointer to the Cargo removed in x
	void dequeue(Cargo*& x)
	{

		if (Head)
		{

			Node<Cargo*>* temp = Head;
			Head = Head->getNext();

			//if tail points on the same address as the head set it to null before deleting or removing Head
			if (Tail == Head)
				Tail = nullptr;

			x = temp->getdata();

		}
	}

	void enqueue ( Cargo* data)
	{
		//create a new node 
		Node<Cargo*>* newNode = new Node<Cargo*>(data);

		//add the newNode at the end of the linked list
		if (Head)
		{
			Tail->setNext(newNode);
			Tail = Tail->getNext();
		}

		//otherwise it is an empty list
		else
		{
			Head = newNode;
			Tail = Head;
		}
	}


	// Take Cargo id, Remove Cargo, return pointer to that Cargo
	Cargo* RemoveNode(int id)
	{
		Node<Cargo*>* prev = nullptr;
		Node<Cargo*>* current = binarySearch(id, prev);

		//if item is found 
		if (current)
		{
			//if the item I want to delete is Head
			if (current == Head)
			{
				Head = Head->getNext();

				//if tail points on the same address as the head set it to null before deleting or removing Head
				if (Tail == Head)
					Tail = nullptr;

				return current->getdata();
			}

			else
			{
				prev->setNext(current->getNext());
				return current->getdata();
			}

		}
		//item is not found
		else
			return nullptr ;
	}
	
	//Deletes all nodes of the list.
	void DeleteAll()
	{
		Node<Cargo*>* P = Head;
		Cargo* pCargo;
		while (Head)
		{
			P = Head->getNext();
			pCargo = Head->getdata();
			delete pCargo;
			delete Head;
			Head = P;
		}
		Head = nullptr;
		Tail = nullptr;
	}


private:

	Node<Cargo*>* middle(Node<Cargo*>* start, Node<Cargo*>* last, Node<Cargo*>*& prev)
		{

			if (start == nullptr)
				return nullptr;
			if (!prev)
				prev = start;

			Node<Cargo*>* slow = start;
			Node<Cargo*>* fast = start->getNext();

			while (fast != last)
			{
				fast = fast->getNext();
				if (fast != last)
				{
					if (prev != slow)
						prev = prev->getNext();

					slow = slow->getNext();
					fast = fast->getNext();
				}
			}
			return slow;
		}

	Node<Cargo*>* binarySearch(int id, Node<Cargo*>*& prev)
		{
			Node<Cargo*>* start = Head;
			Node<Cargo*>* last = nullptr;

			Node<Cargo*>* temp;
			Cargo* pCargo;

			do
			{
				if (prev)//handling odd case 
				{
					temp = prev->getNext();
					pCargo = temp->getdata();

					if (pCargo->getCargoID() == id)
						return prev->getNext();
				}

				// Find middle
				Node<Cargo*>* mid = middle(start, last, prev);
				pCargo = mid->getdata();

				// If middle is empty
				if (mid == nullptr)
					return nullptr;

				// If value is present at middle
				if (pCargo->getCargoID() == id)
					return mid;

				// If value is more than mid
				else if (pCargo->getCargoID() < id)
				{
					start = mid->getNext();
					prev = mid;
				}

				// If the value is less than mid.
				else
					last = mid;

			} while (last == nullptr ||
				last != start);

			// value not present
			return nullptr;
		}

//============================================= ignore ==============================================
	//
	//	// function to find out middle element to conduct binary search
	//Node<Cargo*>* middle(Node<Cargo*>* start, Node<Cargo*>* last)
	//{
	//	if (start == nullptr)
	//		return nullptr;
	//
	//	Node<Cargo*>* slow = start;
	//	Node<Cargo*>* fast = start->getNext();
	//
	//	while (fast != last)
	//	{
	//		fast = fast->getNext();
	//		if (fast != last)
	//		{
	//			slow = slow->getNext();
	//			fast = fast->getNext();
	//		}
	//	}
	//
	//	return slow;
	//}
	//
	//
	//// Binary Search on linked list
	//Node<Cargo*>* binarySearch(int id)
	//{
	//	Node<Cargo*>* start = Head;
	//	Node<Cargo*>* last = nullptr;
	//	Cargo* pCargo;
	//
	//	do
	//	{
	//		// Find middle
	//		Node<Cargo*>* mid = middle(start, last);
	//		pCargo = mid->getdata();
	//
	//		// If middle is empty
	//		if (mid == nullptr)
	//			return nullptr;
	//
	//		// If value is present at middle
	//		if (pCargo->get_cargo_id() == id)
	//			return mid;
	//
	//		// If value is more than mid
	//		else if (pCargo->get_cargo_id() < id)
	//			start = mid->getNext();
	//
	//		// If the value is less than mid.
	//		else
	//			last = mid;
	//
	//	} while (last == nullptr ||
	//		last != start);
	//
	//	// value not present
	//	return nullptr;
	//}
	// 
//===================================================================================================
	
	
};

#endif