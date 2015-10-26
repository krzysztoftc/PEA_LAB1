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
	MatrixCosts costs;
	cout << "Wczytany plik:\n";

	//costs.readFile("default.txt");
	costs.generate(5);

	cout << costs.toString();

	cout << "\nRedukcja:\n";

	cout << "LB: " << costs.reduction() << endl;

	cout << costs.toString();

	pair<int, int> best = costs.maxMin();
	cout << "Max z min = (" << best.first << " ; " << best.second << ")"
			<< endl;

	costs.removeEdge(best);

	cout << "Usuniecie luku: " << endl;
	cout << costs.toString() << endl;

	cout << "\nRedukcja:\n";

	cout << "LB: " << costs.reduction() << endl;

	cout << costs.toString() << endl;

	best = costs.maxMin();
	cout << "Max z min = (" << best.first << " ; " << best.second << ")"
			<< endl;
	costs.removeEdge(best);

	cout << "Usuniecie luku: " << endl;
	cout << costs.toString() << endl;

	cout << "\nRedukcja:\n";

	cout << "LB: " << costs.reduction() << endl;

	cout << costs.toString() << endl;

	cout << "blokowanie luku: " << endl;
	best = costs.maxMin();
	cout << "Max z min = (" << best.first << " ; " << best.second << ")"
			<< endl;
	cout << "Usuwany: " << costs.blockEdge(best) << endl;

	cout << costs.toString() << endl;

	return 0;
}
