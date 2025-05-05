#include <iostream>
#include <vector>
#include <memory>

class Observer {
public:
    virtual void update(int newGrade) = 0;
    virtual ~Observer() = default;
};

class GradeBook {
    int grade;
    std::vector<std::shared_ptr<Observer>> observers;
public:
    void setGrade(int g) {
        grade = g;
        for (auto& obs : observers) {
            obs->update(grade);
        }
    }

    void addObserver(std::shared_ptr<Observer> obs) {
        observers.push_back(obs);
    }
};

class Averager : public Observer {
    std::vector<int> grades;
public:
    void update(int newGrade) override {
        grades.push_back(newGrade);
        double avg = 0;
        for (int g : grades) avg += g;
        avg /= grades.size();
        std::cout << "Average: " << avg << "\n";
    }
};

class Notifier : public Observer {
public:
    void update(int newGrade) override {
        if (newGrade < 60) {
            std::cout << "Email sent to mbperson@ualr.edu\n";
        }
    }
};

int main() {
    GradeBook gb;
    gb.addObserver(std::make_shared<Averager>());
    gb.addObserver(std::make_shared<Notifier>());

    int g;
    while (true) {
        std::cout << "Enter new grade (-1 to exit): ";
        std::cin >> g;
        if (g == -1) break;
        gb.setGrade(g);
    }

    return 0;
}
