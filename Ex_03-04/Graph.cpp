#include "stdafx.h"
#include "Graph.h"
#include <iostream>
#include <vector>
#include <queue>

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

bool Graph::isPath(int vertice1, int vertice2)
{	
	std::queue<int> temp_queue;

	std::vector<bool> vertices_visited(this->vertices);
	
	std::vector<int> parent(this->vertices);
	std::vector<int> path;
	std::vector<int>::iterator i; // Iteratpr used for the vector cycle at the bottom
	//to get all vertices in the adj_list.

	if (vertice1 == vertice2) {
		return true;
	}

	for (int i = 0; i < this->vertices; i++) {
		vertices_visited[i] = false;
	}

	vertices_visited[vertice1] = true; // Marking Current node as visited
	temp_queue.push(vertice1);

	while (!temp_queue.empty()) {
		vertice1 = temp_queue.front();
		temp_queue.pop();

		for (i = adj_list[vertice1].begin(); i != adj_list[vertice1].end(); i++) {
			if (*i == vertice2) {
				parent[*i] = vertice2;
				path.push_back(*i);
				print_path(parent, path);
				return true;
			}
			if (!vertices_visited[*i]) {
				vertices_visited[*i] = true;
				path.push_back(*i);
				parent[*i] = vertice1;
				temp_queue.push(*i);
			}
		}
	}
	return false;
}

bool Graph::isStronglyConnected()
{
	return false;
}

void Graph::print_graph()
{
	for (int i = 0; i<this->vertices; i++) {
		std::cout << i << " -> ";
		for (int j = 0; j < adj_list[i].size(); j++) {
			std::cout << adj_list[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void Graph::print_path(std::vector<int> parent_list, std::vector<int> path_list) {
	for (std::vector<int>::iterator i = path_list.begin(); i < path_list.end(); i++) {
		std::cout << parent_list[*i] << std::endl;
	}
}