#ifndef PHONEBOOK_H
#define PHONEBOOK_H

bool contactExists(const char* name, const char* phoneNumber);
void add2PB(const char* name, const char* phoneNumber);
void findPhone(const char* name);
void printPhoneBook();

#endif // PHONEBOOK_H
