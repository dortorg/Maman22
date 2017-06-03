/*
 * utils.c
 *
 *  Created on: May 27, 2017
 *      Author: Dor
 */

#include "utils.h"
#include <string.h>
#include <memory.h>



void menu()
{
	printf("Please enter valid function name and suitable parameters\n");
	printf( "Available functions:\n");
	printf("read_comp           [complex number],[parameter],[parameter]\n");
	printf("print_comp          [complex number]\n");
	printf("add_comp            [complex number],[complex number]\n");
	printf("sub_comp            [complex number]\n");
	printf("mult_comp_real      [complex number],[scalar]\n");
	printf("mult_comp_img       [complex number],[scalar]\n");
	printf("mult_comp_comp      [complex number],[complex number]\n");
	printf("abs_comp            [complex number]\n");
	printf("halt                [none]\n");

}

int enter_command(command* command)
{
	int flag = EOF;
	char str[30];
	char *token;
	printf("Enter command: \n");

	if(fgets(str, sizeof(str), stdin) != NULL)
	{
		token = strtok(str, " \n");
		strcpy(command->command, token);
		token = strtok(NULL, "\n");
		if(token != NULL)
		{
			strcpy(command->args, token);
		}
		else
		{
			strcpy(command->args, "\0");
		}
		flag = 1;
	}
	return 	flag;
}

void handle_command(command command)
{
	int i;

	halt(command.command);
    /*through over all command list*/
    for(i=0; cmd[i].func != NULL; i++)
    {
        if(strcmp(command.command, cmd[i].name) == 0)
        {
        	printf("fine!!!\n");
        }
        else
        {
        	print_error(NOT_EXIST);
        	break;
        }
    }

}

void halt(char* command)
{
	if(strcmp(command, commands[HALT]) == 0)
	{
		printf("Bye bye!!\n");
		exit(1);
	}
}


void init_complexs()
{
	int i;
	for(i = 0; i < SIZE; ++i)
	{
		storage[i].var->img = 0;
		storage[i].var->real = 0;
	}
}

void print_error(int error)
{
	printf("ERROR: %s\n",errorMsgs[error]);
}
