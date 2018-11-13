// Ex_03-04.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <fstream>
#include "../Ex_03-04/Ex_03-04.h"
#include "../Ex_03-04/Graph.h"

void print_graph( Graph const &graph, int N) {
	for (int i = 0; i < N; i++) {
		std::cout << "The vertice is " << i << " -> ";
		for (int vertices : graph.adj_list[i]) {
			std::cout << vertices << " ";
		}
		std::cout << std::endl;
	}
}

int main()
{
	std::vector<graph_node> edges =
	{
		{ 0, 1 }, { 1, 2 }, { 2, 0 }, { 2, 1 },
		{ 3, 2 }, { 4, 5 }, { 5, 4 }
	};
	int N = 6;

	Graph graph(edges, N);

	print_graph(graph, N);
	system("PAUSE");
    return 0;
}

std::vector<graph_node> read_file(int * vertices)
{
	std::vector<graph_node> edges;
	std::ifstream file("input.txt");
	file >> *vertices;
	edges.resize(*vertices);
	for (int i= 0; i < *vertices;i++) {
		file >> edges[i];
		for (int j=0; j < ;j++) {
			
		}
	}
}