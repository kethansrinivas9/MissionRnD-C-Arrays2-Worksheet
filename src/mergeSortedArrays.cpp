/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/


#include <iostream>

#define MONTH_START 3
#define DAY_START 0
#define YEAR_START 6

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int compare_dates(char *first, char *second) {
	int i = YEAR_START;
	for (; first[i] != '\0'; i++) {
		if (first[i] != second[i])
			return first[i] - second[i];
	}
	for (i = MONTH_START; first[i] != '-'; i++) {
		if (first[i] != second[i])
			return first[i] - second[i];
	}
	for (i = DAY_START; first[i] != '-'; i++) {
		if (first[i] != second[i])
			return first[i] - second[i];
	}
	return 0;
}

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	struct transaction *result = NULL;
	int a = 0, b = 0, current = 0, c;
	if (A == NULL || B == NULL) {
		return NULL;
	}
	result = (struct transaction *) malloc(sizeof(struct transaction) * (ALen + BLen));
	while (a < ALen && b < BLen) {
		c = compare_dates(A[a].date, B[b].date);
		if (c < 0) {
			result[current] = A[a];
			current++;
			a++;
		}
		else if (c > 0) {
			result[current] = B[b];
			current++;
			b++;
		}
		else {
			result[current] = A[a];
			current++;
			result[current] = B[b];
			a++;
			b++;
			current++;
		}
	}
	if (a < ALen) {
		for (; a < ALen; a++, current++)
			result[current] = A[a];
	}
	if (b < BLen) {
		for (; b < BLen; b++, current++)
			result[current] = B[b];
	}
	return result;
}