#include <iostream>

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

void display()
{
    coada* aux = first;
    if (aux == nullptr)
    {
        std::cout << "Queue is empty!";
    }
    else
    {
        while (aux != nullptr)
        {
            std::cout << aux->info << " ";
            aux = aux->next;
        }
    }
}

int main()
{
    push_left(1);
    push_right(2);
    pop_right();
    pop_left();
    push_right(3);
    display();
}
