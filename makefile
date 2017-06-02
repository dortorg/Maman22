.PHONY: all clean
all: complex

CC = gcc
CFLAGES = -Wall -ansi -pedantic
OBJECTS = complex.o main.o utils.o

main: main.o complex.o
	gcc -ansi -Wall -pedantic -lm -o complex main.o complex.o

complex: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -O complex

%.o: %.c
	$(CC) $(CFLAGS) -c $<
clean:
	rm *.o *~complex
