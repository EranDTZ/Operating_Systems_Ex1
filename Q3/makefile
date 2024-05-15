CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -fPIC
LDFLAGS = -shared
TARGET = main libpoisson.so
OBJECTS = main.o poisson.o

.PHONY: all clean debug

all: $(TARGET)

main: main.o poisson.o
	$(CC) $(CFLAGS) $(OBJECTS) -o main -lm

libpoisson.so: poisson.o
	$(CC) $(CFLAGS) $(LDFLAGS) poisson.o -o libpoisson.so

main.o: main.c poisson.h
	$(CC) $(CFLAGS) -c main.c

poisson.o: poisson.c poisson.h
	$(CC) $(CFLAGS) -c poisson.c

clean:
	rm -f $(TARGET) *.o
