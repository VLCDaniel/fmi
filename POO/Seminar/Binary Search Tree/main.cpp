#include "bst.h"
#include "node.h"
#include <iostream>


using namespace std;

int main()
{
    BST A(50);
    A.insertUnique(30);
    A.insertUnique(29);
    A.insertUnique(28);
    A.insertUnique(31);
    A.insertUnique(27);
    A.insertUnique(32);
    A.insertUnique(24);
    A.insertUnique(33);
    A.insertUnique(23);
    A.insertUnique(60);
    A.insertUnique(70);

    A.print();

    return 0;
}