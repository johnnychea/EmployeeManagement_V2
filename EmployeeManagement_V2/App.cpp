#pragma once
#include <xmemory>
#include <vector>
#include <iostream>
#include "Employee.cpp"
#include "SalariedEmployee.cpp"
#include "HourlyEmployee.cpp"
#include "EmployeeService.cpp"

using namespace std;
enum {
    EXIT,
    ADD,
    VIEW,
    SEARCH,
    SORT,
    EDIT,
    DELETE,
    SAVE,
    LOAD
};

enum {
    SALARIED_EMPLOYEE = 1,
    HOURLY_EMPLOYEE
};

class App
{
public:
    void run()
    {
        string name;
        char op;
        int ch;
        int id;
        EmployeeService employeeservice;
        SalariedEmployee sEmployee;
        HourlyEmployee hEmployee;

        do
        {
            system("cls");
            menu();
            ch = getCommand();
            system("cls");

            switch (ch)
            {
            case ADD:
                do
                {
                    addMenu();
                    ch = getChoice();
                    switch (ch)
                    {
                    case SALARIED_EMPLOYEE:
                        sEmployee.input();
                        employeeservice.addEmployee(&sEmployee);
                        break;
                    case HOURLY_EMPLOYEE:
                        hEmployee.input();
                        employeeservice.addEmployee(&hEmployee);
                        break;
                    }
                    cout << "Do you want to add more?(Y/N)";
                    op = getOption();
                } while (op != 'n' && op != 'N');
                break;
            case VIEW:
                employeeservice.viewEmployee();
                break;
            case SEARCH:
                cout << "Enter Employee ID to Search: ";
                cin >> id;
                employeeservice.searchEmployee(id);
                break;
            case SORT:
                employeeservice.sortEmployee();
                break;
            case EDIT:
                cout << "Enter Employee ID to Edit: ";
                cin >> id;
                employeeservice.editEmployee(id);
                break;
            case DELETE:
                cout << "Enter Employee ID to delete: ";
                cin >> id;
                employeeservice.deleteEmployee(id);
                break;
            case SAVE:
                employeeservice.saveEmployeeToFile();
                cout << "Data has been saved" << endl;
                break;
            case LOAD:
                employeeservice.loadEmployeeFromFile();
                cout << "Data has been loaded" << endl;
                break;
            case EXIT:
                exit(1);
            }
            system("pause");
        } while (ch != 0);

    }

    void menu() {
        cout << "...............EMPLOYEE MANAGEMENT SYSTEM..............\n";
        cout << "======================================================\n";

        cout << "1. Add Employee\n";
        cout << "2. Display All Employee\n";
        cout << "3. Search Employee\n";
        cout << "4. Sort Employee\n";
        cout << "5. Edit Employee\n";
        cout << "6. Delete Employee\n";
        cout << "7. Save Employee Data\n";
        cout << "8. Load Employee Data\n";
        cout << "0. Exit from Program\n";
        cout << "Enter (0-8): ";
    }
    void addMenu() {
        cout << "======Add Employee=====\n";
        cout << "1. Salaried Employee\n";
        cout << "2. Hourly Employee\n";
        cout << "Choose (1-2): ";
    }

    int getCommand() {
        int ch;
        cin >> ch;
        return ch;
    }
    int getChoice() {
        int ch;
        cin >> ch;
        return ch;
    }
    char getOption() {
        char op;
        cin >> op;
        return op;
    }

};

