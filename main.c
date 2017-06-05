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
	int flag;
    command comm;

	menu();
	init_complexes();
	printf(LINE);
	printf("Enter command: \n");
	while((flag = enter_command(&comm)) != EOF)
	{
		if(strcmp(comm.command, "\0") != 0)
		{
			handle_command(comm);
			printf(LINE);
			printf("Enter command: \n");
		}
	}
	if(flag == EOF)
	{
		print_error(MISSING_HALT);
	}
	return 0;
}



