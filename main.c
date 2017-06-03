/*
 * Main.c
 *
 *  Created on: May 24, 2017
 *      Author: Dor
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "complex.h"
#include "utils.h"



int main()
{
	char command[30];
	menu();
	init_complexs();

	while(enter_command(command) != EOF)
	{
		if(strcmp(command, commands[HALT]) == 0)
		{
			printf("Bye bye!n");
			exit(1);
		}
		printf("%s\n", command);
	}
	if(strcmp(command, commands[HALT]) != 0)
	{
		print_error(MISSING_HALT);
	}
	return 0;
}



