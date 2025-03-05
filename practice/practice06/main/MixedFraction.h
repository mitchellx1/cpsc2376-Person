#ifndef MIXEDFRACTION_H
#define MIXEDFRACTION_H

#include "Fraction.h"

class MixedFraction : public Fraction {
private:
    int whole;

public:
    // Constructors
    MixedFraction(int whole, int n, int d);
    MixedFraction(const Fraction& fraction);

    // Stream Overload
    friend std::ostream& operator<<(std::ostream& os, const MixedFraction& mixed);
};

#endif
