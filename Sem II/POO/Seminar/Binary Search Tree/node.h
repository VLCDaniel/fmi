#ifndef NODE_H
#define NODE_H

class BST;

class Node 
{
	int info;
	Node* left, * right;
public:
	Node(int);
	friend BST;
};

#endif