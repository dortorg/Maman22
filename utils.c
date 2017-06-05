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

/********** API **********/

void init_complexes()
{
	int i;
	for(i = 0; i < SIZE; ++i)
	{
		storage[i].var->img = 0;
		storage[i].var->real = 0;
	}
}

void menu()
{
	printf("Please enter valid function name and suitable parameters\n");
	printf( "Available functions:\n");
	printf("read_comp           [complex number],[parameter],[parameter]\n");
	printf("print_comp          [complex number]\n");
	printf("add_comp            [complex number],[complex number]\n");
	printf("sub_comp            [complex number],[complex number]\n");
	printf("mult_comp_real      [complex number],[parameter]\n");
	printf("mult_comp_img       [complex number],[parameter]\n");
	printf("mult_comp_comp      [complex number],[complex number]\n");
	printf("abs_comp            [complex number]\n");
	printf("halt                [none]\n");

}

int enter_command(command* command)
{
	int flag = EOF;
	char str[100];
	char *token;

	if(fgets(str, 100, stdin) != NULL)
	{
		if(isEmptyLine(str) != true)
		{
			printf("%s\n", str);
			token = strtok(str, " \n");
			strncpy(command->command, token, 50);
			token = strtok(NULL, "\n");

			if(token != NULL)
			{
				strncpy(command->args, token, 50);
			}
			else
			{
				strncpy(command->args, "\0", 50);
			}
		}
		else
		{
			strncpy(command->command, "\0", 2);
			strncpy(command->args, "\0", 2);
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


/*************** HANDLER FUNCTIONS *******************/

void execute(struct cmd cmd, command com)
{
	remove_spaces(com.args);

	switch(cmd.funcParam)
	{
	case NONE:
		execute_none(com.args, cmd.func);
		break;
	case VAR:
		execute_var(com.args, cmd.func);
		break;
	case ARGS:
		execute_args(com.args, cmd.func);
		break;
	case SCALAR:
		execute_scalar(com.args, cmd.func);
		break;
	}
}

void execute_none(char* args,  void (*func)())
{
	complex* comp;
	if(check_none_args(args) == true)
	{
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

void execute_var(char* args,  void (*func)())
{
	char compA[2], compB[2];
	complex* complexA;
	complex* complexB;

	if(check_var_args(args,compA, compB) == true)
	{
		complexA = string2complex(compA);
		complexB = string2complex(compB);
		if(complexA != NULL && complexB != NULL)
		{
			func(complexA, complexB);
		}
		else
		{
			print_error(INVALID_COMPLEX);
		}
	}
}

void execute_args(char* args,  void (*func)())
{
	complex* comp;
	char compA[2];
	double real, img;
	if(check_args_args(args, compA, &real, &img) == true)
	{
		comp = string2complex(compA);
		if(comp != NULL)
		{
			func(comp, real, img);
		}
		else
		{
			print_error(INVALID_COMPLEX);
		}
	}
}

void execute_scalar(char* args,  void (*func)())
{

}


/*********************** MAIN CHECKING & PARSE FUNCTIONS ****************************/


bool check_none_args(char* args)
{
	if(strlen(args) == 0)
	{
		print_error(NO_ARGS);
		return false;
	}
	if(strlen(args) > 1)
	{
		print_error(EXCESSIVE_TEXT);
		return false;
	}
	if(check_A2F(args) == false)
	{
		print_error(INVALID_COMPLEX);
		return false;
	}
	return true;
}

bool check_var_args(char* args, char* compA, char* compB)
{
	int flag;
	char a,b;
	if(strlen(args) == 3)
	{
		flag = sscanf(args, "%c,%c", &a, &b);
		if(flag == 2)
		{
			strncpy(compA, &a, 1);
			compA[1] = '\0';
			strncpy(compB, &b, 1);
			compB[1] = '\0';

			if(check_A2F(compA) == true && check_A2F(compB) == true)
			{
				return true;
			}
			else
			{
				if(check_A2F(compA) == true)
				{
					print_error(WORNG_PARAMETER_2_COMPLEX);
					return false;
				}
				else
				{
					print_error(WORNG_PARAMETER_1);
					return false;
				}
			}
		}
	}
	if(strlen(args) == 2)
	{
		flag = sscanf(args, "%c%c", &a, &b);
		if(flag == 2)
		{
			strncpy(compA, &a, 1);
			compA[1] = '\0';
			strncpy(compB, &b, 1);
			compB[1] = '\0';

			if(check_A2F(compA) == true && check_A2F(compB) == true)
			{
				print_error(MISSING_COMMA);
				return false;
			}
			else
			{
				print_error(INVALID_ARGS);
				return false;
			}
		}
	}
	if(strlen(args) >= 4)
	{
		flag = sscanf(args, "%c", &a);
		if(flag == 1)
		{
			strncpy(compA, &a, 1);
			compA[1] = '\0';

			if(check_A2F(compA) == true)
			{
				int i = 1;
				while(args[i] == ',' && args[i] != '\0'){i++;}
				if(args[i] != '\0')
				{
					flag = sscanf(args + i, "%c", &b);
					if(flag == 1)
					{
						strncpy(compB, &b, 1);
						compB[1] = '\0';
						if(check_A2F(compB) == true && args[i + 1] == '\0')
						{
							print_error(MULTIPLE_COMMAS);
							return false;
						}
					}
				}

				print_error(INVALID_ARGS);
				return false;
			}
			else
			{
				print_error(INVALID_ARGS);
				return false;
			}
		}
	}

	print_error(INVALID_ARGS);
	return false;
}

bool check_args_args(char* args, char* compA, double* real, double* img)
{
	int status = SUCCESS;
	int flag;
	char temp;
	int i = 0;
	flag = sscanf(args, "%c", &temp);
	if(flag == 1)
	{
		strncpy(compA, &temp, 1);
		compA[1] = '\0';
		if(check_A2F(compA) == false)
		{
			if(compA[0] >= 'G' && compA[0] <= 'Z')
			{

				status = INVALID_COMPLEX;
			}
			else
			{

				print_error(INVALID_ARGS);
				return false;
			}
		}
		++i;
	}
	else
	{

		print_error(INVALID_ARGS);
		return false;
	}

	flag = sscanf((args + i), ",%lf", real);
	printf("-1\n");

	if(flag == 1)
	{
		flag = sscanf((args + i), ",%lf,%lf", real, img);
		if(flag == 2 && status == SUCCESS)
		{
			printf("%d  ddddd\n",status);

			return true;
		}
	}
	else
	{
		printf("0\n");

		if(status == SUCCESS)
		{

			flag = sscanf((args + i), ",%c,%lf", &temp, img);
			if(flag == 2 && check_A2F(&temp) == true)
			{
				print_error(WORNG_PARAMETER_2_REAL);
				return false;
			}
			if(flag != 2)
			{
				printf("1\n");
				char* token = strtok(args + 1, ",");
				if(token != NULL)
				{
					printf("2\n");

					flag = sscanf(token, "%lf", img);
					if(flag == 1)
					{
						printf("3\n");

						token = strtok(NULL, ",");
						if(token != NULL)
						{
							printf("4\n");

							flag = sscanf(token, "%lf", img);
							if(flag == 1)
							{
								print_error(MULTIPLE_COMMAS);
								return false;
							}
							else
							{
								print_error(INVALID_ARGS);
								return false;
							}
						}
						else
						{
							print_error(INVALID_ARGS);
							return false;
						}
					}
					else
					{
						print_error(INVALID_ARGS);
						return false;
					}
				}
				else
				{
					print_error(INVALID_ARGS);
					return false;
				}
			}


			print_error(INVALID_ARGS);
			return false;

		}
		else
		{

			print_error(INVALID_ARGS);
			return false;
		}
	}

	print_error(INVALID_ARGS);
	return false;
}

bool check_scalar_args(char* args, char* compA, double* parameter)
{
	print_error(INVALID_ARGS);
	return false;
}



/********************************** HELP FUNCTIONS **********************************/

bool check_A2F(char* af)
{
	if(af[0] >= 'A' && af[0] <= 'F')
	{
		return true;
	}
	else
	{
		return false;
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

bool isEmptyLine(const char *s) {
  static const char *emptyline_detector = " \t\n";

  return strspn(s, emptyline_detector) == strlen(s);
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

void halt(char* command)
{
	if(strcmp(command, HALT) == 0)
	{
		printf("Bye bye!!\n");
		exit(1);
	}
}

void print_error(int error)
{
	printf("ERROR: %s\n",errorMsgs[error]);
}
