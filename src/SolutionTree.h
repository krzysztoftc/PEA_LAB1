/*
 * SolutionTree.h
 *
 *  Created on: 26 paź 2015
 *      Author: krzysztof
 */

#ifndef SOLUTIONTREE_H_
#define SOLUTIONTREE_H_

#include "SolutionNode.h"
#include "Solution.h"
#include <climits>

class SolutionTree {
	SolutionNode *root;
	SolutionNode *bestSolution;
	void destroy (SolutionNode *root);
	MatrixCosts firstMatrix;
	int uBound = INT_MAX;
public:
	SolutionTree(MatrixCosts &firstMatrix);
	SolutionNode* goDeeper(SolutionNode *root);
	SolutionNode* goUp(SolutionNode *node);

	Solution findSolution();

	void show();
	virtual ~SolutionTree();
};

#endif /* SOLUTIONTREE_H_ */
