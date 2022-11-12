#pragma once

#include <iostream>
#include<fstream>
#include "Employee.cpp"
#include "DynamicArray.cpp"
#include <vector>

using namespace std;
enum EDIT
{
    NAME = 1,
    SEX,
    PHONE
};
class EmployeeService {
private:
    vector<Employee*> employees;

public:
    EmployeeService() {}

    ~EmployeeService() {
        vector<Employee*>::iterator it;
        for (it = employees.begin(); it != employees.end(); it++) {
            delete* it;
        }
    }

    void addEmployee(Employee* employee) {
        employees.push_back(employee);
    }

    void viewEmployee() {
        cout << "=====Employee Data=====" << endl;
        viewInfo();
        for (auto it = employees.begin(); it != employees.end(); it++) {
            (*it)->output();
            cout << endl;
        }
    }
  

    void searchEmployee(int id) {
        vector<Employee*>::iterator it;
        if (getEmployeeById(id) != nullptr) {
            cout << "=====Employee Data=====" << endl;
            viewInfo();
            for (auto it = employees.begin(); it != employees.end(); it++) {
                if ((*it)->getId() == id) {
                    (*it)->output();
                    cout << endl;
                    break;
                }         
            }
        }
        else {
            cout << "NO DATA!!" << endl;
        }
        
    }
    Employee* getEmployeeById(int id) {
        vector<Employee*>::iterator it;
        for (auto it = employees.begin(); it != employees.end(); it++) {
            if ((*it)->getId() == id) {
                return *it;
            }
        }
        return nullptr;
    }
   


    void editEmployee(int id) {
        vector<Employee*>::iterator it;
        int ch;
        string name,phone;
        char sex;
        if (getEmployeeById(id)!=nullptr)
        {
            for (it = employees.begin(); it != employees.end(); it++) {
                if ((*it)->getId() == id) {
                    viewInfo();
                    (*it)->output();
                    cout << endl;
                    do
                    {
                        editMenu();
                        ch = getChoice();
                        switch (ch)
                        {
                        case NAME:
                            cout << "Enter new name: ";
                            cin >> name;
                            (*it)->setName(name);
                            cout << "Name has been edited*" << endl;
                            break;
                        case SEX:
                            cout << "Enter new Gender: ";
                            cin >> sex;
                            (*it)->setSex(sex);
                            cout << "Gender has been edited*" << endl;
                            break;
                        case PHONE:
                            cout << "Enter new Phone Number: ";
                            cin >> phone;
                            (*it)->setPhone(phone);
                            cout << "Name has been edited*" << endl;
                            break;
                        }

                    } while (ch != 0);

                }
            }
        }
        else {
            cout << "NO DATA!!" << endl;
        }
    }
    
    void deleteEmployee(int id) {
        vector<Employee*>::iterator it;
        if (getEmployeeById(id)!=nullptr)
        {
            for (it = employees.begin(); it != employees.end(); it++) {
                if ((*it)->getId() == id) {
                    employees.erase(it);
                    break;
                }
            }
        
        }
        else {
            cout << "NO DATA!!" << endl;
        }
    }


    /*Employee* getEmployeeByName(string name) {
        vector<Employee*>::iterator it;
        for (it = employees.begin(); it != employees.end(); it++) {
            if ((*it)->getName().compare(name) == 0) {
                return *it;
            }
        }
        return nullptr;
    }*/

    vector<Employee*>getAllEmployees() {
        return employees;
    }


    void saveEmployeeToFile() {
        ofstream outputFile;
        outputFile.open("Employees.bin", ios::out | ios::binary | ios::trunc);
        if (!outputFile) {
            cout << "Error in creating file...\n";
            exit(1);
        }
        else {
            vector<Employee*>::iterator it;
            for (auto it = employees.begin(); it != employees.end(); it++) {
                outputFile.write((char*)&it, sizeof(it));
            }
        }

        outputFile.close();
    }
    void loadEmployeeFromFile() {
        Employee employee;
        ifstream inputFile;
        inputFile.open("Employees.bin", ios::in | ios::binary);
        if (!inputFile) {
            cout << "Error in opening file...\n";
            exit(1);
        }
        else {
            while (inputFile.read((char*)(&employee), sizeof(employee))) {
                employees.push_back(&employee);
            }
        }
        inputFile.close();
    }

    void editMenu() {
        cout << "===Edit MENU===\n";
        cout << "1.Name\n";
        cout << "2.Gender\n";
        cout << "3.Phone Number\n";
        cout << "0.MAIN MENU\n";
        cout << "Choose (1-3): ";
    }

    void viewInfo() {
        cout << "ID\tNAME\tPHONE\tSEX" << endl;
    }

    int getChoice() {
        int ch;
        cin >> ch;
        return ch;
    }


};
