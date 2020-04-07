#include <iostream>

int v[100], n, ord[100];

void count_sort(int x)
{
	int aux[256] = { 0 };
	for (int i = 0; i < n; i++)
	{
		aux[(v[i] >> x) & 255]++;
	}
	for (int i = 1; i <= 255; i++)
	{
		aux[i] += aux[i - 1];
	}
	for (int i = n - 1; i >= 0; i--)
	{
		ord[aux[(v[i] >> x) & 255] - 1] = v[i];
		aux[(v[i] >> x) & 255]--;
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
	}

	for (int i = 0; i < sizeof(int); i++)
	{
		count_sort(i * 8);
	}

	for (int i = 0; i < n; i++)
	{
		std::cout << v[i] << ' ';
	}
	return 0;
}