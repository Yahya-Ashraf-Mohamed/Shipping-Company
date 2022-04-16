#pragma once
#include"../DataStructures/Node.h"

template <typename T>

class PriorityQueue
{
private:

public:
	PriorityQueue();
	bool isEmpty() const;
	bool enqueue(const T& newEntry);
	bool dequeue(T& frntEntry);
	bool peek(T& frntEntry)  const;
	~PriorityQueue()
};

template <typename T>
PriorityQueue< T > ::PriorityQueue()
{

}

template <typename T>
bool PriorityQueue< T > ::isEmpty() const
{

}

template <typename T>
bool PriorityQueue< T > ::enqueue(const T& newEntry)
{

}

template <typename T>
bool PriorityQueue< T > ::dequeue(T& frntEntry)
{

}

template <typename T>
bool PriorityQueue< T > ::peek(T& frntEntry)  const
{

}

template <typename T>
PriorityQueue< T > :: ~PriorityQueue()
{}