#include "stdafx.h"
#include "Graph.h"
#include <iostream>
#include <vector>

Graph::Graph(int vertices)
{
	this->vertices = vertices;
	this->adj_list = new std::vector<int>[vertices];
}

Graph::~Graph()
{
}

void Graph::add_edge(int source, int destination)
{
	this->adj_list[source].push_back(destination);
	this->adj_list[destination].push_back(source);
}

void Graph::print_graph()
{
	for (int i = 0; i<this->vertices; i++) {
		std::cout << i << " -> ";
		for (auto edge : *adj_list) {
			std::cout << " " << edge << " ";
		}
		std::cout << std::endl;
	}
}
