/*
 * menu.c
 *
 *  Created on: Jun 16, 2015
 *      Author: dchiu
 */

#include <stdio.h>
#include "menu.h"

int getMenuOption() {
	int opt;
	printf("\n*** WORD STATS MENU ***\n");
	printf("Enter 1 to print vowel and consonant frequency.\n");
	printf("Enter 2 to print histogram.\n");
	printf("Enter 3 to return to inputting more strings.\n");
	printf("Enter 4 to quit.\n");
	//fgets(opt, 1* sizeof(int), stdin);
	// printf("*** WORD STATS MENU ***\n");
	// printf("Enter %d to print vowel and consonant frequency.\n", MENU_STATS);
	// printf("Enter %d to print histogram.\n", MENU_HISTO);
	// printf("Enter %d to return to inputting more strings.\n", MENU_INPUT);
	// printf("Enter %d to quit.\n", MENU_EXIT);
	scanf("%d", &opt);
	return opt;
}
