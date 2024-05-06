#include <iostream>
#include <string>

using namespace std;

const int MAX_EMPLOYEES = 10;

class PerformanceEvaluator {
private:
    struct Employee {
        string name;
        int productivity;
        int attitude;
        int teamwork;
    };

    Employee employees[MAX_EMPLOYEES];
    int count = 0;

    int calculatePerformance(const Employee& employee) {
        // Define rules for performance evaluation
        int productivityScore = employee.productivity * 0.4;
        int attitudeScore = employee.attitude * 0.3;
        int teamworkScore = employee.teamwork * 0.3;
        return productivityScore + attitudeScore + teamworkScore;
    }

public:
    void addEmployee(string name, int productivity, int attitude, int teamwork) {
        if (count < MAX_EMPLOYEES) {
            employees[count] = {name, productivity, attitude, teamwork};
            count++;
        } else {
            cout << "Maximum number of employees reached." << endl;
        }
    }

    int evaluatePerformance(string employeeName) {
        for (int i = 0; i < count; ++i) {
            if (employees[i].name == employeeName) {
                return calculatePerformance(employees[i]);
            }
        }
        return -1; // Employee not found
    }
};

int main() {
    PerformanceEvaluator evaluator;

    // Add employees
    evaluator.addEmployee("John", 8, 9, 7);
    evaluator.addEmployee("Alice", 7, 8, 9);

    // Evaluate performance
    cout << "John's performance score: " << evaluator.evaluatePerformance("John") << endl;
    cout << "Alice's performance score: " << evaluator.evaluatePerformance("Alice") << endl;

    return 0;
}
