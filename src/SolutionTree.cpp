/*
 * SolutionTree.cpp
 *
 *  Created on: 26 paź 2015
 *      Author: krzysztof
 */

#include "SolutionTree.h"

SolutionTree::SolutionTree() {
	// TODO Auto-generated constructor stub
	root = 0;
	bestSolution = 0;
}

SolutionTree::~SolutionTree() {
	// TODO Auto-generated destructor stub
	destroy(root);
}

void SolutionTree::destroy(SolutionNode *root) {
	if (root) {
		destroy(root->leftSon);
		destroy(root->rightSon);
		root -> leftSon = 0;
		root -> rightSon = 0;
		delete root;
	}
}

