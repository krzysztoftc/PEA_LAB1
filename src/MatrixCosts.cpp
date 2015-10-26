/*
 * MatrixCosts.cpp
 *
 *  Created on: 22 paź 2015
 *      Author: krzysztof
 */

#include "MatrixCosts.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <limits.h>

MatrixCosts::MatrixCosts() {
	matrix = 0;
	size = 0;
}

MatrixCosts::~MatrixCosts() {
	remove();
}

void MatrixCosts::create() {
	if (size == 0)
		return;

	if (matrix != 0)
		remove();

	matrix = new int*[size];

	for (int i = 0; i < size; i++) {
		matrix[i] = new int[size];
	}

	for (int i = 0; i < size; i++) {
		matrix[i][0] = i;
		matrix[0][i] = i;
	}
}

void MatrixCosts::remove() {
	if (matrix) {
		for (int i = 0; i < size; i++) {
			if (matrix[i])
				delete[] matrix[i], matrix[i] = 0;
		}

		delete[] matrix;
		matrix = 0;
	}
}

void MatrixCosts::readFile(std::string filename) {
	std::fstream input;
	input.open(filename.c_str(), std::ios::in);

	int in;

	remove();

	input >> in;
	size = in + 1;

	create();

	for (int i = 1; i < size; i++) {
		for (int j = 1; j < size; j++) {
			input >> in;
			matrix[i][j] = in;
		}
	}

	input.close();
}

std::string MatrixCosts::toString() {
	std::string toRet = "";

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			std::stringstream converter;
			converter << matrix[i][j];
			toRet += converter.str() + "\t";
		}
		toRet += "\n";
	}

	return toRet;
}

void MatrixCosts::generate(int cities) {
	remove();

	size = cities + 1;

	create();

	for (int i = 1; i < size; i++) {
		for (int j = 1; j < size; j++) {
			if (i == j)
				matrix[i][j] = -1;
			else
				matrix[i][j] = 1 + rand() % 50;
		}
	}
}

int MatrixCosts::reduction() {
	int bound = 0;
	int min;

	//redukcja wierszy
	for (int i = 1; i < size; i++) {
		min = INT_MAX;

		//szukanie min
		for (int j = 1; j < size; j++) {
			if (matrix[i][j] == 0) {
				min = 0;
				break;
			}
			if (matrix[i][j] > 0 && matrix[i][j] < min)
				min = matrix[i][j];
		}

//		std::cout << std::endl << min << std::endl;

		//redukcja
		if (min) {
			for (int j = 1; j < size; j++) {
				if (matrix[i][j] > 0) {
					matrix[i][j] -= min;
					bound += min;
				}
			}
		}
	}

	//redukcja kolumn
	for (int i = 1; i < size; i++) {
		min = INT_MAX;
		//szukanie min
		for (int j = 1; j < size; j++) {
			if (matrix[j][i] == 0) {
				min = 0;
				break;
			}

			if (matrix[j][i] > 0 && matrix[j][i] < min)
				min = matrix[j][i];
		}

//		std::cout << std::endl << min << std::endl;

		//redukcja
		if (min) {
			for (int j = 1; j < size; j++) {
				if (matrix[j][i] > 0) {
					matrix[j][i] -= min;
					bound += min;
				}
			}
		}
	}

	return bound;
}

//wybiera najwieksza sposrod minimalnych wartosci w wierszach i kolumnach
//zwraca pare <wiersz, kolumna> (indeksy macierzy)

std::pair<int, int> MatrixCosts::maxMin() {
	std::pair<int, int> toRet;
	std::pair<int, int> current;

	int currentMin = INT_MAX;
	int best = INT_MAX;

	//przeglad po wierszach
	for (int i = 1; i < size; i++) {
		bool zero = false;
		currentMin = INT_MAX;
		for (int j = 1; j < size; j++) {
			if (matrix[i][j] == 0) {
				//jesli sa przynajmniej dwa zera, to mozemy je wybrac
				if (zero == true) {
					toRet.first = i;
					toRet.second = j;
					currentMin = 0;
					return toRet;
				}

				else {
					zero = true;
				}
			}
			//wybor najlepszego w danym wierszu
			if (matrix[i][j] > 0) {
				if (currentMin > matrix[i][j]) {
					currentMin = matrix[i][j];
					current.first = i;
					current.second = j;
				}
			}
		}
		//wybor najlepszego we wszystkich wierszach
		if (best > currentMin) {
			best = currentMin;
			toRet = current;
		}
	}

	//przeglad po kolumnach
		for (int i = 1; i < size; i++) {
			bool zero = false;
			currentMin = INT_MAX;
			for (int j = 1; j < size; j++) {
				if (matrix[j][i] == 0) {
					//jesli sa przynajmniej dwa zera, to mozemy je wybrac
					if (zero == true) {
						toRet.first = i;
						toRet.second = j;
						currentMin = 0;
						return toRet;
					}

					else {
						zero = true;
					}
				}
				//wybor najlepszego w danym wierszu
				if (matrix[j][i] > 0) {
					if (currentMin > matrix[j][i]) {
						currentMin = matrix[j][i];
						current.first = i;
						current.second = j;
					}
				}
			}
			//wybor najlepszego we wszystkich wierszach
			if (best > currentMin) {
				best = currentMin;
				toRet = current;
			}
		}

	return toRet;
}
