/*
 * SolutionTree.cpp
 *
 *  Created on: 26 paź 2015
 *      Author: krzysztof
 */

#include "SolutionTree.h"
#include <climits>

SolutionTree::SolutionTree(MatrixCosts firstMatrix) {
	// TODO Auto-generated constructor stub
	root = 0;
	bestSolution = 0;
	this->firstMatrix = firstMatrix;
}

SolutionTree::~SolutionTree() {
	// TODO Auto-generated destructor stub
	destroy(root);
}

void SolutionTree::destroy(SolutionNode *root) {
	if (root) {
		destroy(root->leftSon);
		destroy(root->rightSon);
		root->leftSon = 0;
		root->rightSon = 0;
		delete root;
	}
}

SolutionNode* SolutionTree::goDeeper(SolutionNode *root) {
	SolutionNode *solution = 0;
	if (root == 0) {
		root = new SolutionNode();
		root->matrix = firstMatrix;
		root->leftSon = 0;
		root->rightSon = 0;
		root->lowBound = root->matrix.reduction();
	}

	if (root->matrix.getSize() > 2) {
		root->leftSon = new SolutionNode;
		SolutionNode *son = root->leftSon;
		son->leftSon = 0;
		son->rightSon = 0;
		son->matrix = root->matrix;
		son->lowBound += son->matrix.reduction();
		son->matrix.reduction();
	}

	return solution;
}
