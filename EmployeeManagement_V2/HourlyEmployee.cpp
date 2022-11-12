#pragma once
#include <iostream>
#include "Employee.cpp"
#include "Payment.cpp"
using namespace std;

class HourlyEmployee : public Employee, Payment {
private:
    double rate;
    double hour;
public:
    HourlyEmployee() :Employee(), rate(0), hour(0) {}
    HourlyEmployee(int id, string name, char sex, string phone, double rate, double hour) :Employee(id, name, sex, phone), rate(rate), hour(hour) {}

    double getPayment() {
        return rate * hour;
    }

    void getHemployee() {
        Employee::input();
        cout << "Enter rate: ";
        cin >> rate;
        cout << "Enter hour: ";
        cin >> hour;
    }
};
