#pragma once
#include "Media.h"
#include "List.h"
#include <iostream>
using namespace std;

class Edge;

//--------------------------------------------------------------------------------------//
//									Vertex Interface									//
//--------------------------------------------------------------------------------------//

//Wrapper around data
class Vertex {
private:
	Media* media = nullptr;

	//void* data;

	//Doubly LinkedList
	List<Edge*>* edgesLList;


public:
	
	void deleteEdgeList();

	//Constructor
	Vertex(Media* inMedia): edgesLList(new List<Edge*>()) 
	{
		media = inMedia;
	};

	List<Edge*>* getEdgesLList();
	Media* getMedia();

	void displayAllDestinations();
};

