#include "bst.h"
#include <iostream>
using namespace std;

BST::BST() : size(0), root(NULL) {}

BST::BST(int x) : BST() 
{
	root = new Node(x);
	size++;
}

void BST::insertUnique(int x) 
{
	if (size == 0)
		root = new Node(x);	// nu se poate apela constructorul fiindca obiectul este deja creat
	else 
	{
		Node* p = root;
		bool stop = false;

		while (!stop)
		{
			if (p->info > x)
				if (p->left != NULL)
					p = p->left;
				else 
				{
					p->left = new Node(x);
					stop = true;
				}
			else if (p->info < x) 
			{
				if (p->right != NULL)
					p = p->right;
				else 
				{
					p->right = new Node(x);
					stop = true;
				}
			}
			else
				return;
		}
	}
	size++;
}

bool BST::search(int x)
{
	if (size == 0)
		return false;

	Node* p = root;

	while (p != NULL) 
	{
		if (p->info > x)
			p = p->left;
		else if (p->info < x)
			p = p->right;
		else
			return true;
	}
	return false;
}

void BST::print() 
{
	Node* p = this->root;
	Node**v = new Node*[this->size];
	int i = 0;	
	// Conditia de oprire este ca p sa fie NULL si vectorul de pointeri sa fie gol (i=0)
	while (p != NULL || i != 0)
	{
		// Plecand din radacina, ma duc catre cel mai din dreapta nod
		while (p != NULL)
		{
			v[i] = p;
			i++;
			p = p->right;
		}
		i--;
		p = v[i];
		cout << p->info << " ";
		// Ma mut catre nodul din stanga
		p = p->left;
	}
}