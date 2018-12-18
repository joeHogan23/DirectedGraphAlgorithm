#pragma once
#include "pch.h"
#include "Node.h"

template<typename T>
class List {
private:
	Node<T> *head, *tail; //Front and back of list

public:

	List();		//CONSTRUCTOR
	~List() {
		cout << "deleted" << endl;
	};	//DESTRUCTOR

	Node<T>* search(string key);	//DEFAULT FUNCTION: SEARCH BY STRING WHEN < T > IS UNKNOWN
	Node<T>* search(T inData);		//SEARCH FOR ELEMENT DIRECTLY

	void pushFront(string inKey, T data);	//ASSIGN TO HEAD OF LIST
	void pushBack(string inKey, T data);	//ASSIGN TO TAIL OF LIST

	T popFront();
	T popBack();

	T* toArray();			//CONVERT LIST TO ARRAY AND RETURN ARRAY
	Node<T>* getFront();	//GET HEAD
	Node<T>* getBack();		//GET TAIL

	void setFront(Node<T>* inHead);	//SET HEAD
	void setBack(Node<T>* inTail);	//SET TAIL

	const int count();		//GET ELEMENT COUNT IN LIST

	bool isEmpty();
};

template<typename T>
inline List<T>::List()
{
	//Default head and tail to nullptr
	head = tail = 0;
}

//--- Default search(): Search for Element by key ---
template<typename T>
inline Node<T> * List<T>::search(string key)
{
	//If there is only one element or the Node is at the head position
	if (head != 0 && head->getKey() == key) { 
		return head;
	}

	//Look for tmp by iterating through list
	for (Node<T>* tmp = head; tmp != 0; tmp = tmp->getNext()) 
	{
		if(tmp->getKey() == key)
			return tmp;
	}
	return NULL;
}

//--- Overloaded search(): Search For Element Directly ---
template<typename T>
inline Node<T>* List<T>::search(T inData)
{
	if (head->getData() == inData)
		return head;

	for (Node<T>* tmp = head; tmp != 0; tmp = tmp->getNext()) {
		if (tmp->getData() == inData)
			return tmp;
	}
	return NULL;
}

//--- Add Element to Head ---
template<typename T>
inline void List<T>::pushFront(string inKey, T data)
{
	//Make head a new Node and push old head to the next in link
	head = new Node<T>(inKey, data, head);
	
	//Link front to back if there is only one element in list
	if (tail == 0) 
		tail = head;
}

//--- Add Element to Tail ---
template<typename T>
inline void List<T>::pushBack(string inKey, T data)
{
	if (tail != 0) 
	{
		tail->setNext(new Node<T>(inKey, data));
		tail = tail->getNext();
	}
	else
		tail = head = new Node<T>(inKey, data);
}

template<typename T>
inline T List<T>::popFront()
{
	//Node that will return the T data requested
	Node<T>* tmpNode = head;

	//Move the head down by one Node
	head = getFront()->getNext();

	//Return detached head
	return tmpNode->data;
}

template<typename T>
inline T List<T>::popBack()
{
	//Keeps track of what will be the new tail
	Node<T>* tmpPrev = head;

	//Offset from tmpPrev so tmpPrev will exit loop with reference to the new tail
	Node<T>* tmpCurrent = head->getNext();
	for (; tmpCurrent != tail; tmpCurrent = tmpCurrent->getNext(), tmpPrev = tmpPrev->getNext());

	//Node<T>* tmpNode = tmpPrev->getNext();

	//Move tail up by one Node
	tail = tmpPrev;

	//Break link to old tail
	tail->setNext(NULL);

	//Return detached tail
	return tmpCurrent->getData();
}

//--- Convert List to Array. Return Array ---
template<typename T>
inline T * List<T>::toArray()
{
	//If no elements
	if (head == 0) return NULL;

	//Set the n index
	int i = count();

	//Create array using list size and decrement i for n - 1 indexing 
	T* elements = new T[i--];

	for (Node<T>* tmp = head; tmp != 0; tmp = tmp->getNext()) 
	{
		//Assign data from tmp to element at index i
		elements[i--] = tmp->getData();
	}
	return elements;
}

//--- Get Number of Elements in List ---
template<typename T> 
inline const int List<T>::count()
{
	int c = 0;

	//Counts how many links there are in list
	for (Node<T>* tmp = head; tmp != 0; tmp = tmp->getNext()) c++;

	//returns count
	return c;
}

//Check if List has Elements
template<typename T>
inline bool List<T>::isEmpty()
{
	return head == 0;
}

//--- Get Head ---
template<typename T>
inline Node<T> * List<T>::getFront() { return head; }

//--- Get Tail ---
template<typename T>
inline Node<T> * List<T>::getBack() { return tail; }

//--- Set Head ---
template<typename T>
inline void List<T>::setFront(Node<T>* inHead) { head = inHead; }

//--- Set Tail ---
template<typename T>
inline void List<T>::setBack(Node<T>* inTail) { tail = inTail; }
