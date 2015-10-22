//============================================================================
// Name        : PEA_LAB1.cpp
// Author      : Kinga & Krzysztof
// Version     :
// Copyright   : Copyright 2015: Kinga Wilczek 210063 & Krzysztof Cabala 210047 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "SalesMan.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
	srand(time(0));

	SalesMan seller;

	cout << "Wczytany plik:\n";

	seller.readFile("default.txt");

	cout << seller.toString();

	cout << "\nWlosowy:\n";

	seller.generate(4);

	cout << seller.toString();

	return 0;
}
