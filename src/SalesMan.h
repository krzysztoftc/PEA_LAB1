/*
 * SalesMan.h
 *
 *  Created on: 22 paź 2015
 *      Author: krzysztof
 */

#ifndef SALESMAN_H_
#define SALESMAN_H_

#include "MatrixCosts.h"
#include "Solution.h"

class SalesMan {
	MatrixCosts matrix;

public:
	SalesMan();
	void readFile (std::string filename);
	std::string toString();
	void generate (int cities);
	Solution exhausted();
	virtual ~SalesMan();
};

#endif /* SALESMAN_H_ */
