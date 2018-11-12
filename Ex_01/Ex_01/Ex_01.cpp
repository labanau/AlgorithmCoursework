/**
CourseWork 210CT, Ex_01.cpp
Purpose: Ex_01.cpp : Defines the entry point for the console application and calls the BST class.

@author Rokas Labanauskas
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include "BinarySearchTree_Node.h"
#include "Ex_01.h"
#include <fstream>


int main()
{
	std::vector<std::string> words;
	std::vector<int> frequenc;
	
	words = readFile();
	frequenc = countFreqOfWord(words);

	BinarySearchTree_Node * root = createTree(words, frequenc);
	
	root->pre_orderBST(root);
	
	std::cout << std::endl;

	bool answer = root->searchBST(".txt.");

	answer ? std::cout << "Found\n" : std::cout << "Not Found\n";

	root = root->deleteNode(root, ".txt.");

	std::cout << "Deleted!" << std::endl;

	answer = root->searchBST(".txt.");

	answer ? std::cout << "Found\n" : std::cout << "Not Found\n";

	root->pre_orderBST(root);

    return 0;
}

std::vector<std::string> readFile() {
	std::vector<std::string> words;
	std::string temp;
	std::ifstream file("input.txt");

	while (file>>temp) { // Until the file finishes
		words.push_back(temp);
	}
	file.close();
	return words;
}

std::vector<int> countFreqOfWord(std::vector<std::string> words) {
	std::vector<int> frequenc;
	int count = 1;
	for (int i = 0; i < words.size(); i++) {
		for (int j = 1; j < words.size(); j++) {
			if (words[i] == words[j]) {
				count++;
			}
		}
		frequenc.push_back(count);
		count = 0;
	}
	return frequenc;
}

BinarySearchTree_Node * createTree(std::vector<std::string> words, std::vector<int> frequenc) {
	BinarySearchTree_Node * root = new BinarySearchTree_Node(words[0], frequenc[0]);

	for (int i = 0; i < words.size(); i++) {
		root->insertNode(words[i], frequenc[i]);
	}
	return root;
}

void print(std::vector<std::string> words) { // Will
	for (auto v : words) {
		std::cout << v << std::endl;
	}
}