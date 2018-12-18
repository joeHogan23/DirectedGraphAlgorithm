#pragma once
#include "List.h"
#include <iostream>
#include <string>

using namespace std;

template <class T>
class Queue
{
	List<T> list;

public:
	Queue();
	~Queue();

	void enqueue(string position, T data);
	T dequeue();
	int count();
	bool isEmpty();

};

