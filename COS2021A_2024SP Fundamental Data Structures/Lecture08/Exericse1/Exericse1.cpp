#include <iostream>

template <class T> void removeStackTop(stack <T>& a)
{
	// Complete the function to remove all values equal to the top value in a stack, and reverse its order
    T v = a.top();
	queue<T> y;
    while (!a.IsEmpty())
        y.enqueue(a.pop());
    while (!y.IsEmpty()) {
        if (y.front() != v)
            a.push(y.dequeue());
        else y.dequeue()
    }
}

int main()
{
    
};