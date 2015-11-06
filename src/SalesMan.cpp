/*
 * SalesMan.cpp
 *
 *  Created on: 22 paź 2015
 *      Author: krzysztof
 */

#include "SalesMan.h"
#include <algorithm>
#include <list>
#include <climits>

SalesMan::SalesMan() {
	// TODO Auto-generated constructor stub

}

SalesMan::~SalesMan() {
	// TODO Auto-generated destructor stub
}

void SalesMan::readFile(std::string filename){
	matrix.readFile(filename);
}

std::string SalesMan::toString(){
	return matrix.toString();
}

void SalesMan::generate(int cities){
	matrix.generate(cities);
}

Solution SalesMan::exhausted() {
	int cities = matrix.getSize()-1;
	int *p = new int[cities];

	for (int i = 0; i < cities; i++) {
		p[i] = i+1;
	}

	std::list<int> currentTrace;
	std::list<int> minTrace;

	int currentCost = 0;
	int minCost = INT_MAX;


	do {
		currentCost = 0;
		currentTrace.clear();
		currentTrace.push_back(p[0]);
		for (int i = 1; i < cities; i++) {
			currentCost += matrix.getCost(std::pair <int,int>(currentTrace.back(),p[i]));
			currentTrace.push_back(p[i]);
		}
		currentCost += matrix.getCost(std::pair <int,int>(currentTrace.back(),p[0]));
		currentTrace.push_back(p[0]);

		if (currentCost < minCost) {
			minTrace = currentTrace;
			minCost = currentCost;
		}

	} while (std::next_permutation(p, p + cities));

	Solution s;

	s.trace = minTrace;
	s.cost = minCost;
	delete[] p;
	return s;
}
