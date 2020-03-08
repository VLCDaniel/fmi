#pragma once
#include "Nod.h"
class Lista
{
	Nod* start, *end;
	int size;
public:
	Lista();
	Lista(int);
	Lista(int, int);
	Lista(Lista&);
	~Lista();
	void insert(int);
	void insertAt(int, int);
	int get(int);
	int length();
	void remove(int);
	void f(Lista&, int);
	Lista reverse();
	void removeFirst();
	void removeLast();
	bool hasDuplicates();
	bool has(int);
	bool isEmpty();
	void afisare();
};

