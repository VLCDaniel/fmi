#pragma once
class Nod
{
	int info;
	Nod* next;
public:
	Nod();
	Nod(int, Nod*);
	~Nod();
	void setInfo(int);
	int getInfo();
	void setNext(Nod*);
	void afisare();
	Nod* getNext();
};

