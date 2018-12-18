#include "pch.h"
#include "Graph.h"


//Constructor

Edge::Edge(Vertex * inSource, Vertex * inDestination, int inWeight = 0)
{
	source = inSource;
	destination = inDestination;
	
}

//-----------------------------------------------------------------------------------//
//									Setters											 //
//-----------------------------------------------------------------------------------//

void Edge::setNewSource(Vertex * newSource) { source = newSource; }
void Edge::setNewDestination(Vertex * newDestination) { destination = newDestination; }
void Edge::setNewWeight(int newWeight) { weight = newWeight; }

//-----------------------------------------------------------------------------------//
//									Getters											 //
//-----------------------------------------------------------------------------------//

Vertex * Edge::getSource() { return source; }
Vertex * Edge::getDestination() { return destination; }

int Edge::getWeight() { return weight; }
