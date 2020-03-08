#include <iostream>
#include "Nod.h"
#include "Lista.h"
using namespace std;
int main()
{
	// Test Nod
	/*

	Nod p;
	p.afisare();
	cout << '\n';

	Nod q(1, &p);
	q.afisare();
	cout << '\n';

	Nod r;
	r.setInfo(2);
	cout << r.getInfo() << '\n';
	r.setNext(&q);
	r.afisare();
	cout << '\n';

	//getNext:
	Nod* s;
	s = r.getNext();
	s->afisare();
	*/
	// Test lista - constructor cu doi parametri
	/*
	Lista l1(3,2);
	l1.afisare();
	*/
	// Test lista - metoda insert
	/*
	Lista l1(10);
	l1.insert(20);
	l1.afisare();
	*/

	// Test lista - metoda insertAt
	Lista l(1);
	l.insertAt(2, 0);
	l.insertAt(3, 100);
	l.insertAt(4, -1);
	l.afisare();
	// Metoda get
	cout << "-----------------------------------\n";
	cout << "Metoda get(3): " << l.get(3) << '\n';
	// Metoda length
	cout << "Metoda length: " << l.length() << "\n\n";
	cout << "-----------------------------------\n";

	// Metoda remove
	l.remove(0);
	cout << "-----------------------------------\n";

	// Metoda f
	l.f(l, 10);
	cout << "-----------------------------------\n";
	l.f(l, 10);
	cout << "-----------------------------------\n"; // Observatia din lista.cpp de la functia f
	l.afisare();
	cout << "-----------------------------------\n";

	// Metodele removeFirst si removeLast
	l.removeFirst();
	l.afisare();
	cout << "-----------------------------------\n";

	l.removeLast();
	l.afisare();
	cout << "-----------------------------------\n";

	// Metoda hasDuplicates
	cout << l.hasDuplicates() << '\n';
	l.insert(10);
	cout << l.hasDuplicates() << '\n';

	// Metoda has
	cout << l.has(10) << '\n';

	// Metoda reverse
	l.reverse().afisare(); 
	cout << "-----------------------------------\n";
	return 0;
}