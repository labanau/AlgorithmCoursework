/**
CourseWork 210CT, Ex_01.cpp
Purpose: Ex_01.h : Declarations of the Ex_01 main programs entry point file

@author Rokas Labanauskas
*/

#pragma once

#include "stdafx.h"
#include <string>
#include <iostream>

/**
Read a paragraph of words from a file.

@return vector - with the words in the vector as string type
*/
std::vector<std::string> read_file();

/**
Count words frequencies.

@param words - vector where the words are stored

@return vector - which has the frequencies as int type;
*/
std::vector<int> count_freq_of_words(std::vector<std::string> words);

/**
Creates the BST tree.

@param words - Vector with words with which to create the tree
@param frequenc - Frequencies of the words appearing.

@return root - The created binary search tree.
*/
BinarySearchTree_Node * create_tree(std::vector<std::string> words, std::vector<int> frequenc);


/**
Print the words which where read from the file

@param words - vector with words as string type inside of it.
*/
void print(std::vector<std::string> words);
