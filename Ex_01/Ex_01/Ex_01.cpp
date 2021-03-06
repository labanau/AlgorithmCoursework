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
	std::vector<int> frequency;
	
	words = read_file();
	frequency = count_freq_of_words(words);

	BinarySearchTree_Node * root = create_tree(words, frequency);

	std::cout << std::endl;

	root->search_binary_tree(".txt.");

	root = root->delete_node(root, ".txt.");

	std::cout << "Deleted!" << std::endl;

	root->search_binary_tree(".txt.");

	root->pre_order_binary_tree();

    return 0;
}

std::vector<std::string> read_file() {
	std::vector<std::string> words;
	std::string temp;
	std::ifstream file("input.txt");

	while (file>>temp) { // Until the file finishes
		words.push_back(temp);
	}
	file.close();
	return words;
}

std::vector<int> count_freq_of_words(std::vector<std::string> words) {
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

BinarySearchTree_Node * create_tree(std::vector<std::string> words, std::vector<int> frequenc) {
	BinarySearchTree_Node * root = new BinarySearchTree_Node(words[0], frequenc[0]);

	for (int i = 0; i < words.size(); i++) {
		root->insert_node(words[i], frequenc[i]);
	}
	return root;
}

void print(std::vector<std::string> words) {
	for (auto v : words) {
		std::cout << v << std::endl;
	}
}