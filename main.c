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
	int flag = 0;
	menu();
	init_complexs();
	flag = scanf("%s",command);

	while(flag != -1 || strcmp(command, commands[HALT]) == 0)
	{
		printf("%s\n", command);
		flag = scanf("%s",command);
	}
	if(strcmp(command, commands[HALT]) != 0)
	{
		print_error(MISSING_HALT);
	}
	return 0;
}



