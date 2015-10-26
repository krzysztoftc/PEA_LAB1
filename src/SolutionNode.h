/*
 * SolutionNode.h
 *
 *  Created on: 22 paź 2015
 *      Author: krzysztof
 */

#ifndef SOLUTIONNODE_H_
#define SOLUTIONNODE_H_

#include <list>
#include "MatrixCosts.h"

struct SolutionNode{
	MatrixCosts matrix;
	int lowBound;
	SolutionNode *leftSon;
	SolutionNode *rightSon;
	SolutionNode *parent;
	std::list<int> trace;
};



#endif /* SOLUTIONNODE_H_ */
