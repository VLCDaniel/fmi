#include <iostream>
using namespace std;

struct coada
{
    int info;
    coada* prev, * next;
} *first, * last;

void push_left(int x)
{
    coada* element = new coada;
    element->info = x;
    element->prev = nullptr;
    if (first == nullptr)
    {
        element->next = nullptr;
        first = last = element;
    }
    else
    {
        first->prev = element;
        element->next = first;
        first = element;
    }
}

void push_right(int x)
{
    coada* element = new coada;
    element->info = x;
    element->next = nullptr;
    if (last == nullptr)
    {
        element->prev = nullptr;
        first = last = element;
    }
    else
    {
        last->next = element;
        element->prev = last;
        last = element;
    }
}

int pop_left()
{
    if (first != nullptr)
    {
        int x = first->info;
        coada* prim = first;
        first = first->next;
        if (first != nullptr)
        {
            first->prev = nullptr;
        }
        else
        {
            last = nullptr;
        }
        delete prim;
        return x;
    }
    return 0;
}

int pop_right()
{
    if (last != nullptr)
    {
        int x = last->info;
        coada* ultim = last;
        last = last->prev;
        if (last != nullptr)
        {
            last->next = nullptr;
        }
        else
        {
            first = nullptr;
        }
        delete ultim;
        return x;
    }
    return 0;
}

int main() // Folosind coada de la al doilea exercitiu
{
    int a[25][25], i, j, m, eticheta = 2;
    cin >> m;
    for (i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 1)
            {
                push_left(i);
                push_right(j);
                a[i][j] = eticheta;
                while (first != nullptr)
                {
                    int p = pop_left();
                    int q = pop_right();
                    a[p][q] = eticheta;
                    if (q > 0 && a[p][q - 1] == 1) // Stanga
                    {
                        push_left(p);
                        push_right(q - 1);
                    }
                    if (q < m - 1 && a[p][q + 1] == 1) // Dreapta
                    {
                        push_left(p);
                        push_right(q + 1);
                    }
                    if (p > 0 && a[p - 1][q] == 1) // Sus
                    {
                        push_left(p - 1);
                        push_right(q);
                    }
                    if (p < m - 1 && a[p + 1][q] == 1) // Jos
                    {
                        push_left(p + 1);
                        push_right(q);
                    }
                }
                eticheta++;
            }
        }
    }

    cout << '\n';
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}