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
	char* flag = NULL;
	menu();
	init_complexs();
	flag = enter_command((char**)&command);
	while(flag != NULL)
	{
		if(strcmp(command, commands[HALT]) == 0)
		{
			printf("dorrrrr\n");
			exit(1);
		}
		printf("%s\n", command);
		flag = enter_command((char**)&command);
	}
	if(strcmp(command, commands[HALT]) != 0)
	{
		print_error(MISSING_HALT);
	}
	return 0;
}



