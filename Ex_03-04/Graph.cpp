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
	this->adj_list = new std::vector<int>[vertices];
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

	std::vector<int> parent(this->vertices);
	std::vector<int> path;
	std::vector<int>::iterator i; // Iteratpr used for the vector cycle at the bottom
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
			if (*i == vertice2) {
				parent[*i] = vertice2;
				path.push_back(*i);
				print_path(parent, path);
				return true;
			}
			if (!vertixe_visited[*i]) {
				vertixe_visited[*i] = true;
				path.push_back(*i);
				parent[*i] = vertice1;
				temp_queue.push(*i);
			}
		}
	}
	return false;
}

void Graph::dfs_util(int vertice, std::vector<bool> vertixe_visited) {
	vertixe_visited[vertice] = true;

	std::vector<int>::iterator j;
	
	for (int i = 0; i < vertixe_visited.size(); i++) {
		std::cout << vertixe_visited[i] << " ";
	}
	std::cout << std::endl;

	for (j = adj_list[vertice].begin(); j != adj_list[vertice].end(); j++) {
		if (!vertixe_visited[*j]) {
			dfs_util(*j, vertixe_visited);
		}
	}
}

bool Graph::dfs(int vertice)
{
	std::vector<bool> vertixe_visited(vertice);
	// mark everything to be false
	for (int i = 0; i < this->vertices; i++)
		vertixe_visited[i] = false;

	dfs_util(vertice, vertixe_visited); // DFS starting from the given vertex
	for(int i = 0; i )
}

bool Graph::isConnected()
{
	dfs(0);
	
	for (int i = 0; i < this->vertices; i++) {
		if (vertixe_visited[i] == false) {
			return false; // if at least one vertex is not visited we return false 						  // as it will be not strongly connected
		}
	}

	Graph g = get_reversed_graph(); // We create a reversed graph
	g.print_graph();
	for (int i = 0; i < this->vertices; i++) {
		vertixe_visited[i] = false;
	}

	g.dfs_util(0, vertixe_visited);

	for (int i = 0; i < this->vertices; i++) {
		if (vertixe_visited[i] == false) {
			return false;
		}
	}
	return true;
}

Graph Graph::get_reversed_graph()
{
	Graph g (this->vertices);

	for (int vertex = 0; vertex < this->vertices; vertex++) {
		
		std::vector<int>::iterator i;
		for (i = adj_list[vertex].begin(); i != adj_list[vertex].end(); i++) {
			g.adj_list[*i].push_back(vertex);
		}
	}
	g.print_graph();
	return g;
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