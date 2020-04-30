#pragma once
using namespace std;

class Polinom
{
private:
	unsigned int grad; // gradul polinomului
	double* coef; // pointer catre vector de coeficienti, alocat dinamic. Fiecare index (de la 0) reprezinta puterea lui x si valoarea din vector -  coeficientul.
public:
	Polinom(); // constructor fara parametrii
	Polinom(unsigned int, double[] = nullptr); // constructor cu parametrii
	Polinom(const Polinom&); // constructor de copiere
	~Polinom(); // destructor
	friend istream& operator>>(istream&, Polinom&); // supraincarc citirea
	friend ostream& operator<<(ostream&, const Polinom&); // supraincarc afisarea
	Polinom& operator=(const Polinom&); // supraincarc '='
	double operator()(const double&); // calculeaza valoarea polinomului
	Polinom operator+(const Polinom&) const; // supraincarcarea operatorului '+'
	double& operator[](unsigned int) const; // supraincarcarea operatorului '[]'
	Polinom operator*(const Polinom&) const; // supraincarcarea operatorului '*' pentru inmultirea a 2 polinoame
	Polinom operator*(const int) const; // supraincarcarea operatorului '*' pentru inmultirea cu un scalar la dreapta
	friend Polinom operator*(const int, const Polinom&); // supraincarcarea operatorului '*' pentru inmultirea cu un scalar la stanga
	Polinom operator/(const Polinom&) const; // supraincarcarea operatorului '/' pentru impartirea polinoamelor
	void adaugare(double, int); // adaugarea unui termen de grad i
	void eliminare(int); // eliminarea unui termen de grad i
	int getGrad() const; // metoda care intoarce gradul polinomului
};
