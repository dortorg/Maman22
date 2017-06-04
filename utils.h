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
enum inputParams       {VAR, ARGS, SCALAR, NONE};
static struct cmd{
    char *name;
    void (*func)();
    int funcParam;
}cmd[] = {
    {"read_comp", read_comp, ARGS},
    {"print_comp", print_comp, NONE},
    {"add_comp", add_comp, VAR},
    {"sub_comp", sub_comp, VAR},
    {"mult_comp_real", mult_comp_real, SCALAR},
    {"mult_comp_img", mult_comp_img, SCALAR},
    {"mult_comp_comp", mult_comp_comp, VAR},
    {"abs_comp", abs_comp, NONE},
    {"not_valid", NULL, NONE}
};

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
	"*ERROR: no args enter\n",
};

enum error_id
{
	NOT_EXIST, INVALID_COMPLEX, INVALID_COMMAND, WORNG_PARAMETER_1, WORNG_PARAMETER_2_COMPLEX,
	WORNG_PARAMETER_2_REAL, MISSING_COMMA, MULTIPLE_COMMAS, EXCESSIVE_TEXT, MISSING_HALT, NO_ARGS
};

typedef struct command
{
	char command[30];
	char args[30];
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

enum bool{FALSE, TRUE};

enum commands_id
{
	READ_COMP, PRINT_COMP, ADD_COMP, SUB_COMP, MULT_COMP_REAL, MULT_COMP_IMG,
	MULT_COMP_COMP, ABS, HALT
};

void menu();

int enter_command(command* command);

void init_complexs();

void print_error(int error);

void handle_command(command command);

void halt(char* command);

void execute_none(char* args,  void (*func)());

void execute(struct cmd cmd, command com);

int check_none_args(char* args);

void remove_spaces(char* source);


#endif /* UTILS_H_ */
