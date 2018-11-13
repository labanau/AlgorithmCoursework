#pragma once
#include <iostream>
#include <vector>

struct graph_node{
	int destination;
	int source;
};

class Graph
{
public:
	std::vector<std::vector<int>> adj_list;
	Graph(std::vector<graph_node> const &edges, int vertices);
	~Graph();
};

