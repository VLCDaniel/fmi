#include <iostream>

int v[100], n, ord[100];

int cifre(int x)
{
	if (x != 0)
	{
		return 1 + cifre(x / 10);
	}
	return 0;
}

void count_sort(int p)
{
	int aux[10] = { 0 };
	for (int i = 0; i < n; i++)
	{
		aux[(v[i] / p) % 10]++;
	}
	for (int i = 1; i <= 9; i++)
	{
		aux[i] += aux[i - 1];
	}
	for (int i = n-1; i >= 0; i--)
	{
		ord[aux[(v[i] / p) % 10] - 1] = v[i];
		aux[(v[i] / p) % 10]--;
	}
	for (int i = 0; i < n; i++)
	{
		v[i] = ord[i];
	}
}

int main()
{
	int nr = 0, p = 1;
	std::cout << "n= ";
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cout << "v[" << i << "]= ";
		std::cin >> v[i];
		if (cifre(v[i]) > nr)
		{
			nr = cifre(v[i]);
		}
	}
	while(nr!=0)
	{
		count_sort(p);
		p *= 10;
		nr--;
	}
	for (int i = 0; i < n; i++)
	{
		std::cout << v[i] << ' ';
	}
	return 0;
}