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
	virtual ~MatrixCosts();
};

#endif /* MATRIXCOSTS_H_ */
