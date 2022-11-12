#pragma once
#include<iostream>
#include <iomanip>
using namespace std;

class Employee
{
private:
	int id;
	string name;
	char sex;
	string phone;

public:
	Employee() :id(0), name("unknow"), sex(), phone() {}
	Employee(int id, string name, char sex, string phone) :id(id), name(name), sex(sex), phone(phone) {}
	~Employee() {

	}

	void setId(int id) {
		if (id > 0 && id < 1000) {
			this->id = id;
		}
		else {
			throw "ID must be positve";
		}
	}
	int getId() {
		return id;
	}

	void setName(string name) {
		this->name = name;
	}

	string getName() {
		return name;
	}

	void setSex(char sex) {
		this->sex = sex;
	}

	void setPhone(string phone) {
		this->phone = phone;
	}
	virtual void input() {
		cout << "Input Employee Info" << endl;
		cout << "Enter ID: ";
		do {
			try {
				cin >> id;
				break;
			}
			catch (const char* message) {
				cout << message << endl;
			}
		} while (true);
		cout << "Enter Name: ";
		cin >> name;
		cout << "Enter Gender(M/F): ";
		cin >> sex;
		cout << "Enter Phone Number: ";
		cin >> phone;
	}
	virtual void output() {
		cout << id << "\t" << name << "\t" << sex << "\t" << phone;
	}

};