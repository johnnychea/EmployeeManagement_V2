#pragma once

#include<iostream>
using namespace std;

class Payment {
public:
    virtual double getPayment() = 0;
};