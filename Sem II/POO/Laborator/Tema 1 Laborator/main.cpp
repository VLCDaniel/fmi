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

	assert(p[0] == -1 && p[1] == 0 && p[2] == 1 && p[3] == 0 && p[4] == 0 && p.getGrad() == 5); // Verificarea constructorului cu parametrii

	Polinom p1; // Constructor fara parametrii

	assert(p1.getGrad() == 0 && p1[0] == 0); // Verificarea constructorului fara parametrii

	f >> p1; // Citirea prin supraincarcare

	assert(p1.getGrad() == 2 && p1[0] == 2 && p1[1] == -1 && p1[2] == 1); // Verificare citire prin supraincarcare

	Polinom copy;
	copy = p1; // Supraincarcare '='

	assert(copy.getGrad() == 2 && copy[0] == 2 && copy[1] == -1 && copy[2] == 1); // Verificare '='

	cout << copy; // Afisare prin supraincarcare

	v[0] = 1;
	v[1] = 0;
	v[2] = 1;
	Polinom p2(2, v);
	Polinom p3;

	p3 = p1 + p2; // Supraincarcare adunare

	assert(p3.getGrad() == 2 && p3[0] == 3 && p3[1] == -1 && p3[2] == 2); // Verific daca adunarea e facuta corect

	cout << p3;

	cout << p(1) << '\n'; // Calculul lui p(1)

	//cout << p[10] << '\n'; // Gradul introdus nu exista - eroare tratata

	p3 = p1 * 5; // Inmultirea cu un scalar

	assert(p3.getGrad() == 2 && p3[0] == 10 && p3[1] == -5 && p3[2] == 5); // Verific inmultirea cu un scalar

	cout << p3;

	p3 = p1 * p2; // Inmultirea intre doua polinoame

	assert(p3.getGrad() == 4 && p3[0] == 2 && p3[1] == -1 && p3[2] == 3 && p3[3] == -1 && p3[4] == 1); // Verific inmultirea polinoamelor

	cout << p3;

	assert((p2 * p).getGrad() == (p2.getGrad() + p.getGrad())); // Verific daca inmultirea polinoamelor e corecta : prin verificarea gradelor

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

	p3 = p / p1; // Impartirea polinoamelor

	assert(p3.getGrad() == 3 && p3[0] == -5 && p3[1] == -2 && p3[2] == 2 && p3[3] == 2); // Verific impartirea polinoamelor

	cout << p3; 

	p.adaugare(5, 10); // Adaugarea unui element

	assert(p.getGrad() == 10 && p[10] == 5); // Verific adaugarea

	cout << p; 

	p.eliminare(10); // Eliminarea unui element

	assert(p.getGrad() == 5); // Verific eliminarea

	cout << p;

	return 0;
}