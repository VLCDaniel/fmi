#include "Nod.h"
#include <iostream>
#include <cstring>
using namespace std;

Nod::Nod() // Constructor fara parametrii
{
	this->info = 0;
	this->next = NULL;
}

Nod::Nod(int info, Nod* next) // Constructor cu parametrii
{
	this->info = info;
	this->next = next;
}

Nod::~Nod() // Nu e nevoie de destructor
{
	//Obiect distrus
}

void Nod::afisare() // Afiseaza informatia din nod si adresa la care pointeaza next(in hexa)
{
	cout<< "Informatie nod: " << this->info<< '\n'<< "Adresa de memorie(hexa): ";
	printf("%p\n", this->next);
}

void Nod::setInfo(int info) // Seteaza valoarea din campul info
{
	this->info = info;
}

int Nod::getInfo() // Intoarce valoarea din campul info
{
	return this->info;
}

void Nod::setNext(Nod* next) // Setez pointerul next din nod catre pointerul trimis ca parametru
{
	this->next = next;
}

Nod* Nod::getNext() // Intorc valoarea aflata in campul next
{
	return this->next;
}