/*
 * SolutionTree.h
 *
 *  Created on: 26 paź 2015
 *      Author: krzysztof
 */

#ifndef SOLUTIONTREE_H_
#define SOLUTIONTREE_H_

#include "SolutionNode.h"

class SolutionTree {
	SolutionNode *root;
	SolutionNode *bestSolution;
	void destroy (SolutionNode *root);
	MatrixCosts firstMatrix;
public:
	SolutionTree(MatrixCosts &firstMatrix);
	SolutionNode* goDeeper(SolutionNode *root);
	void show();
	virtual ~SolutionTree();
};

#endif /* SOLUTIONTREE_H_ */
