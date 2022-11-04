#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#pragma warning(disable: 4996)

void GetGreaterAndLeastValueByPermutation(char* valueStr, char* nextBegin, int& greaterAndLeastValue, int value) 
{
	if (*nextBegin == '\0') {
		if (atoi(valueStr) > value && atoi(valueStr) < greaterAndLeastValue) {
			greaterAndLeastValue = atoi(valueStr);
		}
	}
	else {
		for (char* pElement = nextBegin; *pElement != '\0'; pElement++)
		{
			char temp = *pElement;
			*pElement = *valueStr;
			*valueStr = temp;

			GetGreaterAndLeastValueByPermutation(valueStr, nextBegin + 1, greaterAndLeastValue, value);

			*valueStr = *pElement;
			*pElement = temp;
		}
	}
}

int main()
{
	int value = 123;
	int greaterAndLeastValue = 0x7fffffff;

	char valueStr[7];
	sprintf(valueStr, "%d", value);
	GetGreaterAndLeastValueByPermutation(valueStr, valueStr, greaterAndLeastValue, value);
	greaterAndLeastValue = greaterAndLeastValue == 0x7fffffff ? value : greaterAndLeastValue;

	printf("Greater And Least Value is: %d", greaterAndLeastValue);

	return 0;
}