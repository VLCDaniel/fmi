#ifndef _VECTOR_H
#define _VECTOR_H

#include "Fraction.h"
#include <algorithm>

class Vector {
    Fraction *array;
    unsigned size, capacity;
public:
    Vector(unsigned = 1);
    Vector(const Vector&);
    ~Vector();
    void push (Fraction);
    Fraction pop();
    Vector operator=(const Vector&);
    Vector operator+(const Vector&) const;
    Vector operator-(const Vector&) const;
    Fraction operator[] (unsigned) const;
    friend Vector operator*(Fraction, const Vector&);
    friend std::istream& operator>>(std::istream&, Vector&);
    friend std::ostream& operator<<(std::ostream&, const Vector&);
};

#endif //_VECTOR_H