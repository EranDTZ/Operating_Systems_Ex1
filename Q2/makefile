CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
LDFLAGS = -lm
TARGET = main
OBJECTS = main.o poisson.o

.PHONY: all clean debug

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

main.o: main.c poisson.h
	$(CC) $(CFLAGS) -c main.c

poisson.o: poisson.c poisson.h
	$(CC) $(CFLAGS) -c poisson.c

clean:
	rm -f $(TARGET) *.o