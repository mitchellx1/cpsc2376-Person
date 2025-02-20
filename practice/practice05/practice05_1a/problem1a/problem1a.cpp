#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers;
    int n, input;

    std::cout << "Enter the number of integers: ";
    std::cin >> n;

    std::cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> input;
        numbers.push_back(input);
    }

    // Print elements using iterator
    std::cout << "You entered: ";
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Sum even numbers using iterator
    int evenSum = 0;
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        if (*it % 2 == 0) {
            evenSum += *it;
        }
    }
    std::cout << "Sum of even numbers: " << evenSum << std::endl;

    return 0;
}
