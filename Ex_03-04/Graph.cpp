#include "stdafx.h"
#include "Graph.h"
#include <iostream>
#include <vector>

Graph::Graph(int vertices)
{
	this->vertices = vertices;
	adj_list = new std::list<int>[vertices];
}

Graph::~Graph()
{
}

void Graph::add_edge(int source, int destination)
{
	adj_list[source].push_front(destination);
}
