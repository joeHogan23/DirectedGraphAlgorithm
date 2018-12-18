#pragma once

#include <iostream>
#include <string>
using namespace std;

template<typename T>
class Node {
private:

	string key;
	Node<T> *next;
	T data;

public:
	Node<T>(string inKey, T inData, Node<T>* inNext = 0);
	//~Node();

	void setKey(string inKey);
	string getKey();

	void setNext(Node<T>* inNext);
	Node<T>* getNext();

	void setData(T inData);
	T getData();
};

//Constructor
template<typename T> inline Node<T>::Node(string inKey, T inData, Node<T>* inNext) : key(inKey), data(inData), next(inNext) {};

////Destructor
//template<typename T> inline Node<T>::~Node() 
//{
//	cout << "Node deleted" << endl;
//}

//Set Key
template<typename T> inline void Node<T>::setKey(string inKey) { key = inKey; }

//Get Key
template<typename T> inline string Node<T>::getKey() { return key; }

//Set Next Node
template<typename T> inline void Node<T>::setNext(Node<T>* inNext) { next = inNext; }

//Get Next Node
template<typename T> inline Node<T>* Node<T>::getNext() { return next; }

//Set Data In Node
template<typename T> inline void Node<T>::setData(T inData) { data = inData; }

//Get Data In Node
template<typename T> inline T Node<T>::getData() { return data; }


