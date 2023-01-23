#include "Employee.h"

Employee::Employee() {
    this->name = "";
    this->position = "";
    this->age = 0;
}

Employee::Employee(std::string name, std::string position, int age) {
    this->name = name;
    this->position = position;
    this->age = age;
}

Employee::Employee(const Employee& employee) {
    this->name = employee.name;
    this->position = employee.position;
    this->age = employee.age;
}

Employee& Employee::operator=(const Employee& employee) {
    this->name = employee.name;
    this->position = employee.position;
    this->age = employee.age;
    return *this;
}

Employee::~Employee() {}

std::ostream& operator<<(std::ostream& stream, const Employee& employee) {
    stream << "Name: " << employee.name << ", position: " << employee.position << ", age: " << employee.age;
    return stream;
}
