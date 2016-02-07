/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int compare_date(char *first, char *second) {
	int i = 6;
	for (; first[i] != '\0'; i++) {
		if (first[i] != second[i])
			return first[i] - second[i];
	}
	for (i = 3; first[i] != '-'; i++) {
		if (first[i] != second[i])
			return first[i] - second[i];
	}
	for (i = 0; first[i] != '-'; i++) {
		if (first[i] != second[i])
			return first[i] - second[i];
	}
	return 0;
}

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	int a = 0, b = 0, current = 0, min = 0, c;
	struct transaction *result = NULL;
	if (A == NULL || B == NULL || ALen < 0 || BLen < 0)
		return NULL;
	min = ALen > BLen ? BLen : ALen;
	result = (struct transaction *) malloc(sizeof(struct transaction) * min);
	while (a < ALen && b < BLen) {
		c = compare_date(A[a].date, B[b].date);
		if (c == 0) {
			result[current] = A[a];
			current++;
			a++;
			b++;
		}
		else if (c < 0) {
			a++;
		}
		else {
			b++;
		}
	}
	result = (struct transaction *) realloc(result, sizeof(struct transaction) * (current));
	return result;
}