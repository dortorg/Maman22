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
	printf(LINE);
	printf("Enter command: \n");
	while(enter_command(&comm) != EOF)
	{
		if(strcmp(comm.command, "\0") != 0)
		{
			handle_command(comm);
			printf(LINE);
			printf("Enter command: \n");
		}
	}
	if(strcmp(comm.command, commands[HALT]) != 0)
	{
		print_error(MISSING_HALT);
	}

	return 0;
}



