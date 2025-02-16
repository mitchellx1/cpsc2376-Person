#include <iostream>
#include <iomanip>

double convertTemperature(double temp, char scale = 'F') {
    if (scale == 'F') {
        // Convert Celsius to Fahrenheit
        return (temp * 9.0 / 5.0) + 32;
    }
    else if (scale == 'C') {
        // Convert Fahrenheit to Celsius
        return (temp - 32) * 5.0 / 9.0;
    }
    return temp; // Return the original temp if scale is invalid (fallback)
}

int main() {
    int choice;
    double temp;

    std::cout << "1. Convert Celsius to Fahrenheit\n";
    std::cout << "2. Convert Fahrenheit to Celsius\n";
    std::cout << "Choose an option: ";
    std::cin >> choice;

    std::cout << "Enter temperature: ";
    std::cin >> temp;

    if (choice == 1) {
        double result = convertTemperature(temp, 'F');
        std::cout << "Converted: " << std::fixed << std::setprecision(2) << result << "°F\n";
    }
    else if (choice == 2) {
        double result = convertTemperature(temp, 'C');
        std::cout << "Converted: " << std::fixed << std::setprecision(2) << result << "°C\n";
    }
    else {
        std::cout << "Invalid choice.\n";
    }

    return 0;
}
