#include <iostream>
using namespace std;

struct stiva
{
	int info;
	stiva* next;
}*top;

void push(int x)
{
	stiva *a = new stiva;
	a->info = x;
	a->next = top;
	top = a;
}

void pop()
{
	stiva* bob = top;
	int gigel = -1;
	if (top != NULL)
	{
		gigel = top->info;
		top = top->next;
		delete bob;
	}
}

void parcurgere(stiva* pointer) {
	cout << (*pointer).info;
	if ((*pointer).next != NULL)
		parcurgere(pointer->next);
}


int main()
{
	push(1);
	pop();
	push(2);
	push(3);
	parcurgere(top);
	return 0;
}
