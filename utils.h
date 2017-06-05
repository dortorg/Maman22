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
#define LINE "################################################\n"
#define HALT "halt"
#define DEFAULT_SIZE 100


complex a,b,c,d,e,f;


enum inputParams {VAR, ARGS, SCALAR, NONE};


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

/************* ERROR HANDLING *******************/

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
	"*ERROR: invalid args\n",

};

enum error_id
{
	NOT_EXIST, INVALID_COMPLEX, INVALID_COMMAND, WORNG_PARAMETER_1, WORNG_PARAMETER_2_COMPLEX,
	WORNG_PARAMETER_2_REAL, MISSING_COMMA, MULTIPLE_COMMAS, EXCESSIVE_TEXT, MISSING_HALT, NO_ARGS, INVALID_ARGS, SUCCESS
};

typedef struct command
{
	char command[DEFAULT_SIZE];
	char args[DEFAULT_SIZE];
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

typedef enum { false = 0, true } bool;


/*********** FUNCTION DECLARATION ***********/


/************ API *************************/

/*
 * init all complexes A to F with 0
 */
void init_complexes();

/*
 * print simple user manual to know the context
 */
void menu();

/*
 * get input from the user, and insert to command
 */
int enter_command(command* command);

/*
 * Responsible to check the command, and return the result to the user
 */
void handle_command(command command);


/********** HANDLER FUNCTIONS **********/
/*
 * all the commands part to 4 types :
 * none, var, args, scalar
 */

/*
 * manage all types
 */
void execute(struct cmd cmd, command com);

/*
 * functions who get just complex, for example:
 * print_comp A
 */
void execute_none(char* args,  void (*func)());

/*
 * functions who get 2 complex, for example:
 * add_comp A,B
 */
void execute_var(char* args,  void (*func)());

/*
 * functions who get complex and parameter, for example:
 * mult_comp_real A,5
 */
void execute_args(char* args,  void (*func)());

/*
 * functions who get complex and 2 parameters, for example:
 * read_comp A,5,6
 */
void execute_scalar(char* args,  void (*func)());


/********** MAIN CHECKING & PARSE FUNCTIONS **********/

bool check_none_args(char* args);

bool check_var_args(char* args, char* compA, char* compB);

bool check_args_args(char* args, char* compA, double* real, double* img);

bool check_scalar_args(char* args, char* compA, double* parameter);



/*********** HELP FUNCTIONS ***********/

/*
 * print specific error from the errors poll
 */
void print_error(int error_id);

/*
 * remove all spaces from string
 */
void remove_spaces(char* source);

/*
 * get parm of A to F in string, and return the real complex A to F
 */
complex* string2complex(char* af);

/*
 * check if the string is between A to F
 */
bool check_A2F(char* af);

/*
 * check if empty line
 */
bool isEmptyLine(const char *s);

/*
 * check if halt command
 */
void halt(char* command);

#endif /* UTILS_H_ */
