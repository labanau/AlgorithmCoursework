/**
CourseWork 210CT, Ex_01.cpp
Purpose: BinarySearchTree_Node.h : Declarations of the BST class

@author Rokas Labanauskas
*/

#pragma once

#include "stdafx.h"
#include <string>
#include <iostream>

class BinarySearchTree_Node
{
public:
	
	std::string key;
	int value;
	BinarySearchTree_Node * left;
	BinarySearchTree_Node * right;

public:
	/**
	Constructor for the BST class creates the first node

	@param key - the word to store to the BST.
	@param value - the frequency of the word appearing in a file

	Storing both variables to one leaf, which why you can call them a pair.
	*/
	BinarySearchTree_Node(std::string key, int value);

	/**
	Inserts a new node to the BST

	@param key - the word to store to the BST.
	@param value - the frequency of the word appearing in a file
	*/
	void insertNode( std::string key, int value );

	/**
	Print the BST in pre-order

	@param root - Binary search tree
	*/
	void pre_orderBST( BinarySearchTree_Node * root );

	/**
	Search for a node in a BST, by its key.

	@param key - the word used to find the node
	*/
	bool searchBST( std::string key );

	/**
	Delete a node from a BST.

	@param root - Binary search tree, from which to delete the node
	@param key - the node to delete
	*/
	BinarySearchTree_Node * deleteNode(BinarySearchTree_Node * root, std::string key );
	BinarySearchTree_Node * findMinimum(BinarySearchTree_Node * root);
};

