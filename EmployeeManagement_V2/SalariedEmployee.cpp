
#pragma once
#include <iostream>
#include "Employee.cpp"
#include "Payment.cpp"
using namespace std;

class SalariedEmployee : public Employee, Payment {
private:
    double salary;
public:
    SalariedEmployee() :Employee(), salary(0) {}
    SalariedEmployee(int id, string name, char sex, string phone, double salary) :Employee(id, name, sex, phone), salary(salary) {}
    ~SalariedEmployee() {

    }

    double getSalary() {
        return salary;
    }

    double getPayment() {
        return salary;
    }

    void getEmployee() {
        Employee::input();
        cout << "Enter salary: ";
        cin >> salary;
    }
};

