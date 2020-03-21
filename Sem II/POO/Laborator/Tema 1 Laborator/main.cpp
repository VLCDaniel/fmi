#include <iostream>
#include <fstream>
#include <assert.h>
#include "Polinom.h"
using namespace std;

int main()
{
	ifstream f("Polinom.txt");
	double v[6] = {-1, 0, 1, 0, 0, 2};
	Polinom p(5, v); // Constructor cu parametrii
	Polinom p1; // Constructor fara parametrii
	f >> p1; // Citirea prin supraincarcare
	Polinom copy = p1; // Constructorul de copiere + supraincarcare '='
	cout << copy; // Afisare prin supraincarcare

	Polinom p2;
	Polinom p3;

	p2 = p + p1; // Supraincarcare adunare
	assert((p + p1).getGrad() == (p.getGrad())); // Verific daca adunarea e facuta corect - prin grad
	cout << p2;

	cout << p.calcul(1) << '\n'; // Calculul lui p(1)

	//cout << p[10]; // Gradul introdus nu exista - eroare tratata
	
	p3 = 5 * p1; // Inmultirea cu un scalar
	cout << p3;

	p3 = p2 * p; // Inmultirea intre doua polinoame
	cout << p3;

	assert((p2 * p).getGrad() == (p2.getGrad() + p.getGrad())); // Verific daca inmultirea polinoamelor e corecta - prin verificarea gradelor

	/*
	Polinom p4;
	Polinom p5;
	try // Daca ambele polinoame sunt 0, impartirea nu are sens, deci afisez un mesaj
	{
		cout << p4 / p5;
	}
	catch (int e)
	{
		cout << "Ambele polinoame sunt 0. Impartirea nu are sens!";
		exit(-1);
	} 
	*/

	cout << p / p1; // Impartirea polinoamelor

	p.adaugare(5, 10);
	cout << p; // Adaugarea unui element

	p.eliminare(10);
	cout << p; // Eliminarea unui element

	return 0;
}