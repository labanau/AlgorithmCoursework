#include "stdafx.h"
#include "CppUnitTest.h"
#include <string>
#include <vector>
#include "../Ex_01/BinarySearchTree_Node.h"
#include "../Ex_01/Ex_01.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest_Ex0102
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		BinarySearchTree_Node * createTree() 
		{
			BinarySearchTree_Node * root = new BinarySearchTree_Node("root", 1);

			root->insertNode("amazing", 2);
			root->insertNode("lol", 2);
			root->insertNode("beautiful", 2);
			root->insertNode("great", 2);

			return root;
		}
		
		TEST_METHOD(TestMethod_searchKeyInt)
		{ 
			BinarySearchTree_Node * root = createTree();
			
			Assert::AreEqual(false, root->searchBST("0000"));
		}

		TEST_METHOD(TestMethod_searchKeyString) 
		{	
			BinarySearchTree_Node * root = createTree();

			Assert::AreEqual(true, root->searchBST("great"));
		}

		TEST_METHOD(TestMethod_InsertNewNodeAndSearch)
		{
			BinarySearchTree_Node * root = createTree();

			root->insertNode("respect", 10);

			Assert::AreEqual(true, root->searchBST("respect"));
		}

		TEST_METHOD(TestMethod_DeleteNodeAndSearch)
		{
			BinarySearchTree_Node * root = createTree();

			root->deleteNode(root, "great");

			Assert::AreEqual(false, root->searchBST("great"));
		}
	};
}