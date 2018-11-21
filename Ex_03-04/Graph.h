#pragma once
#include <iostream>
#include <list>
#include <stack>
#include <vector>

class Graph
{
private:
	int vertices;
public:
	std::list<int> * adj_list;

	Graph(int vertices);
	~Graph();

	void add_edge( int source, int destination);
	bool isPath( int vertice1, int vertice2);
	bool isConnected();
	void dfs_util(int vertice, std::vector<bool> vertex_visited);
	void dfs(int vertice);

	void print_path(std::vector<int> &parent, int i);
};