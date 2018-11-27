/**
CourseWork 210CT, BinarySearchTree_Node.cpp
Purpose: Create Binary search tree

@author Rokas Labanauskas
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include "BinarySearchTree_Node.h"

/**
Constructor for the BST class creates the first node

@param key - the word to store to the BST.
@param value - the frequency of the word appearing in a file

Storing both variables to one leaf, which why you can call them a pair.
*/
BinarySearchTree_Node::BinarySearchTree_Node(std::string key, int value) {
	this->key = key;
	this->value = value;
	this->left = NULL;
	this->right = NULL;
}

/**
Inserts a new node to the BST

@param key - the word to store to the BST.
@param value - the frequency of the word appearing in a file
*/
void BinarySearchTree_Node::insert_node(std::string key, int value) {
		if (key < this->key) {
			if (this->left == NULL) {
				this->left = new BinarySearchTree_Node(key, value);
			}
			else {
				this->left->insert_node( key, value);
			}
		}
		else { 
			if (this->right == NULL) {
				this->right = new BinarySearchTree_Node(key, value);
			}
			else {
				this->right->insert_node( key, value);
			}
		}
}

/**
Search for a node in a BST, by its key.

@param key - the word used to find the node
*/
bool BinarySearchTree_Node::search_binary_tree( std::string key) {
	std::cout << " -> " << this->key;
	if (key == this->key) {
		std::cout << " Found!" << std::endl;
		return true;
	}
	else if (key <= this->key) {
		if (this->left == NULL) {
			std::cout << " Not Found!" << std::endl;
			return false;
		}
		else {
			return (this -> left) -> search_binary_tree(key);
		}
	}
	else {
		if (this->right == NULL) {
			std::cout << " Not Found!" << std::endl;
			return false;
		}
		else {
			return (this -> right) -> search_binary_tree(key);
		}
	}
	return false;
}

/**
Print the BST in pre-order

@param root - Binary search tree
*/
void BinarySearchTree_Node::pre_order_binary_tree() {
	std::cout << this->key << " : " << this->value << ", ";
	if (this->left != 0) {
		(this->left)->pre_order_binary_tree();
	}
	if (this->right != 0) {
		(this->right)->pre_order_binary_tree();
	}
}

/**
Delete a node from a BST.

@param root - Binary search tree, from which to delete the node
@param key - the node to delete
*/
BinarySearchTree_Node * BinarySearchTree_Node::delete_node(BinarySearchTree_Node * root, std::string key) {
	if (key < root->key) {
		root->left = delete_node(root->left, key);
	}
	else if (key > root->key) {
		root->right = delete_node(root->right, key);
	}
	else {
		if (root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}
		else if (root->left == NULL) {
			root = root->right;
		}
		else if (root->right == NULL) {
			root = root->left;
		}
		else {
			BinarySearchTree_Node * temp = find_min(root->right);
			root->key = temp->key;
			root->right = delete_node(root->right, temp->key);
		}
	}
	return root;
}

BinarySearchTree_Node * BinarySearchTree_Node::find_min(BinarySearchTree_Node * root) {
	while (root->left != NULL) 
		root = root->left;
	return root;
}