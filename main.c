/*
 * Main.c
 *
 *  Created on: May 24, 2017
 *      Author: Dor
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "complex.h"

unsigned getdelim(char **buf, size_t *bufsiz, int delimiter, FILE *fp);
unsigned getLine(char **buf, size_t *bufsiz, FILE *fp);
void print_error(char* error);


enum commands_id
{
	READ_COMP, PRINT_COMP, ADD_COMP, SUB_COMP, MULT_COMP_REAL, MULT_COMP_IMG,
	MULT_COMP_COMP, ABS, HALT
};

char* commands[] = {"read_comp", "print_comp", "add_comp", "sub_comp", "mult_comp_real",
		"mult_comp_img", "mult_comp_comp", "abs", "halt"};

int main()
{
	unsigned int read;
	char* line = NULL;
	size_t len = 0;
	read = getLine(&line, &len, stdin);
printf("%ld\n",len);
	while(read != -1 || strcmp(line, commands[HALT]) == 0)
	{
		printf("%s\n", line);
		read = getLine(&line, &len, stdin);
	}
	if(strcmp(line, commands[HALT]) != 0)
	{
		print_error(MISSING_HALT);
	}
	return 0;
}

void print_error(char* error)
{
	printf("%s\n", error);
}

unsigned getdelim(char **buf, size_t *bufsiz, int delimiter, FILE *fp)
{
	char *ptr, *eptr;


	if (*buf == NULL || *bufsiz == 0) {
		*bufsiz = BUFSIZ;
		if ((*buf = malloc(*bufsiz)) == NULL)
			return -1;
	}

	for (ptr = *buf, eptr = *buf + *bufsiz;;) {
		int c = fgetc(fp);
		if (c == -1) {
			if (feof(fp))
				return ptr == *buf ? -1 : ptr - *buf;
			else
				return -1;
		}
		*ptr++ = c;
		if (c == delimiter) {
			*ptr = '\0';
			return ptr - *buf;
		}
		if (ptr + 2 >= eptr) {
			char *nbuf;
			unsigned nbufsiz = *bufsiz * 2;
			unsigned d = ptr - *buf;
			if ((nbuf = realloc(*buf, nbufsiz)) == NULL)
				return -1;
			*buf = nbuf;
			*bufsiz = nbufsiz;
			eptr = nbuf + nbufsiz;
			ptr = nbuf + d;
		}
	}
	return *bufsiz;
}

unsigned getLine(char **buf, size_t *bufsiz, FILE *fp)
{
	return getdelim(buf, bufsiz, '\n', fp);
}

