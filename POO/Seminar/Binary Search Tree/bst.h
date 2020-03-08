#ifndef BST_H
#define BST_H
#include "node.h"

class BST 
{
	Node* root;
	unsigned size;

public:
	BST();
	BST(int);
	void insertUnique(int);
	bool search(int);
	void print();
};

#endif