/*
 * main.c
 *
 *  Created on: Jun 15, 2015
 *      Author: dchiu
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "defs.h"
#include "stats.h"
#include "menu.h"

void gettingUserInput(char *input, char *token, int histogram[], int *vowelCount, int *totalChars);

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

	gettingUserInput(input, token, histogram, &vowelCount, &totalChars);

	// printf("Total Chars: %d\nTotal Vowels: %d:\nTotal Const: %d\n", totalChars,vowelCount,totalChars-vowelCount);

	// for(int i = 0; i < ALPHABET_SIZE; i++){
	// 	printf("Histogram index %c: %d\n",(char)i+97,histogram[i]);
	// }

	bool notQuit = true;
	int numOption;
	while (notQuit)
	{
		numOption = getMenuOption();
		if (numOption == 1)
		{
			// printf("This is one\n");
			int consonantCount = totalChars - vowelCount;
			printf("\nVowels = %d (%.2f%%), Consonants = %d (%.2f%%), Total= %d\n",
				   vowelCount, 100.00 * ((float)(vowelCount) / (totalChars)), consonantCount,
				   100.00 * ((float)(consonantCount) / (totalChars)), totalChars);
		}
		else if (numOption == 2)
		{
			int maxNumber = 0;
			for(int i = 0; i < ALPHABET_SIZE; i++){
				if(histogram[i] > maxNumber){
					maxNumber = histogram[i];
				}
			}
			char printHisto[ALPHABET_SIZE][maxNumber];
			for(int i = 0; i < maxNumber; i++){ 
				for(int j = 0; j < ALPHABET_SIZE; j++){
					if(histogram[j] == maxNumber){
						printHisto[i][j] = '*';
					}
					else{
						printHisto[i][j] = '0';
					}
				}
			}

			for(int i = ALPHABET_SIZE-1; i >= 0; i--){
				for(int j = maxNumber-1; j >= 0; j--){
					if(printHisto[i][j] == '*'){
						printf("*");
					}
				}
				printf("\n");
			}
			for(int i = 0 ; i < ALPHABET_SIZE; i++){
				printf("%c ", 'a' + i);
			}
			printf("\n");
			for(int i = 0 ; i < ALPHABET_SIZE; i++){
				printf("%d ", histogram[i]);
			}
			printf("\n\n");
		}
		else if (numOption == 3)
		{
			gettingUserInput(input, token, histogram, &vowelCount, &totalChars);
		}
		else if (numOption == 4)
		{
			notQuit = false;
		}
		else
		{
			printf("Error: Unknown option %d\n", numOption);
		}
	}

	// TODO: start by getting strings from users until # is input
	// TODO: after # is input, print menu options

	printf("Exiting...\n");

	free(input);
	free(token);
	return 0;
}

void gettingUserInput(char *input, char *token, int histogram[], int *vowelCount, int *totalChars)
{
	bool acceptsInput = true;
	int aNum = (int)'a';
	int upperANum = (int)'A';
	int countChars = 0;
	int vCount;

	printf("Enter string (# to stop):\n");
	while (acceptsInput)
	{
		fgets(input, MAX_INPUT_LEN, stdin);
		token = strtok(input, " ");
		while (token != NULL)
		{
			char *temp = token;
			while (*temp != '\0')
			{
				// printf("%c\n", *temp);
				// printf("Letter: %c Index: %d\n", *temp, (int)*temp - (int)'a');
				if (*temp >= 'A' && *temp <= 'Z'){
					histogram[(int)*temp - upperANum]++;
					countChars++;
				}
				if (*temp >= 'a' && *temp <= 'z')
				{
					histogram[(int)*temp - aNum]++;
					countChars++;
				}
				temp++;
			}
			token = strtok(NULL, " ");
		}
		vCount = histogram[(int)'a' - aNum] + histogram[(int)'e' - aNum] +
					  histogram[(int)'i' - aNum] + histogram[(int)'o' - aNum] +
					  histogram[(int)'u' - aNum];
		if (*input == '#')
		{
			acceptsInput = false;
		}
	}
	*totalChars += countChars;
	*vowelCount = vCount;
}
