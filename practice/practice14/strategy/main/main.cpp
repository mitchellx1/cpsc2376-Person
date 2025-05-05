#include <iostream>
#include <memory>
#include <string>
#include <algorithm>
#include <cctype>

class TextFilter {
public:
    virtual std::string apply(const std::string& text) = 0;
    virtual ~TextFilter() = default;
};

class ReverseFilter : public TextFilter {
public:
    std::string apply(const std::string& text) override {
        return std::string(text.rbegin(), text.rend());
    }
};

class UppercaseFilter : public TextFilter {
public:
    std::string apply(const std::string& text) override {
        std::string result = text;
        std::transform(result.begin(), result.end(), result.begin(), ::toupper);
        return result;
    }
};

class RemoveVowelsFilter : public TextFilter {
public:
    std::string apply(const std::string& text) override {
        std::string result;
        for (char c : text) {
            if (!strchr("aeiouAEIOU", c)) result += c;
        }
        return result;
    }
};

void menu() {
    std::cout << "\nChoose a filter:\n";
    std::cout << "1. Reverse\n2. Uppercase\n3. Remove Vowels\n4. Exit\n> ";
}

int main() {
    std::string input;
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, input);

    std::unique_ptr<TextFilter> filter;
    int choice = 0;

    do {
        menu();
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        case 1: filter = std::make_unique<ReverseFilter>(); break;
        case 2: filter = std::make_unique<UppercaseFilter>(); break;
        case 3: filter = std::make_unique<RemoveVowelsFilter>(); break;
        case 4: std::cout << "Goodbye!\n"; return 0;
        default: std::cout << "Invalid option\n"; continue;
        }

        std::string result = filter->apply(input);
        std::cout << "Filtered text: " << result << "\n";

    } while (true);

    return 0;
}
