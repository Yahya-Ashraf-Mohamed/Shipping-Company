#pragma once
template <typename T>
class Node
{
private:
	T data; // A data item
	double Priority; //  It shows the priority in the Priority Queue only
	Node<T>* next; // Pointer to next node
public:
	Node();
	Node(const T& DATA);
	Node(const T& DATA, Node<T>* NEXT);
	void setdata(const T& DATA);
	void setNext(Node<T>* NEXT);
	T getdata() const;
	Node<T>* getNext() const;
	double getPriority(T* truck) const;
	void operator= (const T& DATA);
}; // end Node

template <typename T>
void Node<T> :: operator= (const T& DATA)
{
	data = DATA;
}

template < typename T>
Node<T>::Node()
{
	next = nullptr;
}

template < typename T>
Node<T>::Node(const T& DATA)
{
	/*data = DATA;*/
	operator= (DATA);
	next = nullptr;
}

template < typename T>
Node<T>::Node(const T& DATA, Node<T>* NEXT)
{
	data = DATA;
	next = NEXT;
}

template < typename T>
void Node<T>::setdata(const T& DATA)
{
	data = DATA;
}

template < typename T>
void Node<T>::setNext(Node<T>* NEXT)
{
	next = NEXT;
}

template < typename T>
T Node<T>::getdata() const
{
	return data;
}

template < typename T>
Node<T>* Node<T>::getNext() const
{
	return next;
}

template < typename T>
double Node<T>::getPriority(T* truck) const
{
	Priority = truck->getTruckPriority();
	return Priority;
}