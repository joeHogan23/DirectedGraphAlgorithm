#pragma once
#include "pch.h"
#include <map>
#include "Vertex.h"
#include "Edge.h"

#include <iostream>

using namespace std;

//--------------------------------------------------------------------------------------//
//									Graph Interface										//
//--------------------------------------------------------------------------------------//

class Graph 
{
private:
	List<Vertex*>* vertices;
	List<Edge*>* edges;
public:

	Graph();
	~Graph();

	//Default function. Use string to search for source and destination in list
	void addEdge(string inSourceName, string inDestinationName, int weight);

	//Overloaded function. Call this when you know the address of both the source and destination
	void addEdge(Vertex* inSource, Vertex* inDestination, int weight);

	//Add a vertex to the graph using an ID and the Media source
	void addVertex(string inKey, Media* inMedia, const char* next = "", int weightNext = 0, const char* previous = "", int weightPrev = 0);

	Vertex* getVertex(string source);

	Edge* getEdgesByParent(string sourceVertex);

	List<Vertex*>* getVertices();
	List<Edge*>* getEdges();
};