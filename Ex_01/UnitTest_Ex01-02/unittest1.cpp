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
		BinarySearchTree_Node * create_tree() 
		{
			BinarySearchTree_Node * root = new BinarySearchTree_Node("root", 1);

			root->insert_node("amazing", 2);
			root->insert_node("lol", 2);
			root->insert_node("beautiful", 2);
			root->insert_node("great", 2);

			return root;
		}
		
		TEST_METHOD(TestMethod_searchKeyInt)
		{ 
			BinarySearchTree_Node * root = create_tree();
			
			Assert::AreEqual(false, root->search_binary_tree("0000"));
		}

		TEST_METHOD(TestMethod_searchKeyString) 
		{	
			BinarySearchTree_Node * root = create_tree();

			Assert::AreEqual(true, root->search_binary_tree("great"));
		}

		TEST_METHOD(TestMethod_InsertNewNodeAndSearch)
		{
			BinarySearchTree_Node * root = create_tree();

			root->insert_node("respect", 10);

			Assert::AreEqual(true, root->search_binary_tree("respect"));
		}

		TEST_METHOD(TestMethod_DeleteNodeAndSearch)
		{
			BinarySearchTree_Node * root = create_tree();

			root->delete_node(root, "great");

			Assert::AreEqual(false, root->search_binary_tree("great"));
		}
		TEST_METHOD(TestMethod_searchKeyString2)
		{
			BinarySearchTree_Node * root = create_tree();

			Assert::AreEqual(false, root->search_binary_tree("not"));
		}

		TEST_METHOD(TestMethod_searchKeyString3)
		{
			BinarySearchTree_Node * root = create_tree();

			Assert::AreEqual(false, root->search_binary_tree("no"));
		}

		TEST_METHOD(TestMethod_initiliazingEmptyTree)
		{
			BinarySearchTree_Node* root = create_tree();

			Assert::AreEqual(false, root->value == NULL ? false : true);
		}
	};
}