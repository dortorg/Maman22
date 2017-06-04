/*
 * utils.c
 *
 *  Created on: May 27, 2017
 *      Author: Dor
 */

#include "utils.h"
#include <string.h>
#include <memory.h>
#include <stdlib.h>


void menu()
{
	printf("Please enter valid function name and suitable parameters\n");
	printf( "Available functions:\n");
	printf("read_comp           [complex number],[parameter],[parameter]\n");
	printf("print_comp          [complex number]\n");
	printf("add_comp            [complex number],[complex number]\n");
	printf("sub_comp            [complex number],[complex number]\n");
	printf("mult_comp_real      [complex number],[scalar]\n");
	printf("mult_comp_img       [complex number],[scalar]\n");
	printf("mult_comp_comp      [complex number],[complex number]\n");
	printf("abs_comp            [complex number]\n");
	printf("halt                [none]\n");

}

int enter_command(command* command)
{
	int flag = EOF;
	char str[100];
	char *token;

	printf(LINE);
	printf("Enter command: \n");

	if(fgets(str, sizeof(str), stdin) != NULL)
	{
		token = strtok(str, " \n");
/*    	printf("enter_command   %s\n",token);*/

		strcpy(command->command, token);

		token = strtok(NULL, "\n");
/*    	printf("enter_command   %s\n",token);*/

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
/*	printf("handle_command   %s\n",command.args);*/

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
	if(check_A2F(args) == FALSE)
	{
		print_error(INVALID_COMPLEX);
		return FALSE;
	}
	return TRUE;
}

int check_A2F(char* af)
{
	if(af[0] >= 'A' && af[0] <= 'F')
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void execute_none(char* args,  void (*func)())
{
	complex* comp;
	if(check_none_args(args) == TRUE)
	{
		printf("execute_none %s\n", args);
		comp = string2complex(args);
		if(comp != NULL)
		{
			func(comp);
		}
		else
		{
			print_error(INVALID_COMPLEX);
		}
	}
}

complex* string2complex(char* af)
{
	int i;
	for(i = 0; storage[i].var != NULL; ++i)
	{
		if(strcmp(storage[i].name, af) == 0)
		{
			return storage[i].var;
		}
	}
	return NULL;
}

void execute_var(char* args,  void (*func)())
{
	char compA[2], compB[2];
	int i;
	if(check_var_args(args,compA, compB) == TRUE)
	{
		printf("execute_var %s , %s\n",compA, compB);


	}
}

int check_var_args(char* args, char* compA, char* compB)
{
	int flag;
	if(strlen(args) == 3)
	{
		flag = sscanf(args, "%c,%c", compA, compB);
		if(flag == 2)
		{
			if(check_A2F(compA) == TRUE && check_A2F(compB) == TRUE)
			{
				return TRUE;
			}
		}
		printf("check_var_args %s , %s\n",compA, compB);
	}
	return FALSE;
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
	remove_spaces(com.args);

	switch(cmd.funcParam)
	{
	case NONE:
/*		printf("execute %s\n", com.args);*/

		execute_none(com.args, cmd.func);
		break;
	case VAR:
		execute_var(com.args, cmd.func);

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
