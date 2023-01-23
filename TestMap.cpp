#include "Employee.h"                                                    // Defines class Employee
#include "Map.h"                                                        // Defines template Map<Key, Value>
#include "BookInfo.h"                                                // Defines class BookInfo

typedef unsigned int ID;                                                 // Identification number of employee
typedef Map<ID, Employee> Database;                            // Database of employees

typedef std::string Title;                                                    // Title of book
typedef Map<Title, BookInfo> Library;                            // Library of books

void testEmployeesDatabase();
void addEmployees(Database& database);
void modifyEmployees(Database& database);

void testBooksLibrary();
void addBooks(Library& library);
void modifyBooks(Library& library);

int main() {
    testEmployeesDatabase();
    testBooksLibrary();
}

void testEmployeesDatabase() {
    Database database;
    addEmployees(database);

    Database newDatabase = database;                                    // Make a copy of database
    newDatabase.add(830505432, Employee("Ewa Nowak", "chairwoman", 43));    // Add fourth employee
    modifyEmployees(newDatabase);

    std::cout << "Original database:" << std::endl << database << std::endl;
    std::cout << "Modified database:" << std::endl << newDatabase << std::endl;

    database = newDatabase;                                                // Update original database
    std::cout << "Database after the assignment:" << std::endl << database << std::endl;
}

void addEmployees(Database& database) {
    database.add(761028073, Employee("Jan Kowalski", "salesman", 28));     // Add first employee: name: Jan Kowalski, position: salseman, age: 28,
    database.add(510212881, Employee("Adam Nowak", "storekeeper", 54));    // Add second employee
    database.add(730505129, Employee("Anna Zaradna", "secretary", 32));    // Add third employee
}

void modifyEmployees(Database& database) {
    Employee* employeePtr;

    employeePtr = database.find(510212881);                                // Find employee using its ID
    employeePtr->position = "salesman";                                    // Modify the position of employee
    employeePtr = database.find(761028073);                                // Find employee using its ID
    employeePtr->age = 29;                                                // Modify the age of employee
}

void testBooksLibrary() {
    Library library;
    addBooks(library);
    Library newLibrary = library;
    try {
        newLibrary.add("Python for dummies", BookInfo("Stef Maruch", "educational", 725, false));
        std::cout << "Trying to add a book with the same title as an existing book: ";
        newLibrary.add("Python for dummies", BookInfo("Aahz Maruch", "educational", 725, true));
    } catch (KeyAlreadyExistsException& e) {
        std::cout << e.what() << std::endl;
    }
    modifyBooks(newLibrary);
    std::cout << "Original library:" << std::endl << library << std::endl;
    std::cout << "Modified library:" << std::endl << newLibrary << std::endl;
    newLibrary.remove("TIHKAL: The Continuation");
    std::cout << "Library after removing a book:" << std::endl << newLibrary << std::endl;
    try{
        std::cout << "Trying to remove a non-existent book: ";
        newLibrary.remove("Non existent book");
    } catch (KeyNotFoundException& e) {
        std::cout << e.what() << std::endl;
    }
    try{
        std::cout << "Trying to find a non-existent book: ";
        newLibrary.find("Non existent book");
    }catch (KeyNotFoundException& e) {
        std::cout << e.what() << std::endl;
    }
    library = newLibrary;
    std::cout << "Library after the assignment:" << std::endl << library << std::endl;
}

void addBooks(Library& library) {
    library.add("PIHKAL. A chemical love story", BookInfo("Alexander Shulgin", "Chemical", 1123, true));
    library.add("Anarchist cookbook", BookInfo("William Powell", "educational", 234, false));
    library.add("TIHKAL: The Continuation", BookInfo("Alexander Shulgin", "Chemical", 943, true));
}

void modifyBooks(Library& library) {
    BookInfo* bookInfoPtr;
    bookInfoPtr = library.find("PIHKAL. A chemical love story");
    bookInfoPtr->isAvailable = false;
    bookInfoPtr = library.find("Anarchist cookbook");
    bookInfoPtr->numberOfPages = 136;
}
