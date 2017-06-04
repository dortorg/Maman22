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
    	printf("enter_command   %s\n",token);

		strcpy(command->command, token);

		token = strtok(NULL, "\n");
    	printf("enter_command   %s\n",token);

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
        	execute(cmd[i], command);
        	break;
        }
    }
    if(cmd[i].func == NULL)
    {
    	print_error(NOT_EXIST);
    }

}

int check_none_args(char* args)
{
	printf("check_none_args %s\n", args);

	remove_spaces(args);
	printf("check_none_args %s\n", args);
	if(strlen(args) == 0)
	{
		print_error(NO_ARGS);
		return FALSE;
	}
	if(strlen(args) > 1)
	{
		print_error(EXCESSIVE_TEXT);
		return FALSE;
	}
	if(!(strcmp(args, "A") >= 0 && strcmp(args, "F") <= 0))
	{
		print_error(INVALID_COMPLEX);
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

void execute_none(char* args,  void (*func)())
{
	int i;
	if(check_none_args(args) == TRUE)
	{
		for(i = 0; storage[i].var != NULL; ++i)
		{
			if(strcmp(storage[i].name, args) == 0)
			{
				func(storage[i].var);
				break;
			}
		}
	}
}

void remove_spaces(char* source)
{
  char* i = source;
  char* j = source;
  while(*j != 0)
  {
    *i = *j++;
    if(*i != ' ')
      i++;
  }
  *i = 0;
}

void execute(struct cmd cmd, command com)
{
	switch(cmd.funcParam)
	{
	case NONE:
		execute_none(com.args, cmd.func);
		break;
	case VAR:
		break;
	case ARGS:
		break;
	case SCALAR:
		break;
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
