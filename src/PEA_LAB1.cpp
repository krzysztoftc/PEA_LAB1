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
#include "SolutionTree.h"

using namespace std;

int main() {
	srand(time(0));

	SalesMan seller;
	MatrixCosts costs;
	cout << "Wczytany plik:\n";

	seller.readFile("default.txt");
	cout << seller.toString();

	Solution s = seller.exhausted();

	list<int>::iterator it = s.trace.begin();
	cout << endl << *it++;
	while (it != s.trace.end()) {
		cout << " -> " << *it++;
	}
	cout << endl << "cost: " << s.cost << endl;

	costs.readFile("default.txt");
//	costs.generate(5);

	SolutionTree tree(costs);
//	tree.show();
	s = tree.findSolution();

	it = s.trace.begin();
	cout << endl << *it++;
	while (it != s.trace.end()) {
		cout << " -> " << *it++;
	}
	cout << endl << "cost: " << s.cost << endl;

//	cout << costs.toString()<<endl;
////
//	MatrixCosts costs2 = costs;
//	costs2.generate(4);
//	cout << costs.toString()<<endl;
//	cout << costs2.toString()<<endl;

//	cout << "\nRedukcja:\n";
//
//	cout << "LB: " << costs2.reduction() << endl;
//
//	cout << costs2.toString();

	/*	pair<int, int> best = costs.maxMin();
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
	 */
	return 0;
}
