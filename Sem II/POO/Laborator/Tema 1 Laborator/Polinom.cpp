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
		if (this->coef[this->grad] == 0) // Daca coef[grad] = 0, arunc o exceptie, intrucat gradul dominant nu poate fi 0
		{
			throw invalid_argument("Coeficientul dominant nu poate fi 0");
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
	unsigned int grad;
	input >> grad; // Citesc gradul
	p.grad = grad;
	delete[]p.coef; // Dezaloc memoria veche (in cazul in care a fost folosit constructorul cu parametrii inainte)
	p.coef = new double[p.grad + 1]; // Aloc memorie
	for (int i = 0; i <= p.grad; i++)
	{
		double coef;
		input >> coef; // Citesc coeficientii in vector
		p.coef[i] = coef;
	}
	if (p.coef[p.grad] == 0) // Daca v[grad] = 0, arunc o exceptie, intrucat gradul dominant nu poate fi 0
	{
		throw invalid_argument("Coeficientul dominant nu poate fi 0");
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
	delete[]this->coef; // Dezaloc memoria
	this->grad = p.grad;
	this->coef = new double[p.grad + 1]; // Aloc memorie noua
	for (int i = 0; i <= p.grad; i++)
	{
		this->coef[i] = p.coef[i]; // Copiez elementele din vector
	}
	return *this;
}

double& Polinom::operator()(const double& x)
{
	double valoare = 0;
	for (int i = 0; i <= this->grad; i++)
	{
		valoare += pow(x, i) * this->coef[i];
	}
	return valoare;
}

Polinom Polinom::operator+(const Polinom& p) const // Supraincarcarea operatorului '+'
{
	if (this->grad >= p.grad) // Cazul in care gradul polinomului din stanga >= gradul polinomului din dreapta
	{
		Polinom p3(this->grad); // Polinomul care va fi returnat
		for (int i = 0; i <= p.grad; i++)
		{
			p3.coef[i] = this->coef[i] + p.coef[i]; // Adaug in vectorul de coeficienti din p3 suma coeficientilor pana la gradul lui p
		}
		for (int i = p.grad + 1; i <= this->grad; i++)
		{
			p3.coef[i] = this->coef[i]; // Dupa adaug in vectorul de coeficienti din p3 ce a ramas din vectorul coeficientilor din polinomul din stanga
		}
		return p3;
	}
	else // Analog pentru cazul in care gradul polinomului din dreapta > gradul polinomului din stanga
	{
		Polinom p3(p.grad);
		for (int i = 0; i <= this->grad; i++)
		{
			p3.coef[i] = this->coef[i] + p.coef[i];
		}
		for (int i = this->grad + 1; i <= p.grad; i++)
		{
			p3.coef[i] = p.coef[i];
		}
		return p3;
	}
}

double& Polinom::operator[](unsigned int i) const // Supraincarcarea operatorului "[]"
{

	if (!(i >= 0 && i <= this->grad)) // Daca puterea data nu exista
	{
		throw range_error("Putere invalida"); 
	}
	return this->coef[i];
}

Polinom Polinom::operator*(const Polinom& p) const // Supraincarcarea operatorului '*' pentru inmultirea polinoamelor
{
	if (this->grad == 0 && this->coef[0] == 0) // Daca polinomul din stanga e polinomul 0, return polinomul 0
		return Polinom();
	if (p.grad == 0 && p.coef[0] == 0) // Analog pentru polinomul din dreapta
		return Polinom();
	Polinom p3(this->grad + p.grad);
	for (int i = 0; i <= p3.grad; i++)
	{
		p3.coef[i] = 0;
	}
	for (int i = 0; i <= this->grad; i++)
	{
		for (int j = 0; j <= p.grad; j++)
		{
			p3.coef[i + j] += this->coef[i] * p.coef[j];
		}
	}
	return p3;
}

Polinom Polinom::operator*(const int x) const // Supraincarcarea operatorului '*' pentru inmultirea cu un scalar la dreapta
{
	if (this->grad == 0 && this->coef[0] == 0 || x == 0) // Daca polinomul  0 sau x e 0, returnez polinomul 0
	{
		return Polinom();
	}
	Polinom p1 = *this;
	for (int i = 0; i <= p1.grad; i++)
	{
		p1.coef[i] *= x;
	}
	return p1;
}

Polinom operator*(const int x, const Polinom& p) // Supraincarcarea operatorului '*' pentru inmultirea cu un scalar la stanga
{
	if (p.grad == 0 && p.coef[0] == 0 || x == 0) // Daca polinomul  0 sau x e 0, returnez polinomul 0
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

Polinom Polinom::operator/(const Polinom& p) const// Supraincarcarea operatorului '/' pentru impartirea a doua polinoame
											// (se va imparti polinomul cu gradul mai mare la cel cu gradul mai mic)
{
	if ((this->grad == 0 && this->coef[0] == 0) && (p.grad == 0 && p.coef[0] == 0)) // Daca ambele polinoame sunt 0, impartirea la 0 nu are sens
	{
		throw range_error("Ambele polinoame sunt 0 - Impartirea nu are sens!");
	}
	if ((this->grad == 0 && this->coef[0] == 0) || (p.grad == 0 && p.coef[0] == 0)) // Daca unul dintre polinoame este 0, il returnez
	{
		return Polinom();
	}

	if (this->grad >= p.grad) // Cazul in care gradul polinomului din stanga este mai mare sau egal
	{
		Polinom p3(this->grad - p.grad); // p3 reprezinta catul care va fi returnat. Gradul catului va fi diferenta gradelor celor doua polinoame(in modul)
		Polinom* aux = new Polinom(); // copia lui p1(pointer), ca sa-i pot modifica gradul
		*aux = *this;
		int grad = p3.grad;
		for (int i = grad; i >= 0; i--) // parcurg vectorul coeficientilor catului(invers)
		{
			p3.coef[i] = aux->coef[aux->grad] / p.coef[p.grad]; // impartirea propriu-zisa ( de la grad mai mare la grad mai mic)
			for (int j = p.grad; j >= 0; j--) // scad din aux gradul curent din p3 * gradele polinomului din dreapta ( ca sa dea impartirea corect)
			{
				aux->coef[j + i] -= p3.coef[i] * p.coef[j];
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
		Polinom p3(p.grad - this->grad);
		Polinom* aux = new Polinom();
		*aux = p;
		int grad = p3.grad;
		for (int i = grad; i >= 0; i--)
		{
			p3.coef[i] = aux->coef[aux->grad] / this->coef[this->grad];
			for (int j = this->grad; j >= 0; j--)
			{
				aux->coef[j + i] -= p3.coef[i] * this->coef[j];
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
			int j = i - 1;
			while (v[j] == 0 && j > 0)
			{
				j--;
			}
			this->grad = j;
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