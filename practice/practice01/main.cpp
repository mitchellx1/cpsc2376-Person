
#include <iostream>
#include <vector>
#include <numeric> // For std::accumulate

// Function declarations
void printVector(const std::vector<int>& vec);
void doubleVector(std::vector<int>& vec);
int calculateSum(const std::vector<int>& vec);
void printMultiples(const std::vector<int>& vec, int value);

int main() {
    std::vector<int> numbers;
    int choice = 0;

    while (choice != 6) {
        // Display menu
        std::cout << "\nMenu Options:\n";
        std::cout << "1. Add an item to the vector\n";
        std::cout << "2. Print the vector\n";
        std::cout << "3. Double the vector\n";
        std::cout << "4. Find the sum of the vector\n";
        std::cout << "5. Print multiples of a user-defined value\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            int num;
            std::cout << "Enter a number to add to the vector: ";
            std::cin >> num;
            numbers.push_back(num);
            std::cout << num << " has been added to the vector.\n";
        }
        else if (choice == 2) {
            printVector(numbers);
        }
        else if (choice == 3) {
            doubleVector(numbers);
            std::cout << "The vector has been doubled.\n";
        }
        else if (choice == 4) {
            int sum = calculateSum(numbers);
            std::cout << "The sum of all numbers in the vector is: " << sum << "\n";
        }
        else if (choice == 5) {
            int value;
            std::cout << "Enter a value to find multiples of: ";
            std::cin >> value;
            printMultiples(numbers, value);
        }
        else if (choice == 6) {
            std::cout << "Exiting program. Goodbye!\n";
        }
        else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

// Function to print the vector
void printVector(const std::vector<int>& vec) {
    if (vec.empty()) {
        std::cout << "The vector is empty.\n";
    }
    else {
        std::cout << "Vector elements: ";
        for (size_t i = 0; i < vec.size(); i++) {
            std::cout << vec.at(i) << " ";
        }
        std::cout << "\n";
    }
}

// Function to double each element in the vector
void doubleVector(std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); i++) {
        vec.at(i) *= 2;
    }
}

// Function to calculate the sum of the vector
int calculateSum(const std::vector<int>& vec) {
    return std::accumulate(vec.begin(), vec.end(), 0);
}

// Function to print multiples of a user-defined value
void printMultiples(const std::vector<int>& vec, int value) {
    if (vec.empty()) {
        std::cout << "The vector is empty. No multiples to print.\n";
        return;
    }

    std::cout << "Multiples of " << value << ": ";
    bool found = false;
    for (size_t i = 0; i < vec.size(); i++) {
        if (vec.at(i) % value == 0) {
            std::cout << vec.at(i) << " ";
            found = true;
        }
    }

    if (!found) {
        std::cout << "No multiples found.";
    }
    std::cout << "\n";
}
