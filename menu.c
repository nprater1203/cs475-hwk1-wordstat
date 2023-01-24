/*
 * menu.c
 *
 *  Created on: Jun 16, 2015
 *      Author: dchiu
 */

/*
	Name: Nicholas Prater
	Course: CS 481 OS
	Professor: Dr. Chiu
	Date: 1/23/23
*/

#include <stdio.h>
#include "menu.h"

int getMenuOption() {
	int opt;

	//Prompt the user to enter a menu option and read it
	printf("\n*** WORD STATS MENU ***\n");
	printf("Enter 1 to print vowel and consonant frequency.\n");
	printf("Enter 2 to print histogram.\n");
	printf("Enter 3 to return to inputting more strings.\n");
	printf("Enter 4 to quit.\n");

	scanf("%d", &opt);
	return opt;
}
