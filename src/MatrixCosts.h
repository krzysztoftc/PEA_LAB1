/*
 * MatrixCosts.h
 *
 *  Created on: 22 paź 2015
 *      Author: krzysztof
 */

#ifndef MATRIXCOSTS_H_
#define MATRIXCOSTS_H_

#include <iostream>

class MatrixCosts {
	int **matrix;
	int size;
	void create();
	void remove();
public:
	MatrixCosts();
	void setCities(int cities);
	void readFile (std::string filename);
	void generate(int cities);
	int reduction();
	std::string toString();
	std::pair<int,int> maxMin();
	void removeEdge(std::pair <int, int> vert);
	int blockEdge(std::pair <int, int> vert);
	MatrixCosts(const MatrixCosts &matrixCosts);
	int getSize();
	int getCost(std::pair<int,int> edge);
	std::pair<int,int> getVert(std::pair <int,int> cords);
	MatrixCosts& operator= (MatrixCosts &m);
	virtual ~MatrixCosts();
};

#endif /* MATRIXCOSTS_H_ */
