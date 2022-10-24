#include<cstdio>

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

void Test(const char* testName, int N, int expectValue)
{
	printf("%s\n", testName);
	if (OneAppearNumFromOneToN(N) == expectValue) {
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