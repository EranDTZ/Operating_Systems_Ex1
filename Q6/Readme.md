
---

# Phone Book Management

This project demonstrates a simple phone book management system using C++ and UNIX system calls like `pipe`, `fork`, and `execve`. The phone book is stored in a text file named `phonebook.txt`.

## Overview

The project includes the following functionalities:
- Adding a contact to the phone book.
- Finding and displaying a contact's phone number.
- Printing all contacts in the phone book.
- Preventing the addition of duplicate contacts.

## Files

- `phoneBook.hpp`: Header file containing function declarations.
- `phoneBook.cpp`: Source file containing function definitions.
- `main.cpp`: Main file demonstrating the usage of the phone book functions.

## Functions

### add2PB

```cpp
void add2PB(const char* name, const char* phoneNumber);
```

Adds a new contact to the phone book if it does not already exist. Uses `pipe`, `fork`, and `execve` to achieve the functionality.

### findPhone

```cpp
bool findPhone(const char* name, const char* phoneNumber = nullptr);
```

Searches for a contact by name in the phone book and prints the contact details if found. Returns `true` if the contact is found, otherwise returns `false`.

### printPhoneBook

```cpp
void printPhoneBook();
```

Prints all contacts in the phone book.

## Usage

### Adding a Contact

To add a contact, use the `add2PB` function:

```cpp
add2PB("John Doe", "123-4567890");
```

### Finding a Contact

To find and display a contact, use the `findPhone` function:

```cpp
findPhone("John Doe");
```

### Printing All Contacts

To print all contacts in the phone book, use the `printPhoneBook` function:

```cpp
printPhoneBook();
```

## Examples

Here is an example demonstrating the usage of the functions in `main.cpp`:

```cpp
#include "phoneBook.hpp"

int main() {
    // Add contacts to the phone book
    add2PB("Nezer Zaidenberg", "054-5531415");
    add2PB("John Doe", "123-4567890");
    add2PB("Jane Smith", "098-7654321");

    // Find contacts
    findPhone("John Doe");
    findPhone("Jane Smith");

    // Attempt to add a duplicate contact
    add2PB("John Doe", "123-4567890");  // Should not add, as it exists

    // Print all contacts
    printPhoneBook();

    return 0;
}
```

## Compiling and Running

To compile the project, use the following command:

```sh
g++ -o main main.cpp phoneBook.cpp
```

To run the compiled program:

```sh
./main
```

## Notes

- Ensure the `phonebook.txt` file is in the same directory as the executable. If the file does not exist, it will be created automatically.
- The functions use UNIX-specific system calls, so this code is intended to be run on a UNIX-like operating system.

---
