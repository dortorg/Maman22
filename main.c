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
/*    	printf("main   %s\n",comm.command);
    	printf("main   %s\n",comm.args);*/

		handle_command(comm);
	}
	if(strcmp(comm.command, commands[HALT]) != 0)
	{
		print_error(MISSING_HALT);
	}
	return 0;
}



