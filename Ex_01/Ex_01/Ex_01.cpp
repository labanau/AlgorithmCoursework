// Ex_01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
#include "BinarySearchTree_Node.h"
#include <fstream>

std::map<std::string, int> readFile();

void print(std::map<std::string, int> words);

int main()
{
	std::map<std::string, int> words;
	
	words = readFile();

	//print(words);

	BinarySearchTree_Node * root = new BinarySearchTree_Node(words.begin()->first, words.begin()->second);

	for (auto temp : words) {
		root->insertNode(temp.first, temp.second);
	}

	root->pre_orderBST(root);
	
	std::cout << std::endl;

	bool answer = root->searchBST(".txt.");

	answer ? std::cout << "Found\n" : std::cout << "Not Found\n";

    return 0;
}

std::map<std::string, int> readFile() {
	std::map<std::string, int> words;
	
	std::string temp;

	std::ifstream file("input.txt");

	while (file>>temp) { // Until the file finishes
		++words[temp];
	}
	file.close();

	return words;
}

void print(std::map<std::string, int> words) { // Will
	for (auto v : words) {
		std::cout << v.first << " : " << v.second << std::endl;
	}
}