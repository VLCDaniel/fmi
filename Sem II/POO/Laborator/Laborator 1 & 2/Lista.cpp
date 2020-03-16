#include "Lista.h"
#include <iostream>
using namespace std;

Lista::Lista() // Constructorul fara parametrii
{
	this->start = NULL;
	this->end = NULL;
	this->size = 0;
}

Lista::Lista(int x) // Constructor cu un parametru - Lista cu un element
{
	Nod* p = new Nod();
	p->setInfo(x);
	this->end = p;
	this->start = p;
	this->size = 1;
}

Lista::Lista(int x, int y) // Constructor cu 2 parametrii - Lista cu x elemente, fiecare cu valoarea y
{
	this->size = x;
	Nod* p = new Nod(y, NULL);
	this->end = p;
	this->start = p;
	while (--x != 0)
	{
		Nod* p1 = new Nod(y, start);
		start = p1;
	}
}

void Lista::afisare() // Afiseaza informatiile despre toate elementele din lista
{
	if (this->size == 0)
	{
		cout << "Lista este vida";
	}
	else
	{
	Nod* p = start;
	while (p)
	{
		p->afisare();
		cout << "size = " << this->size << "\n\n";
		p = p->getNext();
	}
	cout << "Start: " << this->start << '\n';
	cout << "End: " << this->end << "\n\n";
	}
}

void Lista::insert(int x) // Inserarea unui element la final
{
	Nod* p = new Nod(x, start);
	this->start = p;
	this->size += 1;
	if (this->size == 1) // Daca lista era initial vida, trebuie si ca end sa pointeze catre elementul inserat
	{
		this->end = p;
	}
}

void Lista::insertAt(int x, int i) // Insereaza elementul x pe pozitia i, considerand ca indexarea incepe de la 0
{
	if (this->size == 0) // Daca lista este initial vida, avem un caz special
	{
		Nod* p = new Nod(x, NULL);
		this->start = p;
		this->end = p;
		this->size = 1;
	}
	else
	{
		if (i >= this->size) // Daca pozitia >= size, adaugam elementul pe ultima pozitie din lista
		{
			Nod* p = new Nod(x, NULL);
			this->end->setNext(p);
			this->end = p;
			this->size += 1;
		}
		else if (i <= 0) // Daca pozitia < 0, adaugam elementul pe prima pozitie din lista
		{
			Nod* p = new Nod(x, start);
			this->start = p;
			this->size += 1;
		}
		else // Altfel adaugam elementul pe pozitia x
		{
			Nod* p = start;
			while (i-- != 1)
			{
				p = p->getNext();
			}

			Nod* q = new Nod(x, p->getNext());
			p->setNext(q);
			this->size++;
		}
	}
}

int Lista::get(int i) // Intoarce elementul de pe pozitia i, INT_MAX daca i nu este un indice valid
{
	if (i < this->size && i >= 0) // I poate avea valori de la 0...(size - 1)
	{
		Nod* p = start;
		while (i-- != 0)
		{
			p = p->getNext();
		}
		return p->getInfo();
	}
	else 
	{
		return INT_MAX;
	}
}

int Lista::length() // Intoarce numarul de elemente din lista
{
	return this->size;
}

void Lista::remove(int i) // Sterge elementul de pe pozitia i
{
	if (i >= 0 && i < this->size)
	{
		if (i == 0)
		{
			Nod* p = start;
			start = start->getNext();
			delete p;
			this->size -= 1;
			return;
		}
		Nod* p = start;
		while (i-- != 1)
		{
			p = p->getNext();
		}
		Nod* q = p->getNext();
		p->setNext(q->getNext());
		delete q;
		this->size--;
	}
}

void Lista::f(Lista& l, int x) // Afiseaza lista l si adauga elementul x la final
{ // Observatie: lista primita ca parametru, l, este de fapt o copie, creata prin constructorul de copiere, asadar, modificarile aduse acesteia nu se salveaza din cauza 
  // constructorului de copiere default. Pentru a modifica lista, trebuie sa trimit functiei adresa listei.
	l.afisare();
	l.insert(x);
}

Lista::Lista(Lista& l) // Constructorul de copiere
{
	this->size = l.size;
	Nod* p = new Nod;
	Nod* q = l.start;
	this->start = p;
	while (q->getNext() != NULL)
	{
		p->setInfo(q->getInfo());
		p->setNext(new Nod);
		p = p->getNext();
		q = q->getNext();
	}
	p->setInfo(q->getInfo());
	p->setNext(NULL);
	this->end = p;
}

Lista::~Lista() // Destructorul Listei
{
	Nod* p = this->start;
	this->size = 0;
	while (this->start)
	{
		delete p;
		this->start = this->start->getNext();
		p = start;
	}
	this->end = NULL;
}

Lista Lista::reverse() // Returneaza o noua lista inversata
{
	if (this->size == 0)
	{
		Lista* l = new Lista();
		return *l;
	}
	Nod* p = this->start;
	Lista* l = new Lista(p->getInfo());
	p = p->getNext();
	while (p != NULL)
	{
		l->insertAt(p->getInfo(), 0);
		p = p->getNext();
	}
	return *l;
}

void Lista::removeFirst() // Sterge primul element din lista
{
	if (this->size == 0)
	{
		return;
	}
	this->size--;
	Nod* p = this->start;
	this->start = this->start->getNext();
	delete p;
}

void Lista::removeLast() // Sterge ultimul element din lista
{
	if (this->size == 0)
	{
		return;
	}
	this->size--;
	Nod* p = this->start;
	while (p->getNext() != this->end && p->getNext() != NULL)
	{
		p = p->getNext();
	}
	p->setNext(NULL);
	delete this->end;
	this->end = p;
}

bool Lista::hasDuplicates() // Intoarce true daca elementele listei sunt unice, false altfel
{
	if (this->size == 0 || this->size == 1)
	{
		return false;
	}
	Nod* p = this->start;
	while (p != NULL)
	{
		Nod* q = this->start;
		int nr = 0;
		while (q != NULL)
		{
			if (q->getInfo() == p->getInfo())
				nr++;
			q = q->getNext();
		}
		if (nr > 1)
			return true;
		p = p->getNext();
	}
	return false;
}

bool Lista::has(int x) // Returneaza true daca lista il contine pe x, false altfel
{
	if (this->size == 0)
		return false;
	Nod* p = this->start;
	while (p != NULL)
	{
		if (p->getInfo() == x)
			return true;
		p = p->getNext();
	}
	return false;
}

bool Lista::isEmpty() // Returneaza true daca lista nu contine elemente, false altfel
{
	if (this->size == 0)
	{
		return true;
	}
	return false;
}