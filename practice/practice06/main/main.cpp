#include "Fraction.h"
#include "MixedFraction.h"
#include <iostream>

using namespace std;

int main() {
    Fraction current(1, 3);
    int choice;

    while (true) {
        cout << "\nCurrent Fraction: " << current << "\n";
        cout << "Options:\n";
        cout << "1. Enter a fraction manually\n";
        cout << "2. Add a fraction\n";
        cout << "3. Subtract a fraction\n";
        cout << "4. Multiply by a fraction\n";
        cout << "5. Divide by a fraction\n";
        cout << "6. Display as Mixed Fraction\n";
        cout << "7. Clear Fraction\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 8) break;

        int num, den;
        Fraction input;

        switch (choice) {
        case 1:
            cout << "Enter numerator and denominator: ";
            cin >> num >> den;
            try {
                current = Fraction(num, den);
            }
            catch (const exception& e) {
                cout << "Error: " << e.what() << "\n";
            }
            break;

        case 2:
            cout << "Enter fraction to add (num/den): ";
            cin >> num >> den;
            try {
                input = Fraction(num, den);
                current = current + input;
            }
            catch (const exception& e) {
                cout << "Error: " << e.what() << "\n";
            }
            break;

        case 3:
            cout << "Enter fraction to subtract (num/den): ";
            cin >> num >> den;
            current = current - Fraction(num, den);
            break;

        case 4:
            cout << "Enter fraction to multiply (num/den): ";
            cin >> num >> den;
            current = current * Fraction(num, den);
            break;

        case 5:
            cout << "Enter fraction to divide by (num/den): ";
            cin >> num >> den;
            try {
                current = current / Fraction(num, den);
            }
            catch (const exception& e) {
                cout << "Error: " << e.what() << "\n";
            }
            break;

        case 6:
            cout << "Mixed Fraction: " << MixedFraction(current) << "\n";
            break;

        case 7:
            current = Fraction(0, 1);
            break;

        default:
            cout << "Invalid choice!\n";
        }
    }
    return 0;
}
