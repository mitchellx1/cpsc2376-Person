#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

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

    // Print squared elements using std::for_each and lambda
    std::cout << "Squared values: ";
    std::for_each(numbers.begin(), numbers.end(), [](int num) {
        std::cout << num * num << " ";
        });
    std::cout << std::endl;

    // Calculate the sum of squared values using std::accumulate and lambda
    int squaredSum = std::accumulate(numbers.begin(), numbers.end(), 0, [](int acc, int num) {
        return acc + (num * num);
        });

    std::cout << "Sum of squared values: " << squaredSum << std::endl;

    return 0;
}
