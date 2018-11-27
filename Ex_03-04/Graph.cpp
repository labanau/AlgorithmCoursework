/**
CourseWork 210CT, Exercises from 3 to 6.
Purpose: Graph.cpp : Graph class methods.

@author Rokas Labanauskas
*/

#include "stdafx.h"
#include "Graph.h"
#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <numeric>

Graph::Graph(int vertices, bool directed)
{
	this->vertices = vertices;
	this->directed = directed;
	adj_list = new std::list<std::pair<int, int> >[vertices];
}

Graph::~Graph()
{
	delete[] adj_list;
}

void Graph::add_edge(int source, int destination, int weight)
{
	if (this->directed == true) {
		adj_list[source].emplace_back(std::make_pair(destination, weight));
	}
	else {
		adj_list[source].emplace_back(std::make_pair(destination, weight));
		adj_list[destination].emplace_back(std::make_pair(source, weight));
	}
}

int Graph::dijkstra(int source, int destination) {
	try {
		std::set<std::pair<int, int>> set; // Keep track of vertices in shortest path
		std::vector<int> min_distance(this->vertices, INT_MAX);
		set.insert(std::make_pair(0, source));
		min_distance[source] = 0;

		while (!set.empty()) {
			std::pair<int, int> temp_pair = *(set.begin());
			set.erase(set.begin());

			int edge = temp_pair.second;

			std::list<std::pair<int, int>>::iterator i;

			for (i = adj_list[edge].begin(); i != adj_list[edge].end(); i++) {
				int vertice = i->first;
				int weight = i->second;

				if (min_distance[vertice] > min_distance[edge] + weight) {
					if (min_distance[vertice] != INT_MAX) {
						set.erase(set.find(std::make_pair(min_distance[vertice], vertice)));
					}
					min_distance[vertice] = min_distance[edge] + weight;
					set.insert(std::make_pair(min_distance[vertice], vertice));
				}
			}
		}

		return min_distance[destination];
	}
	catch (std::out_of_range){
		std::cout << "Out of bound!" << std::endl;
	}
}

bool Graph::is_path(int vertice1, int vertice2)
{
	std::vector<bool> vertixe_visited(this->vertices);
	std::queue<int> temp_queue;
	std::vector<int> parent(this->vertices, -1);
	std::list<std::pair<int, int>>::iterator i;

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
			int vertice = (*i).first;
			
			if (!vertixe_visited[vertice]) {
				vertixe_visited[vertice] = true;
				temp_queue.push(vertice);
				parent[vertice] = vertice1;
				if (vertice == vertice2) {
					std::cout << "Path: ";
					print_path(parent, vertice);
					std::cout << std::endl;
					return true;
				}
			}
		}
	}
	return false;
}


bool Graph::is_connected()
{
	std::vector<bool> vertices_visited(this->vertices);
	for (int vertice = 0; vertice < this->vertices; vertice++)
		vertices_visited[vertice] = false;

	for (int vertice = 2; vertice<this->vertices; vertice++)
	{
		if (vertices_visited[vertice] == false)
		{
			dfs_util(vertice, vertices_visited);

			std::cout << "\n";
		}
		return true;
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


void Graph::print_current_graph()
{
	std::list<std::pair<int, int>>::iterator j;
	for (int i = 0; i < this->vertices; i++) {
		std::cout << i << " - > ";
		for (j = adj_list[i].begin(); j != adj_list[i].end(); j++) {
			int v = (*j).first;
			std::cout << v << " ";
		}
		std::cout << std::endl;
	}
}

void Graph::dfs_util(int vertice, std::vector<bool> vertixe_visited) {
	vertixe_visited[vertice] = true;

	std::cout << vertice << " ";

	std::list<std::pair<int, int>>::iterator j;

	for (j = adj_list[vertice].begin(); j != adj_list[vertice].end(); j++) {
		if (!vertixe_visited[(*j).first]) {
			dfs_util((*j).first, vertixe_visited);
		}
	}
}

void Graph::dfs(int vertice)
{
	std::vector<bool> vertice_visited(this->vertices);

	for (int i = 0; i < this->vertices; i++)
		vertice_visited[i] = false;

	for (int i = 0; i < this->vertices; i++)
		if(vertice_visited[i] = false)
			dfs_util(i, vertice_visited);
}