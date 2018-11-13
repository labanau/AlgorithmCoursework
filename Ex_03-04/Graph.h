#pragma once
#include <iostream>
#include <list>

class Graph
{
private:
	int vertices;
	std::list<int> * adj_list;
public:
	Graph(int vertices);
	~Graph();

	void add_edge(int source, int destination);
};

