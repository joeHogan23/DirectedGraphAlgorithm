#include "pch.h"
#include "Queue.h"

template<class T>
Queue<T>::Queue() {}

template<class T>
Queue<T>::~Queue() {}

template<class T>
void Queue<T>::enqueue(string key,T data)
{
	list.pushBack(key, data);
}

template<class T>
T Queue<T>::dequeue()
{
	if (!list.isEmpty()) 
		return list->popFront();

	return NULL;
}

template<class T>
int Queue<T>::count()
{
	return list.count();
}

template<class T>
bool Queue<T>::isEmpty()
{
	return list.isEmpty();
}
