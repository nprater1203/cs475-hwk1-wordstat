/*
 * main.c
 *
 *  Created on: Jun 15, 2015
 *      Author: dchiu
 */

/*
	Name: Nicholas Prater
	Course: CS 481 OS
	Professor: Dr. Chiu
	Date: 1/23/23
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "defs.h"
#include "stats.h"
#include "menu.h"


/**
 * @brief Main function
 *
 * @param argc Ignore
 * @param argv Ignore
 * @return int
 */
int main(int argc, char *argv[])
{
	// declare and initialize the histogram
	int histogram[ALPHABET_SIZE];
	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		histogram[i] = 0;
	}

	int vowelCount = 0;
	int totalChars = 0;

	char *input = malloc(MAX_INPUT_LEN * sizeof(char));
	char *token = malloc(MAX_INPUT_LEN * sizeof(char));

	// Prompt the user to input strings
	gettingUserInput(input, token, histogram, &vowelCount, &totalChars);

	bool notQuit = true;
	int numOption;

	// Prompt the user for menu options and complete them according to what the 
	// user inputs
	while (notQuit)
	{
		numOption = getMenuOption();

		// Vowel and consonants frequencies
		if (numOption == 1)
		{
			int consonantCount = totalChars - vowelCount;
			printf("\nVowels = %d (%.2f%%), Consonants = %d (%.2f%%), Total= %d\n",
				   vowelCount, 100.00 * ((float)(vowelCount) / (totalChars)), consonantCount,
				   100.00 * ((float)(consonantCount) / (totalChars)), totalChars);
		}

		// Printing the histogram
		else if (numOption == 2)
		{
			printHistogram(histogram);
		}

		// Prompting the user for more string inputs
		else if (numOption == 3)
		{
			gettingUserInput(input, token, histogram, &vowelCount, &totalChars);
		}
		else if (numOption == 4)
		{
			notQuit = false;
		}

		// Error handling for improper user menu input
		else
		{
			printf("Error: Unknown option %d\n", numOption);
		}
	}

	printf("Exiting...\n");
	free(input);
	free(token);
	return 0;
}