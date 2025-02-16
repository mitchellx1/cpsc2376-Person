#include <iostream>
#include <iomanip>

template <typename T>
T calculate(T num1, T num2, char op) {
    switch (op) {
    case '+': return num1 + num2;
    case '-': return num1 - num2;
    case '*': return num1 * num2;
    case '/': return (num2 != 0) ? num1 / num2 : 0;  // Avoid division by zero
    default: std::cout << "Invalid operation.\n"; return 0;
    }
}

int main() {
    double num1, num2;
    char op;

    std::cout << "Enter first number: ";
    std::cin >> num1;  // Automatically handles both int and double input
    std::cout << "Enter second number: ";
    std::cin >> num2;
    std::cout << "Enter operation (+, -, *, /): ";
    std::cin >> op;

    double result = calculate(num1, num2, op);

    // Print result with appropriate formatting
    if (num1 == static_cast<int>(num1) && num2 == static_cast<int>(num2) && result == static_cast<int>(result)) {
        std::cout << "Result: " << static_cast<int>(result) << "\n";
    }
    else {
        std::cout << "Result: " << std::fixed << std::setprecision(2) << result << "\n";
    }

    return 0;
}
