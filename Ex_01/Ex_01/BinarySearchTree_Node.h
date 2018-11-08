#pragma once

#include "stdafx.h"
#include <string>
#include <iostream>
#include <map>

class BinarySearchTree_Node
{
public:
	
	std::string key;
	int value;
	BinarySearchTree_Node * left;
	BinarySearchTree_Node * right;

public:
	BinarySearchTree_Node(std::string key, int value);

	void insertNode( std::string key, int value );
	void pre_orderBST( BinarySearchTree_Node * root );
	bool searchBST( std::string key );
	BinarySearchTree_Node * deleteNode(BinarySearchTree_Node * root, std::string key );
	BinarySearchTree_Node * findMinimum(BinarySearchTree_Node * root);
};

