/*
 * SalesMan.cpp
 *
 *  Created on: 22 paź 2015
 *      Author: krzysztof
 */

#include "SalesMan.h"

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

