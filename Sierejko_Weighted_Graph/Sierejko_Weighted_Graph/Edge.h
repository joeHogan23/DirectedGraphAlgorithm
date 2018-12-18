
#pragma once
#include "pch.h"

//--------------------------------------------------------------------------------------//
//									Edge Interface										//
//--------------------------------------------------------------------------------------//

class Edge {
private:
	string key;

	Vertex* source;
	Vertex* destination;

	int weight;

public:
	Edge(Vertex* source, Vertex* destination, int inWeight);

	//Set New Source
	void setNewSource(Vertex* newSource);
	
	//Set New Destination
	void setNewDestination(Vertex* newDestination);
	
	//Set New Weight
	void setNewWeight(int newWeight);

	//Get Source
	Vertex* getSource();

	//Get Destination
	Vertex* getDestination();

	//--------------------------------------------------------------------------------------------------------//
	//											DOUBLY LINKED LIST							  				  //
	//--------------------------------------------------------------------------------------------------------//

	//Get Weight
	int getWeight();

};