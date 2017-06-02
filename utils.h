/*
 * utils.h
 *
 *  Created on: May 27, 2017
 *      Author: Dor
 */

#ifndef UTILS_H_
#define UTILS_H_
#include <stdio.h>


complex a,b,c,d,e,f;

struct {
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

void print_error(char* error);


#endif /* UTILS_H_ */
