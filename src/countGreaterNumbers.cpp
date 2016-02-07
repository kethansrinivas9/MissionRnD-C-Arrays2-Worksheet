/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
#include<string.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int return_number(char* array,int a,int b)
{
	int count = 0;
	for (int i = a; i <= b; i++)
	{
		count = count * 10 + array[i] - '0';
	}
	return count;
}

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int day1, day2, month1, month2, year1, year2,count=0;
	day1 = return_number(date, 0, 1);
	month1 = return_number(date,3,4);
	year1 = return_number(date, 6, 9);
	if (Arr == NULL || len <= 0 || month1 > 12 || year1<=0 || day1 > 31)
		return NULL;
	for (int i = 0; i < len; i++)
	{
		day2 = return_number(Arr[i].date, 0, 1);
		month2 = return_number(Arr[i].date, 3, 4);
		year2 = return_number(Arr[i].date, 6, 9);
		if (month2 <= 12 || year2>0 || day2 <= 31)
		{
			if (year2 > year1)
				count++;
			else if (month2 > month1&&year2 >= year1)
				count++;
			else if (day2 > day1&& month2 >= month1&&year2 >= year1)
				count++;
		}
	}
	return count;
}
