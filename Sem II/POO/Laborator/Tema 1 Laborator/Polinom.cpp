#include<iostream>
#include<math.h>
#include "Polinom.h"
using namespace std;

Polinom::Polinom() : grad(0), coef(new double[1]) // Constructor fara parametrii
{
	this->coef[0] = 0;
}

Polinom::Polinom(unsigned int x, double v[]) // Constructor cu parametrii
{
	if (v) // Daca vectorul de coeficienti este dat
	{
		this->grad = x;
		this->coef = new double[x + 1]; // Aloc memorie pentru vectorul coeficientilor
		for (int i = 0; i <= x; i++)
		{
			coef[i] = v[i]; // Adaug coeficientii in vector
		}
	}
	else // Daca nu dau coeficientii, vreau sa initializez toti coeficientii cu 0
	{
		this->grad = x;
		this->coef = new double[x + 1];
		for (int i = 0; i <= this->grad; i++)
		{
			this->coef[i] = 0;
		}
	}
}

Polinom::Polinom(const Polinom& p) // Constructorul de copiere
{
	this->grad = p.grad;
	this->coef = new double[this->grad + 1]; // Aloc memorie noua
	for (int i = 0; i <= p.grad; i++)
	{
		this->coef[i] = p.coef[i]; // Copiez elementele din vector
	}
}

Polinom::~Polinom() // Destructor
{
	this->grad = 0;
	delete[]this->coef;
	this->coef = nullptr;
}

istream& operator>>(istream& input, Polinom& p) // Supraincarcarea operatorului de citire '>>'
{
	input >> p.grad; // Citesc gradul
	delete[]p.coef; // Dezaloc memoria veche (in cazul in care a fost folosit constructorul cu parametrii inainte)
	p.coef = new double[p.grad + 1]; // Aloc memorie
	for (int i = 0; i <= p.grad; i++)
	{
		input >> p.coef[i]; // Citesc coeficientii in vector
	}
	try // Daca v[grad] = 0, arunc o exceptie, intrucat gradul dominant nu poate fi 0
	{
		if (p.coef[p.grad] == 0)
		{
			throw p.grad;
		}
	}
	catch (unsigned int grad)
	{
		cout << "Coeficientul dominant nu poate fi 0";
		exit(-1);
	}
	return input;
}

ostream& operator<<(ostream& output, const Polinom& p) // Supraincarcarea operatorului de afisare '<<'
{
	for (int i = p.grad; i > 0; i--)
	{
		if (p.coef[i] > 0)
		{
			output << p.coef[i] << "*x^" << i << " + ";
		}
		if (p.coef[i] < 0)
		{
			output << '(' << p.coef[i] << ')' << "*x^" << i << " + ";
		}
	}
	if (p.coef[0] > 0)
	{
		output << p.coef[0];
	}
	if (p.coef[0] < 0)
	{
		output << '(' << p.coef[0] << ')';
	}
	if (p.grad == 0 && p.coef[0] == 0)
	{
		output << 0;
	}
	output << '\n';
	return output;
}

Polinom& Polinom::operator=(const Polinom& p) // Supraincarcarea operatorului '='
{
	if (this == &p) // Daca cele doua polinoame sunt egale, nu fac nimic
		return *this;
	//delete[]this->coef; // Dezaloc memoria
	this->grad = p.grad;
	this->coef = new double[p.grad + 1]; // Aloc memorie noua
	for (int i = 0; i <= p.grad; i++)
	{
		this->coef[i] = p.coef[i]; // Copiez elementele din vector
	}
	return *this;
}

double Polinom::calcul(double x) // Calculez valoarea polinomului in x
{
	double valoare = 0;
	for (int i = 0; i <= this->grad; i++)
	{
		valoare += pow(x, i) * this->coef[i];
	}
	return valoare;
}

Polinom operator+(const Polinom& p1, const Polinom& p2) // Supraincarcarea operatorului '+'
{
	Polinom p3;
	if (p1.grad >= p2.grad) // Cazul in care gradul lui p1 >= gradul lui p2
	{
		p3.grad = p1.grad;
		p3.coef = new double[p3.grad + 1];
		for (int i = 0; i <= p2.grad; i++)
		{
			p3.coef[i] = p1.coef[i] + p2.coef[i]; // Adaug in vectorul de coeficienti din p3 suma coeficientilor pana la gradul lui p2
		}
		for (int i = p2.grad + 1; i <= p1.grad; i++)
		{
			p3.coef[i] = p1.coef[i]; // Dupa adaug in vectorul de coeficienti din p3 ce a ramas din vectorul coeficientilor din p1
		}
	}
	else // Analog pentru cazul in care gradul lui p2 > gradul lui p1
	{
		p3.grad = p2.grad;
		p3.coef = new double[p2.grad];
		for (int i = 0; i <= p1.grad; i++)
		{
			p3.coef[i] = p1.coef[i] + p2.coef[i];
		}
		for (int i = p1.grad + 1; i <= p2.grad; i++)
		{
			p3.coef[i] = p2.coef[i];
		}
	}
	return p3;
}

double Polinom::operator[](unsigned int i) // Supraincarcarea operatorului "[]"
{
	try
	{
		if (!(i >= 0 && i <= this->grad))
		{
			throw this->coef[i];
		}
	}
	catch (...)
	{
		cout << "Gradul introdus nu exista";
		exit(-1);
	}
}

Polinom operator*(const Polinom& p1, const Polinom& p2) // Supraincarcarea operatorului '*' pentru inmultirea polinoamelor
{
	if (p1.grad == 0 && p1.coef[0] == 0) // Daca p1 e polinomul 0, return polinomul 0
		return Polinom();
	if (p2.grad == 0 && p2.coef[0] == 0) // Analog pentru p2
		return Polinom();
	Polinom p3;
	p3.grad = p1.grad + p2.grad;
	p3.coef = new double[p3.grad + 1];
	for (int i = 0; i <= p3.grad; i++)
	{
		p3.coef[i] = 0;
	}
	for (int i = 0; i <= p1.grad; i++)
	{
		for (int j = 0; j <= p2.grad; j++)
		{
			p3.coef[i + j] += p1.coef[i] * p2.coef[j];
		}
	}
	return p3;
}

Polinom operator*(const int& x, Polinom const& p) // Supraincarcarea operatorului '*' pentru inmultirea cu un scalar la stanga
{
	if (p.grad == 0 && p.coef[0] == 0 || x == 0) // Daca p e polinomul 0 sau x e 0, returnez polinomul 0
	{
		return Polinom();
	}
	Polinom p1 = p;
	for (int i = 0; i <= p1.grad; i++)
	{
		p1.coef[i] *= x;
	}
	return p1;
}

Polinom operator*(Polinom const& p, const int& x) // Supraincarcarea operatorului '*' pentru inmultirea cu un scalar la dreapta
{
	return x * p;
}

Polinom operator/(const Polinom& p1, const Polinom& p2) // Supraincarcarea operatorului '/' pentru impartirea a doua polinoame (se va imparti polinomul cu gradul mai mare la cel cu gradul mai mic)
{
	if ((p1.grad == 0 && p1.coef[0] == 0) && (p2.grad == 0 && p2.coef[0] == 0)) // Daca ambele polinoame sunt 0, impartirea la 0 nu are sens
	{
		throw - 1;
	}
	if ((p1.grad == 0 && p1.coef[0] == 0) || (p2.grad == 0 && p2.coef[0] == 0)) // Daca p1 este polinomul 0 sau p2 este polinomul 0, il returnez
	{
		return Polinom();
	}

	if (p1.grad >= p2.grad) // Cazul in care gradul lui p1 este mai mare sau egal
	{
		Polinom p3(p1.grad - p2.grad); // p3 reprezinta catul care va fi returnat. Gradul catului va fi diferenta gradelor celor doua polinoame(in modul)
		Polinom* aux = new Polinom(); // copia lui p1(pointer), ca sa-i pot modifica gradul
		*aux = p1;
		int grad = p3.grad;
		for (int i = grad; i >= 0; i--) // parcurg vectorul coeficientilor catului(invers)
		{
			p3.coef[i] = aux->coef[aux->grad] / p2.coef[p2.grad]; // impartirea propriu-zisa ( de la grad mai mare la grad mai mic)
			for (int j = p2.grad; j >= 0; j--) // scad din aux gradul curent din p3 * gradele din p2 ( ca sa dea impartirea corect)
			{
				aux->coef[j + i] -= p3.coef[i] * p2.coef[j];
			}
			aux->grad--;
			while (aux->coef[aux->grad] == 0) // ignor coeficientii cu 0 pentru eficienta
			{
				aux->grad--;
			}
		}
		delete aux;
		return p3;
	}

	else // analog, doar ca suntem in cazul in care gradul lui p2 > gradul lui p1
	{
		Polinom p3(p2.grad - p1.grad);
		Polinom* aux = new Polinom();
		*aux = p2;
		int grad = p3.grad;
		for (int i = grad; i >= 0; i--)
		{
			p3.coef[i] = aux->coef[aux->grad] / p1.coef[p1.grad];
			for (int j = p1.grad; j >= 0; j--)
			{
				aux->coef[j + i] -= p3.coef[i] * p1.coef[j];
			}
			aux->grad--;
			while (aux->coef[aux->grad] == 0)
			{
				aux->grad--;
			}
		}
		delete aux;
		return p3;
	}
}

void Polinom::adaugare(double x, int i) // Adaugarea unui termen de grad i
{
	if (i >= 0) // ma intereseaza gradele pozitive
	{
		if (i > this->grad) // daca gradul pe care vreau sa-l adaug e mai mare decat cel al polinomului
		{
			double* v = new double[i + 1]; // aloc memorie pentru un nou vector
			for (int j = 0; j <= this->grad; j++) // copiez elementele vechi in el
			{
				v[j] = this->coef[j];
			}
			for (int j = this->grad + 1; j < i; j++) // initializez elementele dintre gradul vechi si cel nou cu 0
			{
				v[j] = 0;
			}
			v[i] = x; // adaug elementul de grad i
			this->grad = i;
			delete[] this->coef;
			this->coef = v;
		}
		else
		{
			if (this->coef[i] != 0) // daca elementul pe care vreau sa-l adaug deja exista, adun coeficientii
			{
				this->coef[i] += x;
			}
			else // altfel, il initializez
			{
				this->coef[i] = x;
			}
		}
	}
}

void Polinom::eliminare(int i) // Eliminarea unui termen de grad i din polinom
{
	if (i >= 0 && i <= this->grad) // ma intereseaza doar gradele existente
	{
		if (i == this->grad) // daca vreau sa elimin gradul dominant
		{
			double* v = new double[i];
			for (int j = 0; j < i; j++)
			{
				v[j] = this->coef[j];
			}
			this->grad = i - 1;
			delete[] this->coef;
			this->coef = v;
		}
		else
		{
			this->coef[i] = 0;
		}
	}
}

int Polinom::getGrad() const // Metoda care returneaza gradul polinomului
{
	return this->grad;
}