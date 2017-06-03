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
	command comm;

	menu();
	init_complexs();

	while(enter_command(&comm) != EOF)
	{
		printf("command: %s\n", comm.command);
		printf("args: %s\n", comm.args);
		if(strcmp(comm.command, commands[HALT]) == 0)
		{
			printf("Bye bye!!\n");
			exit(1);
		}
	}
	if(strcmp(comm.command, commands[HALT]) != 0)
	{
		print_error(MISSING_HALT);
	}
	return 0;
}



