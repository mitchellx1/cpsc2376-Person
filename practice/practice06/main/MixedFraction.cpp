#include "MixedFraction.h"

// Constructor for mixed fraction
MixedFraction::MixedFraction(int whole, int n, int d) : Fraction(n, d), whole(whole) {}

// Convert Fraction to MixedFraction
MixedFraction::MixedFraction(const Fraction& fraction) : Fraction(fraction) {
    whole = fraction.getNumerator() / fraction.getDenominator();
}

// Overloaded << for output
std::ostream& operator<<(std::ostream& os, const MixedFraction& mixed) {
    if (mixed.whole != 0)
        os << mixed.whole << " " << mixed.getNumerator() % mixed.getDenominator() << "/" << mixed.getDenominator();
    else
        os << mixed.getNumerator() << "/" << mixed.getDenominator();
    return os;
}
