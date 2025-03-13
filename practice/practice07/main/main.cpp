#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <memory>

using namespace std;

// Base Class: Employee
class Employee {
protected:
    string name;
    int id;

public:
    Employee(string name, int id) : name(name), id(id) {}
    virtual ~Employee() {}

    virtual double calculateSalary() const = 0;
    virtual void displayInfo() const {
        cout << "ID: " << id << ", Name: " << name;
    }
};

// Derived Class: SalariedEmployee
class SalariedEmployee : public Employee {
private:
    double monthlySalary;

public:
    SalariedEmployee(string name, int id, double monthlySalary)
        : Employee(name, id), monthlySalary(monthlySalary) {
    }

    double calculateSalary() const override {
        return monthlySalary;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        cout << ", Type: Salaried, Monthly Salary: $" << monthlySalary << endl;
    }
};

// Derived Class: HourlyEmployee
class HourlyEmployee : public Employee {
private:
    double hourlyRate;
    int hoursWorked;

public:
    HourlyEmployee(string name, int id, double hourlyRate, int hoursWorked)
        : Employee(name, id), hourlyRate(hourlyRate), hoursWorked(hoursWorked) {
    }

    double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }

    void displayInfo() const override {
        Employee::displayInfo();
        cout << ", Type: Hourly, Hours Worked: " << hoursWorked
            << ", Hourly Rate: $" << hourlyRate
            << ", Salary: $" << calculateSalary() << endl;
    }
};

// Derived Class: CommissionEmployee
class CommissionEmployee : public Employee {
private:
    double baseSalary;
    double salesAmount;
    double commissionRate;

public:
    CommissionEmployee(string name, int id, double baseSalary, double salesAmount, double commissionRate)
        : Employee(name, id), baseSalary(baseSalary), salesAmount(salesAmount), commissionRate(commissionRate) {
    }

    double calculateSalary() const override {
        return baseSalary + (salesAmount * commissionRate);
    }

    void displayInfo() const override {
        Employee::displayInfo();
        cout << ", Type: Commission, Base Salary: $" << baseSalary
            << ", Sales: $" << salesAmount
            << ", Commission Rate: " << (commissionRate * 100) << "%"
            << ", Salary: $" << calculateSalary() << endl;
    }
};

// Function to read employee records from a file
void loadEmployees(const string& filename, vector<unique_ptr<Employee>>& employees) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        istringstream ss(line);
        string type, name;
        int id;
        double salary, rate, sales;
        int hours;

        ss >> type >> id >> name;

        if (type == "Salaried") {
            ss >> salary;
            employees.push_back(make_unique<SalariedEmployee>(name, id, salary));
        }
        else if (type == "Hourly") {
            ss >> rate >> hours;
            employees.push_back(make_unique<HourlyEmployee>(name, id, rate, hours));
        }
        else if (type == "Commission") {
            ss >> salary >> sales >> rate;
            employees.push_back(make_unique<CommissionEmployee>(name, id, salary, sales, rate));
        }
        else {
            cerr << "Invalid employee type found: " << type << endl;
        }
    }
}

// Function to display all employees
void displayEmployees(const vector<unique_ptr<Employee>>& employees) {
    if (employees.empty()) {
        cout << "No employees found." << endl;
        return;
    }

    cout << "\nEmployee Payroll:\n----------------\n";
    for (const auto& emp : employees) {
        emp->displayInfo();
    }
}

// Main Function
int main() {
    vector<unique_ptr<Employee>> employees;
    string filename = "employees.txt";

    loadEmployees(filename, employees);
    displayEmployees(employees);

    return 0;
}
