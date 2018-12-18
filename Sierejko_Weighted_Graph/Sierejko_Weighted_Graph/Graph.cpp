#include "pch.h"
#include "Graph.h"
#include "Queue.h"

Graph::Graph() 
{
	vertices = new List<Vertex*>();
	edges = new List<Edge*>();
}

Graph::~Graph()
{
	cout << "Graph deleted" << endl;

	for (Node<Vertex*>* tmpV; !vertices->isEmpty();) 
	{
		//Get the head
		Vertex* currentVertex = vertices->getFront()->getData();

		//Deletes all Nodes in the Edges List of currentVertex
		currentVertex->deleteEdgeList();

		//Set the tmp as the next in line
		tmpV = vertices->getFront()->getNext();

		//Delete the Media data
		delete vertices->getFront()->getData();
		cout << "Vertex Data Deleted" << endl;


		//Delete the head
		delete vertices->getFront();
		cout << "Vertex List Deleted" << endl;

		//Set the new head as next Node 
		vertices->setFront(tmpV);
	}
}

//Default function. Use string to search for source and destination in list
void Graph::addEdge(string inSourceName, string inDestinationName, int weight)
{
	//Locate the source and destination vertices if they exist
	Vertex* source = getVertex(inSourceName);
	Vertex* destination = getVertex(inDestinationName);

	//Call overloaded addEdge with addresses to source and destination
	addEdge(source, destination, weight);
}

//Overloaded function. Call this when you know the address of both the source and destination
void Graph::addEdge(Vertex * inSource, Vertex * inDestination, int weight)
{

	//Makes sure there is a source and destination
	if (inSource != 0 && inDestination != 0) 
	{
		//Edge's key is generated sequentially
		string tmpKey = to_string(inSource->getEdgesLList()->count());

		Edge* tmpEdge = new Edge(inSource, inDestination, weight);

		//Give the source a new edge connecting to destination, with line weight
		inSource->getEdgesLList()->pushFront(tmpKey, tmpEdge);

		edges->pushFront(tmpKey, tmpEdge);
	}
}
 
void Graph::addVertex(string key, Media* inMedia, const char* next, int weightNext, const char* previous, int weightPrev)
{
	//Checks if vertex is already in list
	if (getVertex(key) != 0)
	{
		cout << "Vertex name exists in database. Please rename and try again" << endl;
		return;
	}

	//Create a new vertex
	Vertex* currentVertex = new Vertex(inMedia);

	//Add Vertex to graph's list
	vertices->pushFront(key, currentVertex);

	if (next != "") 
	{
		Vertex* nextVertex = getVertex(next);

		if (nextVertex != 0)
		{
			//Add an edge from Current Vertex to the Next Vertex
			addEdge(currentVertex, nextVertex, weightNext);
		}
	}

	if (previous != "")
	{
		Vertex* previousVertex = getVertex(previous);
		
		if (previousVertex != 0) 
		{
			//Add an edge from Previous Vertex to the Current Vertex
			addEdge(previousVertex, currentVertex, weightPrev);
		}
	}
}

//Find a Vertex by its key
Vertex * Graph::getVertex(string inKey)
{
	//Check if the source exists
	Node<Vertex*>* tmp = vertices->search(inKey);

	//Return vertex if node exists
	if (tmp != 0) return  tmp->getData();

	//If nothing is found, return null
	return nullptr;
}

//Get Array of Edges of a Vertex
Edge * Graph::getEdgesByParent(string sourceVertex)
{
	//Get the parent of Edges
	Vertex* parentVertex = getVertex(sourceVertex);

	//If the parentVertex doesn't exist, return null
	if (parentVertex == 0)
		return nullptr;

	//Create array of edges from parent
	Edge* childEdges = *parentVertex->getEdgesLList()->toArray();

	//Return array of child edges
	return childEdges;
}

//Get List of Vertices
List<Vertex*>* Graph::getVertices()
{
	return vertices;
}

//Get List of Edges
List<Edge*>* Graph::getEdges()
{
	return edges;
}


