CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -lm
TARGET = main
OBJECTS = main.o poisson.o

.PHONY : all clean debug

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

main.o: main.c poisson.h
	$(CC) $(CFLAGS) -c main.c

poisson.o: poisson.c poisson.h
	$(CC) $(CFLAGS) -c poisson.c

clean:
	rm -f $(TARGET) *.o

debug: $(TARGET)
	gdb ./$(TARGET) -c core
