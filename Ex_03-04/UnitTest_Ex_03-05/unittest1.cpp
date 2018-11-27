#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Ex_03-04.cpp"
#include "../Graph.cpp"
#include "../Graph.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest_Ex_0305
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		Graph * createTree()
		{
			int vertices = 4;

			Graph *graph = new Graph(vertices, true);

			//  making above shown graph 
			graph->add_edge(0, 1, 4);
			graph->add_edge(0, 2, 8);
			graph->add_edge(1, 2, 8);
			graph->add_edge(2, 0, 7);
			graph->add_edge(2, 3, 8);
			graph->add_edge(3, 3, 7);

			return graph;
		}

		TEST_METHOD(TestMethod_add_vertices){

			Graph  * graph = createTree();
			graph->print_current_graph();
			Assert::AreEqual(false, graph->adj_list->empty());
		}
		TEST_METHOD(TestMethod_is_there_path1)
		{
			Graph  * graph = createTree();

			Assert::AreEqual(true, graph->is_path(0, 3));
		}
		TEST_METHOD(TestMethod_is_there_path2)
		{
			Graph  * graph = createTree();

			Assert::AreEqual(true, graph->is_path(0, 1));
		}
		TEST_METHOD(TestMethod_is_there_path3)
		{
			Graph  * graph = createTree();

			Assert::AreEqual(false, graph->is_path(0, 4));
		}
		TEST_METHOD(TestMethod_is_there_path4)
		{
			Graph  * graph = createTree();

			Assert::AreEqual(false, graph->is_path(0, 7));
		}
		TEST_METHOD(TestMethod_is_strongly_connected)
		{
			Graph  * graph = createTree();

			Assert::AreEqual(true, graph->is_connected());
		}
		TEST_METHOD(TestMethod_shortest_path)
		{
			Graph  * graph = createTree();

			Assert::AreEqual(7, graph->dijkstra(2, 0));
		}
		TEST_METHOD(TestMethod_shortest_path2)
		{
			Graph  * graph = createTree();

			Assert::AreEqual(4, graph->dijkstra(0, 1));
		}
		TEST_METHOD(TestMethod_shortest_path3)
		{
			Graph  * graph = createTree();

			Assert::AreEqual(8, graph->dijkstra(0, 2));
		}

	};
}