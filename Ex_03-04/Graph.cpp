#include "stdafx.h"
#include "Graph.h"
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>

Graph::Graph(int vertices)
{
	this->vertices = vertices;
	adj_list = new std::list<int>[vertices];
}

Graph::~Graph()
{
	delete[] adj_list;
}

void Graph::add_edge(int source, int destination)
{
	this->adj_list[source].push_back(destination);
	this->adj_list[destination].push_back(source);
}

bool Graph::isPath(int vertice1, int vertice2)
{	
	std::vector<bool> vertixe_visited(this->vertices);
	std::queue<int> temp_queue;
	std::vector<int> parent(this->vertices, -1);
	std::list<int>::iterator i; // Iteratpr used for the vector cycle at the bottom
	//to get all vertices in the adj_list.

	if (vertice1 == vertice2) {
		return true;
	}

	for (int i = 0; i < this->vertices; i++) {
		vertixe_visited[i] = false;
	}

	vertixe_visited[vertice1] = true; // Marking Current node as visited
	temp_queue.push(vertice1);

	while (!temp_queue.empty()) {
		vertice1 = temp_queue.front();
		temp_queue.pop();

		for (i = adj_list[vertice1].begin(); i != adj_list[vertice1].end(); i++) {
			if (!vertixe_visited[*i]) {
				vertixe_visited[*i] = true;
				temp_queue.push(*i);
				parent[*i] = vertice1;
				if (*i == vertice2) {
					std::cout << "Path: ";
					print_path(parent, *i);
					std::cout << std::endl;
					return true;
				}
			}
		}
	}
	return false;
}

bool Graph::isConnected()
{
	std::vector<bool> vertices_visited(this->vertices);
	for (int vertice = 0; vertice < this->vertices; vertice++)
		vertices_visited[vertice] = false;

	for (int vertice = 0; vertice<this->vertices; vertice++)
	{
		if (vertices_visited[vertice] == false)
		{
			dfs_util(vertice, vertices_visited);

			std::cout << "\n";
			return true;
		}
	}
	return false;
}

void Graph::print_path(std::vector<int>& parent, int i)
{
	if (parent[i] == -1) {
		std::cout << i;
		return;
	}

	print_path(parent, parent[i]);
	std::cout << " -> " << i;
}

void Graph::dfs_util(int vertice, std::vector<bool> vertixe_visited) {
	vertixe_visited[vertice] = true;

	std::cout << vertice << " ";

	std::list<int>::iterator j;

	for (j = adj_list[vertice].begin(); j != adj_list[vertice].end(); j++) {
		if (!vertixe_visited[*j]) {
			dfs_util(*j, vertixe_visited);
		}
	}
}

void Graph::dfs(int vertice)
{
	std::vector<bool> vertice_visited(this->vertices);

	// mark everything to be false
	for (int i = 0; i < this->vertices; i++)
		vertice_visited[i] = false;

	dfs_util(vertice, vertice_visited);
}