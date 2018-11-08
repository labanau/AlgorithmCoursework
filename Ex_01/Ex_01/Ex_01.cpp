// Ex_01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include "BinarySearchTree_Node.h"
#include <fstream>

std::vector<std::string> readFile();

std::vector<int> countFreqOfWord(std::vector<std::string> words);

void print(std::vector<std::string> words);

int main()
{
	std::vector<std::string> words;
	std::vector<int> frequenc;
	
	words = readFile();
	frequenc = countFreqOfWord(words);
	//print(words);
	std::cout << words[0] << " : " << frequenc[0] << std::endl;
	BinarySearchTree_Node * root = new BinarySearchTree_Node(words[0], frequenc[0]);

	for (int i = 0; i < words.size(); i++) {
		root->insertNode(words[i], frequenc[i]);
	}

	root->pre_orderBST(root);
	
	std::cout << std::endl;

	bool answer = root->searchBST(".txt.");

	answer ? std::cout << "Found\n" : std::cout << "Not Found\n";

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
	int count = 0;
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

void print(std::vector<std::string> words) { // Will
	for (auto v : words) {
		std::cout << v << std::endl;
	}
}