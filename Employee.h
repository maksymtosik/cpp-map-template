#pragma once
#include <iostream>

class Employee {
    public:
        std::string name;
        std::string position;
        int age;
        Employee();
        Employee(std::string name, std::string position, int age);
        Employee(const Employee& employee);
        Employee& operator=(const Employee& employee);
        ~Employee();
        friend std::ostream& operator<<(std::ostream& stream, const Employee& employee);
};
