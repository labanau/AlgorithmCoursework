#include "stdafx.h"
#include <iostream>
#include <string>
#include "BinarySearchTree_Node.h"


BinarySearchTree_Node::BinarySearchTree_Node(std::string key, int value) {
	this->key = key;
	this->value = value;
	this->left = NULL;
	this->right = NULL;
}

void BinarySearchTree_Node::insertNode(std::string key, int value) {
		if (key < this->key) {
			if (this->left == NULL) {
				this->left = new BinarySearchTree_Node(key, value);
			}
			else {
				this->left->insertNode( key, value);
			}
		}
		else {
			if (this->right == NULL) {
				this->right = new BinarySearchTree_Node(key, value);
			}
			else {
				this->right->insertNode( key, value);
			}
		}
}

bool BinarySearchTree_Node::searchBST( std::string key) {
	if (key == this->key) {
		return true;
	}
	else if (key <= this->key) {
		if (this->left == NULL) {
			return false;
		}
		else {
			return (this -> left) -> searchBST(key);
		}
	}
	else {
		if (this->right == NULL) {
			return false;
		}
		else {
			return (this -> right) -> searchBST(key);
		}
	}
	return false;
}

void BinarySearchTree_Node::pre_orderBST(BinarySearchTree_Node * root) {
	std::cout << root->key << " : " << root->value << ", ";
	if (root->left != 0) {
		pre_orderBST(root->left);
	}
	if (root->right != 0) {
		pre_orderBST(root->right);
	}
}