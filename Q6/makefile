CC=clang++
CFLAGS=-Wall -Wextra -Werror

all: main

main: main.o phoneBook.o
	$(CC) $(CFLAGS) main.o phoneBook.o -o main

main.o: main.cpp phoneBook.hpp
	$(CC) $(CFLAGS) -c main.cpp

phoneBook.o: phoneBook.cpp phoneBook.hpp
	$(CC) $(CFLAGS) -c phoneBook.cpp

clean:
	rm -f main main.o phoneBook.o
