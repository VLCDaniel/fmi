#include <iostream>

int n, v[100], tos = 0;

void insert(int x)
{
    n++;
    int aux, i = n - 1;
    v[i] = x; // il inserez pe x pe ultima pozitie
    while ((i - 1) / 2 >= 0 && v[(i - 1) / 2] > v[i]) // actualizez heap-ul verificand daca x este mai mare ca tatal lui(si ca acesta exista)
    {
        aux = v[i];
        v[i] = v[(i - 1) / 2];
        i = (i - 1) / 2;
        v[i] = aux;
    }
}

void afisare()
{
    for (int i = 0; i < n; i++)
    {
        std::cout << v[i] << ' ';
    }
    std::cout << '\n';
}

void citire()
{
    std::cout << "n= ";
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        std::cout << "v[" << i << "]= ";
        int x;
        std::cin >> x;
        v[tos] = x;
        int j = tos;
        while ((j - 1) / 2 >= 0 && v[(j - 1) / 2] > v[j]) // actualizez heap-ul verificand daca x este mai mare ca tatal lui(si ca acesta exista)
        {
            int aux;
            aux = v[j];
            v[j] = v[(j - 1) / 2];
            j = (j - 1) / 2;
            v[j] = aux;
        }
        tos++;
    }
    std::cout << '\n';
}

void swap(int& a, int& b)
{
    int aux = a;
    a = b;
    b = aux;
}

int pop_min()
{
    if (n != 0)
    {
        swap(v[0], v[n - 1]);
        n--;
        int i = 0;
        while (2 * i + 1 < n) // cat timp exista fiul stang
        {
            if (2 * i + 2 < n) // daca exista fiul drept
            {
                if (v[i] <= v[2 * i + 1] && v[i] <= v[2 * i + 2]) // daca v[i] e mai mic ca fii sai, e pe pozitia corecta.
                {
                    return v[n];
                }
                if (v[2 * i + 1] < v[2 * i + 2]) // daca fiul stang < fiul drept
                {
                    if (v[i] > v[2 * i + 1])
                    {
                        swap(v[i], v[2 * i + 1]);
                        i = 2 * i + 1;
                    }
                }
                else // daca fiul drept < fiul stang
                {
                    if (v[i] > v[2 * i + 2])
                    {
                        swap(v[2 * i + 2], v[i]);
                        i = 2 * i + 2;
                    }
                }
            }
            else // daca nu exista fiul drept
            {
                if (v[i] > v[2 * i + 1])
                {
                    swap(v[i], v[2 * i + 1]);
                    i = 2 * i + 1;
                }
                else
                {
                    return v[n];
                }
            }
        }
        return v[n];
    }
}

int main()
{
    citire(); // 12 ; 2 4 5 9 7 10 9 15 20 13 18 14
    afisare();
    std::cout << "Insert(0) ";
    insert(0);
    afisare();
    while (n != 0)
    {
        std::cout << "Pop(" << pop_min() << ")\n";
        afisare();
    }
    return 0;
}