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
	void print_graph();
};

