/**
CourseWork 210CT, Exercises from 3 to 6.
Purpose: Graph.h : Declarations for the Graph class.

@author Rokas Labanauskas
*/
#pragma once
#include <iostream>
#include <list>
#include <vector>

/**
Class Graph - Create, add, remove vertices and three different algorithms implementation.

@return vector - with the words in the vector as string type
*/
class Graph
{
private:

	/**
	How much vertices the graph will have
	
	@parimeter int - Count of Vertices.
	*/
	int vertices;

	/**
	If the graph is directed or undirected.
	*/
	bool directed;
public:
	/**
	Store the vertices in a Adjacency list

	@parameter Multi-dimensional list, with pairs of Destinations and Weights
	*/
	std::list<std::pair<int, int>> * adj_list;

	/**
	Graph class constructor
	*/
	Graph(int vertices, bool directed);

	/**
	Graph class de-constructor
	*/
	~Graph();

	/**
	Add edge to a graph.
	
	@return None
	*/
	void add_edge( int source, int destination, int weight);

	/**
	Check if a graph has a path between two vertices.
	
	@return bool - If there is a path True if not, False.
	*/
	bool is_path( int vertice1, int vertice2);
	
	/**
	Check if a graph is strongly connected
	
	@return bool - If it is strongly connected return True if not, False.
	*/
	bool is_connected();

	/**
	DFS utility, helper for DFS function
	
	@return None
	*/
	void dfs_util(int vertice, std::vector<bool> vertex_visited);
	
	/**
	Main DFS function
	
	@return None
	*/
	void dfs(int vertice);
	
	/**
	Djikstra algorithm, to find shortest path from src to dst.

	@return the value of the path.
	*/
	int dijkstra(int source, int destination);
	
	// Both functioncs are print fuinctions, one used to print the current graph and other the path.

	void print_path(std::vector<int> &parent, int i);
	void print_current_graph();
};