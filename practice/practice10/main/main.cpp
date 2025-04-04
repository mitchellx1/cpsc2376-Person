#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <direct.h> // For _getcwd
#include <cstring>  // For FILENAME_MAX

// Define PI manually
constexpr double PI = 3.141592653589793;

// Base class
class Shape {
public:
    virtual double getArea() const = 0;
    virtual ~Shape() = default;
};

// Rectangle class
class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double getArea() const override {
        return width * height;
    }
};

// Circle class
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double getArea() const override {
        return PI * radius * radius;
    }
};

// Function to print all areas
void printAllAreas(const std::vector<std::unique_ptr<Shape>>& shapes) {
    std::cout << std::fixed << std::setprecision(4);
    for (const auto& shape : shapes) {
        std::cout << "Area: " << shape->getArea() << std::endl;
    }
}

int main() {
    // Print current working directory
    char buffer[FILENAME_MAX];
    if (_getcwd(buffer, FILENAME_MAX)) {
        std::cout << " Current working directory: " << buffer << "\n";
    }
    else {
        std::cerr << " Failed to get current working directory.\n";
    }

    // Try to open shapes.txt
    std::ifstream file("shapes.txt");
    if (!file) {
        std::cerr << " Error opening file. Make sure 'shapes.txt' is in the directory above.\n";
        return 1;
    }

    std::vector<std::unique_ptr<Shape>> shapes;
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string shapeType;
        iss >> shapeType;

        if (shapeType == "rectangle") {
            double w, h;
            iss >> w >> h;
            shapes.push_back(std::make_unique<Rectangle>(w, h));
        }
        else if (shapeType == "circle") {
            double r;
            iss >> r;
            shapes.push_back(std::make_unique<Circle>(r));
        }
    }

    printAllAreas(shapes);
    return 0;
}
