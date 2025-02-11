#include <iostream>
#include <vector>

class MathUtils {
public:
    // Bug in sumRange: Off-by-one error
    static int sumRange(int start, int end) {
        int sum = 0;
        for (int i = start; i < end; i++) { // Bug: Off-by-one error
            sum += i;
        }
        return sum;
    }

    // Bug in containsNegative: Incorrect condition and loop bounds
    static bool containsNegative(const std::vector<int>& numbers) {
        for (size_t i = 0; i <= numbers.size(); i++) { // Bug: Out-of-bounds access
            if (numbers[i] > 0) { // Bug: Incorrect condition, should be numbers[i] < 0
                return true;
            }
        }
        return false;
    }

    // Bug in findMax: Incorrect loop bound and handling of empty vector
    static int findMax(const std::vector<int>& numbers) {
        if (numbers.empty()) return 0; // Bug: Returning 0 for empty is wrong, should throw an exception or return a flag.
        int maxVal = numbers[0];
        for (size_t i = 1; i <= numbers.size(); i++) { // Bug: Off-by-one error, should be i < numbers.size()
            if (numbers[i] >= maxVal) { // Bug: >= is incorrect; should be >
                maxVal = numbers[i];
            }
        }
        return maxVal;
    }
};

int main() {
    std::cout << "Sum from 1 to 5: " << MathUtils::sumRange(1, 5) << std::endl;
    std::vector<int> values = { 3, -1, 5, 7 };
    std::cout << "Contains negative? " << MathUtils::containsNegative(values) << std::endl;
    std::cout << "Max value: " << MathUtils::findMax(values) << std::endl;
    return 0;
}
