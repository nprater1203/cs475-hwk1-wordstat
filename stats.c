/*
 * histo.c
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

// TODO: function definitions for dealing with histogram below

void gettingUserInput(char *input, char *token, int histogram[], int *vowelCount, int *totalChars)
{
	bool acceptsInput = true;
	
	int countChars = 0;

	printf("Enter string (# to stop):\n");

	// Continue to prompt the user for strings until the string
	// starts with a #
	while (acceptsInput)
	{
		fgets(input, MAX_INPUT_LEN, stdin);

		// Split up the inputted string based in white space
		token = strtok(input, " ");
		while (token != NULL)
		{
			char *temp = token;

			// Update the histogram so that all letters gets converted to lowercase
			// and only chars in the alphabet are added
			while (*temp != '\0')
			{
				// "Converting the uppercase letters to lowercase" and updating the
				// histogram
				if (*temp >= 'A' && *temp <= 'Z')
				{
					histogram[(int)*temp - upperANum]++;
					countChars++;
				}

				// Updating the histogram
				if (*temp >= 'a' && *temp <= 'z')
				{
					histogram[(int)*temp - aNum]++;
					countChars++;
				}
				temp++;
			}
			token = strtok(NULL, " ");
		}

		if (*input == '#')
		{
			acceptsInput = false;
		}
	}

	*totalChars += countChars;
	*vowelCount = histogram[(int)'a' - aNum] + histogram[(int)'e' - aNum] +
				  histogram[(int)'i' - aNum] + histogram[(int)'o' - aNum] +
				  histogram[(int)'u' - aNum];;
}

void printHistogram(int* histogram){
    int maxNumber = 0;
	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		if (histogram[i] > maxNumber)
		{
			maxNumber = histogram[i];
		}
	}

	// Declaration and initialization of the 2D print histogram array
	char printHisto[ALPHABET_SIZE][maxNumber];
	for(int i = 0; i < ALPHABET_SIZE; i++)
	{
		for(int j = 0; j < maxNumber; j++)
		{
				printHisto[i][j] = ' ';
		}
	}

	// Fill in histogram appropriately
	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		for (int j = 0; j < histogram[i]; j++)
		{
			printHisto[i][j] = '*';
	    }
	}

	// Print the histogram vertically
	for (int i = maxNumber-1; i >= 0; i--)
	{
		for (int j = 0; j < ALPHABET_SIZE; j++)
		{
			printf("%c ", printHisto[j][i]);
		}
		printf("\n");
	}

	// Print the alphabet in lowercase letters
	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		printf("%c ", 'a' + i);
	}
	printf("\n");

	// Print the corresponding frequency of the respective letter 
	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		printf("%d ", histogram[i]);
	}
	printf("\n");
}