#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#pragma warning(disable: 4996)

int OneSumInNum(int num)
{
	int oneNum = 0;
	while (num)
	{
		if (num % 10 == 1) oneNum++;
		num = num / 10;
	}
	return oneNum;
}

//n*log(n)
int OneAppearNumFromOneToN(int N)
{
	if (N < 1) {
		return 0;
	}

	int number = 0;
	while (N)
	{
		number += OneSumInNum(N);
		N--;
	}

	return number;
}

int PowerBase10(int n)
{
	int result = 1;
	for (int i = 0; i < n; i++)
	{
		result *= 10;
	}
	return result;
}

int NumberOf1(char* str)
{
	if (str == nullptr || *str < '0' || *str > '9') return 0;

	int firstNum = *str - '0';
	int lenght = strlen(str);

	if (firstNum == 0 && lenght == 1) return 0;
	if (firstNum > 0 && lenght == 1) return 1;

	//e.g. 21345
	int numFirstDigit = 0;
	if (firstNum == 1) {
		numFirstDigit = atoi(str + 1) + 1;
	}
	else if (firstNum > 1) {
		numFirstDigit = PowerBase10(lenght - 1);
	}

	//except first num : 01345 - 21345
	int numOtherDigit = firstNum * (lenght - 1) * PowerBase10(lenght - 2); // one of 1 other permutation
	//1 - 1345
	int numRecursive = NumberOf1(str + 1);

	return numFirstDigit + numOtherDigit + numRecursive;

}

int OneAppearNumFromOneToN_logn(int N)
{
	if (N < 1) return 0;

	char str[50];
	sprintf(str, "%d", N);

	return NumberOf1(str);
}

void Test(const char* testName, int N, int expectValue)
{
	printf("%s\n", testName);
	if (OneAppearNumFromOneToN_logn(N) == expectValue) {
		printf("Passed!\n");
	}
	else {
		printf("Failed!\n");
	}
}

void Test1()
{
	int N = 10;
	int expectValue = 2;
	Test("Normal test:", N, expectValue);
}

int main()
{
	Test1();
	Test("Test1", 1, 1);
	Test("Test2", 5, 1);
	Test("Test3", 10, 2);
	Test("Test4", 55, 16);
	Test("Test5", 99, 20);
	Test("Test6", 10000, 4001);
	Test("Test7", 21345, 18821);
	return 0;
}