#include "Fraction.h"

#include <iostream>

int cmmdc (int a, int b) {
    while (a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    return a;
}

int cmmmmc (int a, int b) {
    int p = a * b;
    return p / cmmdc(a,b);
}

void Fraction::simplify() {
    const int c = cmmdc(n, m);
    if (c != 1) {
        n /= c;
        m /= c;
    }
}

Fraction::Fraction(int x, int y) : n(x) {
    if (y == 0) {
        throw std::range_error("Numitor 0");
    }
    m = y;
}

Fraction Fraction::operator+(Fraction f) const {
    Fraction g;
    const int c = cmmmmc(m, f.m);
    g.m = c;
    g.n = n * (c / m) + f.n * (c / f.m);
    g.simplify();
    return g;
}

Fraction Fraction::operator-(Fraction f) const {
    Fraction g;
    const int c = cmmmmc(m, f.m);
    g.m = c;
    g.n = n * (c / m) - f.n * (c / f.m);
    g.simplify();
    return g;
}

Fraction Fraction::operator*(Fraction f) const {
    Fraction g;
    g.n = n * f.n;
    g.m = m * f.m;
    g.simplify();
    return g;
}

Fraction Fraction::operator/(Fraction f) const {
    Fraction g;
    g.n = n * f.m;
    g.m = m * f.n;
    g.simplify();
    return g;
}

std::ostream& operator<< (std::ostream& out, Fraction f) {
    out << f.n << "/" << f.m;
    return out;
}

std::istream& operator>> (std::istream& in, Fraction& f) {
    in >> f.n >> f.m;
    return in;
}

Fraction operator* (int x, Fraction f) {
    Fraction g;
    g.n = x * f.n;
    g.m = x * f.m == 0 ? f.m : x * f.m;
    return g;
}