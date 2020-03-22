#include "Vector.h"

Vector::Vector(unsigned dim) : capacity(dim), size(0) {
    array = new Fraction[capacity];
}

Vector::Vector(const Vector& v) : size(v.size), capacity(v.capacity) {
    array = new Fraction[capacity];
    std::copy(v.array, v.array+size, array);
}


Vector::~Vector() {
    delete[] array;
    size = capacity = 0;
}


Vector Vector::operator=(const Vector& v) {
    delete[] array;
    size = v.size;
    capacity = v.capacity;
    array = new Fraction[capacity];
    std::copy(v.array, v.array + size, array);
    return v;
}

void Vector::push(Fraction f) {
    if (size == capacity) {
        capacity += 10;
        Fraction *aux = new Fraction[capacity];
        std::copy(array, array + size, aux);
        delete[] array;
        array = aux;
    }
    array[size++] = f;
}

Fraction Vector::pop() {
    if (size == 0) {
        throw std::out_of_range("Vector gol");
    }
    return array[--size];
}

Vector Vector::operator+(const Vector& v) const {
    if (size != v.size) {
        throw std::domain_error("Dimensiuni diferite ale vectorilor");
    }
    Vector w(size);
    for (unsigned i = 0; i < size; i++) {
        w.array[i] = v.array[i] + array[i];
    }
    w.size = size;
    return w;
}

Vector Vector::operator-(const Vector& v) const {
     if (size != v.size) {
        throw std::domain_error("Dimensiuni diferite ale vectorilor");
    }
    Vector w(size);
    for (unsigned i = 0; i < size; i++) {
        w.array[i] = v.array[i] - array[i];
    }
    w.size = size;
    return w;
}

Vector operator*(Fraction f, const Vector& v) {
    Vector w(v.size);
    w.size = v.size;
    for (unsigned i = 0; i < v.size; i++) {
        w.array[i] = f * v.array[i];
    }
    return w;
}

std::istream& operator>>(std::istream& in, Vector& v) {
    delete[] v.array;
    unsigned dim;
    in >> dim;
    v.size = dim;
    v.capacity = dim;;
    v.array = new Fraction[v.capacity];
    for (unsigned i = 0; i < v.size; i++) {
        Fraction f;
        in >> f;
        v.array[i] = f;
    }
    return in;
}

Fraction Vector::operator[](unsigned index) const {
    if (index > size) {
        throw std::out_of_range("Index mai mare ca dimensiunea vectorului");
    }
    return array[index];
}

std::ostream& operator<<(std::ostream& out, const Vector& v) {
    for(unsigned i = 0; i < v.size; i++) {
        out << v[i] << " ";
    }
    return out;
}