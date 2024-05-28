#include "phoneBook.hpp"
#include <iostream>
#include <unistd.h>
#include <fstream>
#include <sys/wait.h>
#include <cstring>


bool contactExists(const char* name, const char* phoneNumber) {
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return false;
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return false;
    }

    if (pid == 0) {  // Child process
        close(pipefd[0]);  // Close unused read end
        dup2(pipefd[1], STDOUT_FILENO);  // Redirect stdout to pipe
        close(pipefd[1]);  // Close original write end after dup
        execlp("grep", "grep", name, "phonebook.txt", nullptr);
        perror("execlp");
        _exit(EXIT_FAILURE);
    } else {  // Parent process
        close(pipefd[1]);  // Close unused write end
        char buffer[4096];
        ssize_t bytesRead;
        bool found = false;
        while ((bytesRead = read(pipefd[0], buffer, sizeof(buffer))) > 0) {
            if (strstr(buffer, phoneNumber) != nullptr) {
                found = true;
                break;
            }
        }
        if (bytesRead == -1) {
            perror("read");
        }
        close(pipefd[0]);
        int status;
        waitpid(pid, &status, 0);  // Wait for child to finish
        return found;
    }
}

void add2PB(const char* name, const char* phoneNumber) {
    if (contactExists(name, phoneNumber)) {
        std::cout << "Contact already exists: " << name << ", " << phoneNumber << std::endl;
        return;
    }

    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return;
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return;
    }

    if (pid == 0) {  // Child process
        close(pipefd[0]);  // Close unused read end
        dup2(pipefd[1], STDOUT_FILENO);  // Redirect stdout to pipe
        close(pipefd[1]);  // Close original write end after dup

        // Use execlp to call echo with the provided name and phoneNumber
        execlp("echo", "echo", name, ",", phoneNumber, nullptr);
        perror("execlp");
        _exit(EXIT_FAILURE);
    } else {  // Parent process
        close(pipefd[1]);  // Close unused write end
        char buffer[4096];
        ssize_t bytesRead;

        std::ofstream outfile;
        outfile.open("phonebook.txt", std::ios::app); // Open file in append mode

        if (!outfile.is_open()) {
            perror("ofstream");
            return;
        }

        while ((bytesRead = read(pipefd[0], buffer, sizeof(buffer))) > 0) {
            outfile.write(buffer, bytesRead);  // Write to the file
        }
        if (bytesRead == -1) {
            perror("read");
        }

        close(pipefd[0]);
        outfile.close();

        int status;
        waitpid(pid, &status, 0);  // Wait for child to finish
    }
}



void findPhone(const char* name) {
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return;
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return;
    }

    if (pid == 0) {  // Child process
        close(pipefd[0]);  // Close unused read end
        dup2(pipefd[1], STDOUT_FILENO);  // Redirect stdout to pipe
        close(pipefd[1]);  // Close original write end after dup
        execlp("grep", "grep", name, "phonebook.txt", nullptr);
        perror("execlp");
        _exit(EXIT_FAILURE);
    } else {  // Parent process
        close(pipefd[1]);  // Close unused write end
        char buffer[4096];
        ssize_t bytesRead;
        bool found = false;
        while ((bytesRead = read(pipefd[0], buffer, sizeof(buffer))) > 0) {
            write(STDOUT_FILENO, buffer, bytesRead);
            found = true;
        }
        if (bytesRead == -1) {
            perror("read");
        }
        close(pipefd[0]);
        int status;
        waitpid(pid, &status, 0);  // Wait for child to finish

        if (!found) {
            std::cout << "Contact not found." << std::endl;
        }
    }
}


// void findPhone(const char* name) {
//     int pipefd[2];
//     if (pipe(pipefd) == -1) {
//         perror("pipe");
//         return;
//     }

//     pid_t pid = fork();
//     if (pid == -1) {
//         perror("fork");
//         return;
//     }

//     if (pid == 0) {  // Child process
//         close(pipefd[0]);  // Close unused read end
//         dup2(pipefd[1], STDOUT_FILENO);  // Redirect stdout to pipe
//         close(pipefd[1]);  // Close original write end after dup
//         execlp("grep", "grep", name, "phonebook.txt", nullptr);
//         perror("execlp");
//         _exit(EXIT_FAILURE);
//     } else {  // Parent process
//         close(pipefd[1]);  // Close unused write end
//         char buffer[4096];
//         ssize_t bytesRead;
//         while ((bytesRead = read(pipefd[0], buffer, sizeof(buffer))) > 0) {
//             write(STDOUT_FILENO, buffer, bytesRead);
//         }
//         if (bytesRead == -1) {
//             perror("read");
//         }
//         close(pipefd[0]);
//         int status;
//         waitpid(pid, &status, 0);  // Wait for child to finish

//         // If grep found the name, print the contact details
//         if (WEXITSTATUS(status) == 0) {
//             printContact(name);
//         }
//     }
// }



// void printContact(const char* name) {
//     int pipefd[2];
//     if (pipe(pipefd) == -1) {
//         perror("pipe");
//         return;
//     }

//     pid_t pid = fork();
//     if (pid == -1) {
//         perror("fork");
//         return;
//     }

//     if (pid == 0) {  // Child process
//         close(pipefd[0]);  // Close unused read end
//         dup2(pipefd[1], STDOUT_FILENO);  // Redirect stdout to pipe
//         close(pipefd[1]);  // Close original write end after dup
//         execlp("grep", "grep", name, "phonebook.txt", nullptr);
//         perror("execlp");
//         _exit(EXIT_FAILURE);
//     } else {  // Parent process
//         close(pipefd[1]);  // Close unused write end
//         char buffer[4096];
//         ssize_t bytesRead;
//         // bool found = false;
//         while ((bytesRead = read(pipefd[0], buffer, sizeof(buffer))) > 0) {
//             write(STDOUT_FILENO, buffer, bytesRead);
//             // found = true;
//         }
//         if (bytesRead == -1) {
//             perror("read");
//         }
//         close(pipefd[0]);
//         int status;
//         waitpid(pid, &status, 0);  // Wait for child to finish

//         // if (!found) {
//         //     std::cout << "Contact not found." << std::endl;
//         // }
//     }
// }



void printPhoneBook() {
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("pipe");
        return;
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return;
    }

    if (pid == 0) {  // Child process
        close(pipefd[0]);  // Close unused read end
        dup2(pipefd[1], STDOUT_FILENO);  // Redirect stdout to pipe
        close(pipefd[1]);  // Close original write end after dup
        execlp("cat", "cat", "phonebook.txt", nullptr);
        perror("execlp");
        _exit(EXIT_FAILURE);
    } else {  // Parent process
        close(pipefd[1]);  // Close unused write end
        char buffer[4096];
        ssize_t bytesRead;
        while ((bytesRead = read(pipefd[0], buffer, sizeof(buffer))) > 0) {
            write(STDOUT_FILENO, buffer, bytesRead);
        }
        if (bytesRead == -1) {
            perror("read");
        }
        close(pipefd[0]);
        int status;
        waitpid(pid, &status, 0);  // Wait for child to finish
    }
}

