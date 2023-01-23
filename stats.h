/*
 * histo.h
 */

#ifndef STATS_H_
#define STATS_H_

// constants
#define ALPHABET_SIZE 26

// TODO: functions declarations go below
//int wordCount = 0;
void loadHistogram(int histogram[],  char* token, int* vowelCount, int* consonantCount);
int vowelCount();
int consonantCount();


#endif /* STATS_H_ */
