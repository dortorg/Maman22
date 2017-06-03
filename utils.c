/*
 * utils.c
 *
 *  Created on: May 27, 2017
 *      Author: Dor
 */

#include "utils.h"
#include <string.h>




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
	int flag = 0;
	char str[30];
	char* token;
	printf("Enter command: \n");
	flag = scanf("%s", str);
	if(flag != EOF)
	{
		int inputLength = strlen(str);
		char *inputCopy = (char*) calloc(inputLength + 1, sizeof(char));
		strncpy(inputCopy, str, inputLength);

		command->command = strtok_r (inputCopy, " ", &command->args);
		printf("command: %s\n", command->command);
		printf("args: %s\n", command->args);
	/*	token = strtok(str, "\n\t ");
		strcpy(command->command, token);
		token = strtok(NULL, "\n\t ");
		strcpy(command->args, token);*/
	}
	return 	flag;
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
