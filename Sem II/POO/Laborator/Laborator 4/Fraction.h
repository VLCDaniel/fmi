#ifndef _FRACTION_H
#define _FRACTION_H

#include <istream>
#include <ostream>
#include <stdexcept>

class Vector;

class Fraction {
    int n, m;
    void simplify ();
public:
    Fraction(int = 0, int = 1);
    Fraction operator+(Fraction)const;
    Fraction operator-(Fraction)const;
    Fraction operator/(Fraction)const;
    Fraction operator*(Fraction)const;
    friend Fraction operator*(int, Fraction);
    friend std::istream& operator>>(std::istream& in, Fraction&);
    friend std::ostream& operator<<(std::ostream& in, Fraction);
    friend class Vector;
};

int cmmmmc(int, int);

#endif // _FRACTION_H