#pragma once
#include "pch.h"
#include "Graph.h"

void Vertex::deleteEdgeList()
{
	for (Node<Edge*>* tmp; !edgesLList->isEmpty(); ) 
	{
		tmp = edgesLList->getFront()->getNext();

		//Delete head of list
		delete edgesLList->getFront();

		cout << "Deleted Edge" << endl;

		//Set the head as Next Node
		edgesLList->setFront(tmp);
	}
	delete edgesLList;
	cout << "Deleted Edge List" << endl;
}

//Connects this Vertex to a list of other Vertices 
List<Edge*>* Vertex::getEdgesLList() { return edgesLList; }

//Get Data in Vertex
Media* Vertex::getMedia() { return media; }

void Vertex::displayAllDestinations() { }
