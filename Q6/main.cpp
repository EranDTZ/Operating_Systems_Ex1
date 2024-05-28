#include <iostream>
#include <fstream>
#include <sstream>
#include "phoneBook.hpp"

int main() {
    // // Read phonebook.txt
    std::ifstream infile("phonebook_copy.txt");
    std::string line;
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        std::string name, phoneNumber;
        if (std::getline(iss, name, ',') && std::getline(iss, phoneNumber)) {
            // Add entry to phonebook
            add2PB(name.c_str(), phoneNumber.c_str());
        }
    }
    infile.close();
    findPhone("John");
    findPhone("Eran");
    add2PB("Eran Tzarum", "207640806");
    findPhone("Eran");
    // printPhoneBook();

    return 0;
}
