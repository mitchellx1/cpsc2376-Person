#include <iostream>
#include <string>

int main() {
    float redPotion{ 0.0f };    // Amount of red potion in mL
    float bluePotion{ 0.0f };   // Amount of blue potion in mL
    float* flask{ nullptr };    // Pointer to the selected potion
    std::string potionChoice;

    while (true) {
        std::cout << "Which potion to add liquid to? (Red/Blue or Done to exit): ";
        std::cin >> potionChoice;

        if (potionChoice == "Done" || potionChoice == "done") {
            break;
        }

        if (potionChoice == "Red" || potionChoice == "red") {
            flask = &redPotion;
        }
        else if (potionChoice == "Blue" || potionChoice == "blue") {
            flask = &bluePotion;
        }
        else {
            std::cout << "Invalid choice. Please enter 'Red', 'Blue', or 'Done'.\n";
            continue;
        }

        float amount;
        std::cout << "Enter amount to add (mL): ";
        std::cin >> amount;

        if (amount < 0) {
            std::cout << "Amount cannot be negative!\n";
            continue;
        }

        *flask += amount;  // Update the potion amount using pointer

        std::cout << "Red Potion: " << redPotion << " mL, Blue Potion: " << bluePotion << " mL\n";
    }

    std::cout << "Potion brewing complete. Final amounts - Red: " << redPotion << " mL, Blue: " << bluePotion << " mL\n";
    return 0;
}
