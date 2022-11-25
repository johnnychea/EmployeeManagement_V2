
#pragma once
#include <iostream>
#include "Employee.cpp"
#include "Payment.cpp"
#include "AbstractSe.cpp"

using namespace std;

class SalariedEmployee : public Employee, Payment, AbstractSe {
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

    void getSemployee() {
        Employee::input();
        cout << "Enter salary: ";
        cin >> salary;
    }
};

