.PHONY: all clean
all: complex

CC = gcc
CFLAGES = -Wall -ansi -pedantic
OBJECTS = complex.o main.o utils.o

complex: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o complex -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $<
clean:
	rm *.o *~complex
