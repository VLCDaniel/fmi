#include <iostream>
#include "Fraction.h"
#include "Vector.h"

using namespace std;


int main () {
    Fraction f(3, 5), g(3, 10);
    cout << f + g << endl;
    Vector v;
    for (int i = 0; i < 10l; i++) {
        v.push( i * f);
    }
    cout << v << endl;
    Vector w(v);
    cout << w << endl;
    return 0;
}