CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
TARGET = main
OBJECTS = main.o failures.o

.PHONY : all clean debug

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)

main.o: main.c failures.h
	$(CC) $(CFLAGS) -c main.c

failures.o: failures.c failures.h
	$(CC) $(CFLAGS) -c failures.c

clean:
	rm -f $(TARGET) *.o

debug: $(TARGET)
	gdb ./$(TARGET) -c core
