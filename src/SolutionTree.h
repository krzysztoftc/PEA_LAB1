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
public:
	SolutionTree();

	virtual ~SolutionTree();
};

#endif /* SOLUTIONTREE_H_ */
