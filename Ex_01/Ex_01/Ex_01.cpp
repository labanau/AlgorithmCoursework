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

/**
Read a paragraph of words from a file.

@return vector - with the words in the vector as string type
*/
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

/**
Count words frequencies.

@param words - vector where the words are stored

@return vector - which has the frequencies as int type;
*/
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

/**
Creates the BST tree.

@param words - Vector with words with which to create the tree
@param frequenc - Frequencies of the words appearing.

@return root - The created binary search tree.
*/
BinarySearchTree_Node * createTree(std::vector<std::string> words, std::vector<int> frequenc) {
	BinarySearchTree_Node * root = new BinarySearchTree_Node(words[0], frequenc[0]);

	for (int i = 0; i < words.size(); i++) {
		root->insertNode(words[i], frequenc[i]);
	}
	return root;
}

/**
Print the words which where read from the file

@param words - vector with words as string type inside of it.
*/
void print(std::vector<std::string> words) {
	for (auto v : words) {
		std::cout << v << std::endl;
	}
}