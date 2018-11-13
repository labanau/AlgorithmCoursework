#include "stdafx.h"
#include "Graph.h"
#include <iostream>
#include <vector>

Graph::Graph(std::vector<graph_node> const &edges, int vertices)
{
    adj_list.resize(vertices);

    for(auto &edge : edges) {
        adj_list[edge.source].push_back(edge.destination);

        //adj_list[edge.destination].push_back(edge.source);
    }
}

Graph::~Graph()
{
}