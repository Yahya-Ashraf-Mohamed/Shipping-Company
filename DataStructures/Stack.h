template<typename T>
class Stack
{
private:
	T* items;		// Array of stack items
	int top;                   // Index to top of stack
	int size = 0;

public:

	Stack()
	{
		items = new T[size];
		top = -1;
	}  // end default constructor

	bool isEmpty() const
	{
		return top == -1;
	}  // end isEmpty

	bool push(const T& newEntry)
	{
		if (top == size - 1) return false;	//Stack is FULL
		top++;
		items[top] = newEntry;
		return true;
	}  // end push


	int StackSize()
	{
		return size;
	}

	bool pop(T& TopEntry)
	{
		if (isEmpty()) return false;
		TopEntry = items[top];
		top--;
		return true;
	}  // end pop

	bool peek(T& TopEntry) const
	{
		if (isEmpty()) return false;

		TopEntry = items[top];
		return true;
	}  // end peek

}; // end ArrayStack