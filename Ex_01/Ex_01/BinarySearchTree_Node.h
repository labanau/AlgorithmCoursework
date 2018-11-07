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
	~BinarySearchTree_Node();

	void insertNode( std::string key, int value );
	void pre_orderBST(BinarySearchTree_Node * root);
	bool searchBST( std::string key );
};

