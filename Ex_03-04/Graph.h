#pragma once
#include <iostream>
#include <vector>

class Graph
{
private:
	int vertices;
public:
	std::vector<int> * adj_list;
	Graph(int vertices);
	~Graph();

	void add_edge( int source, int destination);
	bool isPath( int vertice1, int vertice2);
	bool isStronglyConnected();


	void print_path(std::vector<int> parent_list, std::vector<int> path_list);
	void print_graph();
};