#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <stdexcept>

class Fraction {
private:
    int num; // Numerator
    int den; // Denominator

    void simplify(); // Helper function to simplify the fraction

public:
    // Constructors
    Fraction();
    Fraction(int n, int d);

    // Getters
    int getNumerator() const;
    int getDenominator() const;

    // Setters
    void setNumerator(int n);
    void setDenominator(int d);

    // Operator Overloads
    friend Fraction operator+(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator-(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator*(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator/(const Fraction& lhs, const Fraction& rhs);

    // Stream Overload
    friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction);
};

#endif
