#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

const std::string FILE_NAME = "account_balance.txt";
const std::string BANK_NAME = "Brooks Financial";

// Function to check if account file exists
bool fileExists(const std::string& filename) {
    std::ifstream file(filename);
    return file.good();
}

// Function to create a new account
void createAccount(std::string& accountName) {
    std::cout << "\nWelcome to " << BANK_NAME << "!\n";
    std::cout << "Enter your account name: ";
    std::getline(std::cin, accountName);

    std::ofstream file(FILE_NAME);
    if (!file) {
        std::cerr << "Error: Unable to create account file.\n";
        exit(1);
    }
    file << "100.00";  // Default starting balance
    file.close();
    std::cout << "Account '" << accountName << "' created successfully with a balance of $100.00\n";
}

// Function to read balance from file
double readBalance() {
    std::ifstream file(FILE_NAME);
    double balance = 100.00;

    if (file.is_open()) {
        file >> balance;
        file.close();
    }
    return balance;
}

// Function to write balance to file
void writeBalance(double balance) {
    std::ofstream file(FILE_NAME);
    if (!file) {
        std::cerr << "Error: Unable to update account file.\n";
        return;
    }
    file << std::fixed << std::setprecision(2) << balance;
    file.close();
}

// Function to handle transactions
void transactionMenu(std::string& accountName) {
    double balance = readBalance();
    int choice = 0;

    while (true) {
        std::cout << "\nWelcome, " << accountName << " to " << BANK_NAME << "!\n";
        std::cout << "----------------------------------\n";
        std::cout << "1. Check Balance\n";
        std::cout << "2. Deposit Money\n";
        std::cout << "3. Withdraw Money\n";
        std::cout << "4. Exit\n";
        std::cout << "----------------------------------\n";
        std::cout << "Enter your choice: ";

        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cerr << "Invalid input. Please enter a number between 1 and 4.\n";
            continue;
        }

        if (choice == 1) {
            std::cout << "\nYour current balance is: $" << std::fixed << std::setprecision(2) << balance << "\n";
        }
        else if (choice == 2) {
            double amount;
            std::cout << "Enter deposit amount: $";
            std::cin >> amount;

            if (amount > 0) {
                balance += amount;
                writeBalance(balance);
                std::cout << "Deposit successful. New balance: $" << balance << "\n";
            }
            else {
                std::cerr << "Error: Deposit amount must be positive.\n";
            }
        }
        else if (choice == 3) {
            double amount;
            std::cout << "Enter withdrawal amount: $";
            std::cin >> amount;

            if (amount > 0 && amount <= balance) {
                balance -= amount;
                writeBalance(balance);
                std::cout << "Withdrawal successful. New balance: $" << balance << "\n";
            }
            else if (amount > balance) {
                std::cerr << "Error: Insufficient funds. Balance: $" << balance << "\n";
            }
            else {
                std::cerr << "Error: Withdrawal amount must be positive.\n";
            }
        }
        else if (choice == 4) {
            std::cout << "Thank you for using " << BANK_NAME << "! Goodbye.\n";
            break;
        }
        else {
            std::cerr << "Invalid choice. Please select a valid option.\n";
        }
    }
}

// Main function
int main() {
    std::string accountName;

    std::cout << "Welcome to " << BANK_NAME << "!\n";
    std::cout << "Do you have an account? (yes/no): ";

    std::string response;
    std::cin >> response;
    std::cin.ignore();  // Clear newline from input buffer

    if (response == "no") {
        createAccount(accountName);
    }
    else {
        std::cout << "Enter your account name: ";
        std::getline(std::cin, accountName);
    }

    transactionMenu(accountName);
    return 0;
}
