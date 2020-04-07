#include <iostream>

int n, min, max;
int* v;

void citire()
{
	std::cout << "n= ";
	std::cin >> n;
	v = new int[n];
	std::cout << "v[0]= ";
	std::cin >> v[0];
	max = min = v[0];
	for (int i = 1; i < n; i++)
	{
		std::cout << "v[" << i << "]= ";
		std::cin >> v[i];
		if (v[i] < min)
		{
			min = v[i];
		}
		if (v[i] > max)
		{
			max = v[i];
		}
	}
}

int* x = new int[max - min + 1];
int* m = new int[n + 1];


int main()
{
	citire();
	for (int i = 0; i < max - min + 1; i++)
	{
		x[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		x[v[i] - min]++;
	}
	for (int i = 1; i < max - min + 1; i++)
	{
		x[i] += x[i - 1];
	}
	for (int i = 0; i < n; i++)
	{
		m[x[v[i] - min]] = v[i];
		x[v[i] - min]--;
	}
	for (int i = 1; i <= n; i++)
	{
		std::cout << m[i] << ' ';
	}
	delete[] v;
	delete[] x;
	delete[] m;
	return 0;
}