/*
 * SolutionTree.cpp
 *
 *  Created on: 26 paź 2015
 *      Author: krzysztof
 */

#include "SolutionTree.h"
#include <list>
#include <climits>
//------------------------------------------------
//PAMIĘTAJ PROGRAMISTO MŁODY ZAWSZE ODRÓŻNIAJ ZMIENNE LOKALNE OD SKŁADNIKÓW KLASY !!!
// DIS <----- dej pozor :D
//------------------------------------------------
SolutionTree::SolutionTree(MatrixCosts &fMatrix) {
	// TODO Auto-generated constructor stub
	root = 0;
	bestSolution = 0;
	firstMatrix = fMatrix;
//	firstMatrix = MatrixCosts();
//	firstMatrix.generate(5);
//	std::cout<<"\nMatrix w konstruktorze:\n"<<this->firstMatrix.toString();
//	std::cout<<"First matrix: "<<&firstMatrix<<std::endl;
//	std::cout<<"bestSolution: "<<&bestSolution<<std::endl;

}

SolutionTree::~SolutionTree() {
	// TODO Auto-generated destructor stub
	destroy(root);
}

void SolutionTree::show() {
	std::cout << "First matrix: " << &firstMatrix << std::endl;
	std::cout << "bestSolution: " << &bestSolution << std::endl;
	std::cout << "Show: \n" << firstMatrix.toString();
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
		this->root = new SolutionNode();
		root = this->root;
		root->matrix = firstMatrix;
		root->parent = 0;

		root->leftSon = 0;
		root->rightSon = 0;

		root->lowBound = root->matrix.reduction();
	}

	if (root->matrix.getSize() > 3) {
		root->leftSon = new SolutionNode;
		SolutionNode *son = root->leftSon;
		son->parent = root;
		son->leftSon = 0;
		son->rightSon = 0;
		son->matrix = root->matrix;
		son->lowBound += son->matrix.reduction();
		son->trace = root->trace;
		std::pair<int, int> best = son->matrix.maxMin();
		std::pair<int, int> vert = son->matrix.getVert(best);
		son->matrix.removeEdge(best);
		son->trace.push_back(vert.first);
		son->trace.push_back(vert.second);

		goDeeper(son);
	} else {
		solution = root;

		if (!solution->trace.empty()) {
			solution->trace.push_back(solution->trace.front());
		}
	}
	return solution;
}

