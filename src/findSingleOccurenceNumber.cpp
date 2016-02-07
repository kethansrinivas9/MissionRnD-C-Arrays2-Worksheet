/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/
#include<algorithm>
using namespace std;

int findSingleOccurenceNumber(int *A, int len) {

	if (len <= 0||A==NULL)
		return -1;
	std:sort(A + 0, A + len);
	for (int i = 0; i < len; i = i + 3)
	{
		if (A[i] == A[i + 1] && A[i + 1] == A[i + 2])
		{
		}
		else if (i == len - 1)
			return A[i];
		else
			return A[i];
	}
}