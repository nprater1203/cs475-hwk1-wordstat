/*
 * histo.h
 */

/*
	Name: Nicholas Prater
	Course: CS 481 OS
	Professor: Dr. Chiu
	Date: 1/23/23
*/

#ifndef STATS_H_
#define STATS_H_

// constants
#define ALPHABET_SIZE 26
#define aNum (int)'a'
#define upperANum (int)'A'

// TODO: functions declarations go below

/**
 * @brief Getting user Input
 *
 * @param char* Input from the user
 * @param char* Input with malloc memory fpor strtok
 * @param int[] Histogram
 * @param int*   Number of vowels passed by reference
 * @param int*   Number of chars passed by reference
 * 
 * @return void
 */
void gettingUserInput(char *input, char *token, int histogram[], int *vowelCount, int *totalChars);

/**
 * @brief Prints out the histogram vertically
 *
 * @param int* Histogram of letter frequences
 * 
 * @return void
 */
void printHistogram(int* histogram);


#endif /* STATS_H_ */
