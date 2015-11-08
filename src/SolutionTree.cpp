/*
 * SolutionTree.cpp
 *
 *  Created on: 26 paź 2015
 *      Author: krzysztof
 */

#include "SolutionTree.h"
#include <list>
#include <climits>
#include "Solution.h"

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
//	std::cout << "Wchodze do goDeeper root: " << root << std::endl;

	if (root == 0) {
		this->root = new SolutionNode();
		root = this->root;
		root->matrix = firstMatrix;
		root->parent = 0;

		root->leftSon = 0;
		root->rightSon = 0;

		root->lowBound = root->matrix.reduction();
		std::cout << "Matrix po redukcji" << std::endl;
		std::cout << root->matrix.toString() << std::endl;

	}

	if (root->matrix.getSize() > 3) {
		root->leftSon = new SolutionNode;
		SolutionNode *son = root->leftSon;
		son->parent = root;
		son->leftSon = 0;
		son->rightSon = 0;
		son->matrix = root->matrix;
		son->lowBound = root->lowBound;
		son->lowBound += son->matrix.reduction();
		std::cout << "Matrix po redukcji" << std::endl;
		std::cout << son->matrix.toString() << std::endl;

		son->trace = root->trace;
		son->visited = false;

		if (son->lowBound > uBound) {

//			std::cout << "wychodze" << std::endl;
			return 0;
		}
		if (!son->visited) {
			std::pair<int, int> best = son->matrix.maxMin();
			std::pair<int, int> vert = son->matrix.getVert(best);
			//std::cout<<"Max z min: "<<son->matrix.getCost(vert);

			std::pair<int, int> edge = son->matrix.removeEdge(vert);
			std::cout << "Matrix po usuwaniu" << std::endl;
			std::cout << son->matrix.toString() << std::endl;

			son->trace.push_back(vert.first);
			son->trace.push_back(vert.second);
			son->visited = true;

			std::cout << "(" << edge.first << ";" << edge.second << ")"
					<< std::endl;
		} else {
//			std::cout << "Cos pomijam" << std::endl;
		}
		return goDeeper(son);
	}

	else {
		solution = root;

		int r, c;
		std::pair<int,int> vert(1,1) ;
		for (vert.first = 1; vert.first < 3; vert.first++) {
			for (vert.second = 1; vert.second < 3; vert.second++) {
				if (solution -> matrix.getCost(vert) == 0){
					std::pair<int,int> ready = solution ->matrix.getVert(vert);
					std::swap(ready.first,ready.second);
					std::cout << "(" << ready.first << ";" << ready.second << ")"
										<< std::endl;
					root -> matrix.blockEdge(vert);
				}
			}
		}

		if (!solution->trace.empty()) {
			solution->trace.push_back(solution->trace.front());
		}

		if (bestSolution == 0 || solution->lowBound < bestSolution->lowBound) {
			bestSolution = solution;
			uBound = solution->lowBound;
		}
//		std::cout << "GoDeeper zwraca: " << root << std::endl;
		return solution;
	}

//	std::cout << "Cout przy return 0" << std::endl;
	return root;
}

SolutionNode* SolutionTree::goUp(SolutionNode *node) {
//	std::cout << "GoUp node = " << node << std::endl;
	SolutionNode *parent = node->parent;

	if (parent) {
//		std::cout << "Wchodze w prawego syna!" << std::endl;
		if (parent->matrix.getSize() > 3) {
			parent->rightSon = new SolutionNode;
			SolutionNode *son = parent->rightSon;
			son->visited = true;
			son->parent = parent;
			son->leftSon = 0;
			son->rightSon = 0;
			son->matrix = parent->matrix;
			son->trace = parent->trace;
			son->lowBound += son->matrix.reduction();

			std::pair<int, int> best = son->matrix.maxMin();
//			std::cout << "best (" << best.first << " , " << best.second << ")"
//					<< std::endl;
			std::pair<int, int> vert = son->matrix.getVert(best);

			son->matrix.blockEdge(vert);
			std::cout << "Matrix po blokowaniu" << std::endl;
			std::cout << son->matrix.toString() << std::endl;

			if (son->lowBound < uBound) {
				goUp(goDeeper(son));
			}
		}
	}

	return 0;
}

Solution SolutionTree::findSolution() {
	Solution solution;
	SolutionNode *n = goDeeper(0);
//	std::cout << "findSolution *n: " << n << std::endl;
	goUp(n);

	solution.trace = bestSolution->trace;
	solution.cost = 0;

	/*std::list<int>::iterator it = solution.trace.begin();
	 while (++it != solution.trace.end()) {
	 solution.cost += bestSolution->matrix.getCost(
	 std::pair<int, int>(*(--it), *(++it)));
	 }
	 solution.cost += bestSolution->matrix.getCost(
	 std::pair<int, int>(bestSolution->trace.back(),
	 bestSolution->trace.front()));
	 */
	return solution;
}

