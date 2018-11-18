// Ex_03-04.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <fstream>
#include "../Ex_03-04/Ex_03-04.h"
#include "../Ex_03-04/Graph.h"

int main()
{
	int vertices = 4;

	Graph graph(vertices);

	graph.add_edge(0, 1);
	graph.add_edge(0, 2);
	graph.add_edge(1, 2);
	graph.add_edge(3, 3);

	graph.print_graph();
	
	graph.isPath(0, 3) ? std::cout << "Yes!\n" : std::cout << "No!" << std::endl;
	graph.isPath(1, 2) ? std::cout << "Yes!\n" : std::cout << "No!" << std::endl;
	graph.isPath(0, 1) ? std::cout << "Yes!\n" : std::cout << "No!" << std::endl;
	system("PAUSE");
    return 0;
}