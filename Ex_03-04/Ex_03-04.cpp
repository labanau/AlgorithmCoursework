/**
CourseWork 210CT, Exercises from 3 to 6.
Purpose: Ex_03-04.cpp : Defines the entry point for the console application and calls the Graph class.

@author Rokas Labanauskas
*/
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <fstream>
#include "../Ex_03-04/Ex_03-04.h"
#include "../Ex_03-04/Graph.h"

int main()
{
	int vertices = 4;

	Graph graph(vertices, true);

	//  making above shown graph 
	graph.add_edge(0, 1, 4);
	graph.add_edge(0, 2, 8);
	graph.add_edge(1, 2, 8);
	graph.add_edge(2, 0, 7);
	graph.add_edge(2, 3, 8);
	graph.add_edge(3, 3, 7);

	int distance = graph.dijkstra(0, 3);

	std::cout << distance << std::endl;
	
	graph.print_current_graph();
	
	graph.is_path(0, 7) ? std::cout << "Yes!\n" : std::cout << "No!" << std::endl;
	graph.is_path(1, 2) ? std::cout << "Yes!\n" : std::cout << "No!" << std::endl;
	graph.is_path(2, 4) ? std::cout << "Yes!\n" : std::cout << "No!" << std::endl;

	std::cout << "Following is Depth First Traversal For The Graph ";

	graph.dfs(2);

	std::cout << std::endl;

	graph.is_connected() ? std::cout << "Yes! It is strongly connected!\n" : std::cout << "No!" << std::endl;
    return 0;
}