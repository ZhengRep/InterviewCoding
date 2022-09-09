#include<stdio.h>
#include<stdlib.h>
#include<string.h>

static int topDigitIndex;

bool Increment(char* numArray)
{
	
}

void printNumArray(char* numArray)
{

}

void PrintToNMaxNum(int n)
{
	if (n <= 0) return;
	char* numArray = new char[n + 1];
	memset(numArray, '0', n);
	numArray[n] = '\0';

	while (Increment(numArray))
	{
		printNumArray(numArray);
	}
	printf("\n");
}

int main()
{

	return 0;
}