#include "pch.h" // This includes the necessary files for MS unit testing framework
#include "../practice03/practice03.cpp"  // Include the buggy code file
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Practice03Tests
{
    TEST_CLASS(MathUtilsTests)
    {
    public:

        // Test sumRange
        TEST_METHOD(TestSumRange)
        {
            Assert::AreEqual(MathUtils::sumRange(1, 5), 10); // 1 + 2 + 3 + 4 = 10
            Assert::AreEqual(MathUtils::sumRange(0, 0), 0); // Edge case, no numbers to sum
            Assert::AreEqual(MathUtils::sumRange(-5, 0), -15); // -5 + -4 + -3 + -2 + -1 = -15
        }

        // Test containsNegative
        TEST_METHOD(TestContainsNegative)
        {
            std::vector<int> values = { 3, -1, 5, 7 };
            Assert::IsTrue(MathUtils::containsNegative(values)); // Contains negative (-1)

            values = { 3, 5, 7 };
            Assert::IsFalse(MathUtils::containsNegative(values)); // No negatives

            values = {};
            Assert::IsFalse(MathUtils::containsNegative(values)); // Empty vector
        }

        // Test findMax
        TEST_METHOD(TestFindMax)
        {
            std::vector<int> values = { 3, -1, 5, 7 };
            Assert::AreEqual(MathUtils::findMax(values), 7); // 7 is the max value

            values = { 3, 3, 3 };
            Assert::AreEqual(MathUtils::findMax(values), 3); // All values are equal

            values = {};
            Assert::AreEqual(MathUtils::findMax(values), 0); // Edge case, empty vector
        }
    };
}
