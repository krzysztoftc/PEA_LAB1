/*
 * SolutionTree.cpp
 *
 *  Created on: 26 paź 2015
 *      Author: krzysztof
 */

#include "SolutionTree.h"
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

void SolutionTree::show(){
	std::cout<<"First matrix: "<<&firstMatrix<<std::endl;
	std::cout<<"bestSolution: "<<&bestSolution<<std::endl;
	std::cout<<"Show: \n"<<firstMatrix.toString();
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
//	std::cout<<"\nweszlo goDeeper"<<std::endl;
//	std::cout<<"First matrix: "<<&firstMatrix<<std::endl;
//	std::cout<<"bestSolution: "<<&bestSolution<<std::endl;

//	std::cout<<"\nMatrix w goDeeper:\n" <<std::endl;
//	std::cout<<this->firstMatrix.toString();
	std::cout<<"Root: "<<root<<std::endl;
	if (root == 0) {
		this -> root = new SolutionNode();
		root = this -> root;
		std::cout<<"Teraz root: "<<root<<std::endl;
		root->matrix = firstMatrix;
//		std::cout<<"\nMatrix w yfie:\n"<<root->matrix.toString();

		root->leftSon = 0;
		root->rightSon = 0;
//		std::cout<<"\nWeszlo1"<<std::endl;

		root->lowBound = root->matrix.reduction();
//		std::cout<<"\nWeszlo2"<<std::endl;
	}
//	std::cout<<"\nPrzeszlo"<<std::endl;

	std::cout<<"\nMatrix po kolejnym kroku:\n"<<root -> matrix.toString();

	if (root->matrix.getSize() > 3) {
		root->leftSon = new SolutionNode;
		SolutionNode *son = root->leftSon;
		son->leftSon = 0;
		son->rightSon = 0;
		son->matrix = root->matrix;
		son->lowBound += son->matrix.reduction();
		son->matrix.reduction();
		std::pair<int, int> best = son->matrix.maxMin();
		std::pair<int,int > vert = son->matrix.getVert(best);
		son -> matrix.removeEdge(best);
		if (son->trace.empty()) son->trace.push_back(vert.first);
		son ->trace.push_back(vert.second);
		goDeeper(son);
	}
	solution = root -> leftSon;

	return solution;
}


