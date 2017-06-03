/*
 * utils.h
 *
 *  Created on: May 27, 2017
 *      Author: Dor
 */

#ifndef UTILS_H_
#define UTILS_H_

#include <stdio.h>
#include "complex.h"


#define SIZE 6

complex a,b,c,d,e,f;

static char* commands[] = {"read_comp", "print_comp", "add_comp", "sub_comp", "mult_comp_real",
		"mult_comp_img", "mult_comp_comp", "abs_comp", "halt"};



/*List: Errors*/
static char *errorMsgs[] = {
    "*ERROR: command does not exist\n",
    "*ERROR: invalid complex variable\n",
    "*ERROR: invalid command\n",
    "*ERROR: wrong parameter, first parameter must be complex\n",
    "*ERROR: wrong parameter, second parameter must be complex\n",
    "*ERROR: wrong parameter, second parameter must be a real number\n",
    "*ERROR: missing comma\n",
	"*ERROR: multiple consecutive commas\n",
	"*ERROR: excessive text\n",
	"*ERROR: not end with halt\n",
};

enum error_id
{
	NOT_EXIST, INVALID_COMPLEX, INVALID_COMMAND, WORNG_PARAMETER_1, WORNG_PARAMETER_2_COMPLEX,
	WORNG_PARAMETER_2_REAL, MISSING_COMMA, MULTIPLE_COMMAS, EXCESSIVE_TEXT, MISSING_HALT
};

typedef struct command
{
	char* command[10];
	char* args[20];
}command;

static struct {
   char *name;
   complex *var;
}storage[] = {
   {"A",&a},
   {"B",&b},
   {"C",&c},
   {"D",&d},
   {"E",&e},
   {"F",&f},
   {"0", NULL}
};



enum commands_id
{
	READ_COMP, PRINT_COMP, ADD_COMP, SUB_COMP, MULT_COMP_REAL, MULT_COMP_IMG,
	MULT_COMP_COMP, ABS, HALT
};

void menu();

int enter_command(command* command);

void init_complexs();

void print_error(int error);


#endif /* UTILS_H_ */
