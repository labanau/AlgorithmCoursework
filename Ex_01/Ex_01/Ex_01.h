/**
CourseWork 210CT, Ex_01.cpp
Purpose: Ex_01.h : Declarations of the Ex_01 main programs entry point file

@author Rokas Labanauskas
*/

#pragma once

#include "stdafx.h"
#include <string>
#include <iostream>

std::vector<std::string> readFile();

std::vector<int> countFreqOfWord(std::vector<std::string> words);

BinarySearchTree_Node * createTree(std::vector<std::string> words, std::vector<int> frequenc);

void print(std::vector<std::string> words);
