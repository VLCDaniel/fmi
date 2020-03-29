#include <iostream>
using namespace std;

struct stiva
{
	int info;
	stiva* next;
}*top;

void push(int x)
{
	stiva* a = new stiva;
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

int main()
{
	int n;
	cin >> n;
	int* v = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
		if (top == NULL || top->info == v[i])
		{
			push(v[i]);
		}
		else
		{
			pop();
		}
    }

	if (top == NULL)
	{
		cout << "Nu exista element majoritar";
	}
	else
	{
		int aparitii = 0;
		for (int i = 0; i < n; i++)
		{
			if (v[i] == top->info)
			{
				aparitii++;
			}
		}
		if (aparitii > n / 2)
		{
			cout << "Elementul majoritar este: " << top->info;
		}
		else
		{
			cout << "Nu exista element majoritar";
		}
	}
	delete[]v;
	return 0;
}
