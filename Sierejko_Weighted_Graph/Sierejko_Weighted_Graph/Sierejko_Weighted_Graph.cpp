#include "pch.h"
#include "Graph.h"
#include <iostream>

using namespace std;

int main()
{

	Graph* graph = new Graph();

	//Add vertices to graph
	graph->addVertex("1", new Video("Cutest Cat Compilation 2017", "MP4", 615, Resolution(1920, 1080)));
	graph->addVertex("2", new Music("Dream On", "Aerosmith", "M4V", 192, 268));
	graph->addVertex("3", new Video("LotR: The Fellowship of the Ring", "MOV", 13680, Resolution(1920, 1080)));
	graph->addVertex("4", new Music("Lateralus", "Tool", "MP3", 192, 568));
	graph->addVertex("5", new Video("Jurassic Park", "MOV", 7620, Resolution(1920, 1080)));

	//Adds a vertex and connects it to Vertex 1 and Vertex 4
	graph->addVertex("6", new Music("Six", "All That Remains", "MP3", 192, 203), "1", 5, "4", 7);

	//Connect vertices via edges
	graph->addEdge("1", "2", 15);
	graph->addEdge("1", "3", 20);
	graph->addEdge("1", "4", 25);
	graph->addEdge("1", "5", 15);
	graph->addEdge("3", "5", 15);
	graph->addEdge("3", "4", 15);
	graph->addEdge("4", "2", 15);
	graph->addEdge("5", "4", 15);
	
	//Create an array from vertices
	Vertex** vertices = graph->getVertices()->toArray();

	int vCount = graph->getVertices()->count();

	for (int i = 0; i < vCount; i++)
	{
		//Get an edge array of the list inside vertex i
		if (!vertices[i]->getEdgesLList()->isEmpty())
		{
			//Create an array from current vertex's edge list
			Edge** edges = vertices[i]->getEdgesLList()->toArray();

			//Get the count of the edges inside the current vertex
			int eCount = vertices[i]->getEdgesLList()->count();

			//Output each vertex name and which vertices they are connected to via an edge
			for (int j = 0; j < eCount; j++) 
			{
				//Outputs the name and format of the graph Vertex at the index i
				cout << vertices[i]->getMedia()->getMediaName() << "."
					<< vertices[i]->getMedia()->getFormat() << " -----------------> ";

				//Outputs the name and format Edge's destination at index j
				cout << edges[j]->getDestination()->getMedia()->getMediaName() << "."
					<< edges[j]->getDestination()->getMedia()->getFormat() << endl;
			}
			cout << endl;
		}
	}

	cout << endl << endl;
	//ToArray allows index access of List
	cout << "Search with toArray() function..." << endl;
	cout << "Graph Vertex Media Properties at position 1: " << endl;

	//Print all properties of Media at index 1
	graph->getVertices()->toArray()[1]->getMedia()->printProperties();

	system("pause");

	//graph deletes pointer data manually
	delete graph;

	cout << "MEMORY RELEASED" << endl;
	system("pause");
	return 0;
}