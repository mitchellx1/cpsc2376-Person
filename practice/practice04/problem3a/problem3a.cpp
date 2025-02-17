#include <iostream>
#include <list>
#include <string>

void showTasks(const std::list<std::string>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks available.\n";
        return;
    }

    std::cout << "Tasks:\n";
    int index = 1;
    for (const auto& task : tasks) {
        std::cout << index++ << ". " << task << "\n";
    }
}

int main() {
    std::list<std::string> tasks;
    int choice;

    while (true) {
        std::cout << "\n1. Add Task\n";
        std::cout << "2. Remove Task\n";
        std::cout << "3. Show Tasks\n";
        std::cout << "4. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;
        std::cin.ignore();  // Ignore leftover newline from previous input

        if (choice == 1) {
            std::string task;
            std::cout << "Enter task: ";
            std::getline(std::cin, task);
            tasks.push_back(task);
            std::cout << "Task added!\n";
        }
        else if (choice == 2) {
            showTasks(tasks);
            if (tasks.empty()) continue;

            int taskNumber;
            std::cout << "Enter task number to remove: ";
            std::cin >> taskNumber;

            if (taskNumber < 1 || taskNumber > tasks.size()) {
                std::cout << "Invalid task number!\n";
                continue;
            }

            auto it = tasks.begin();
            std::advance(it, taskNumber - 1);
            tasks.erase(it);
            std::cout << "Task removed!\n";
        }
        else if (choice == 3) {
            showTasks(tasks);
        }
        else if (choice == 4) {
            std::cout << "Exiting...\n";
            break;
        }
        else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
