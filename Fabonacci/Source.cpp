#include<stdio.h>

void FabonacciByIterator(const char* description, int valueNum)
{
	printf(description);
	if (valueNum < 0) return;
	int numOne = 0, numTwo = 1;
	int numSum = 0;
	for(int i = 0; i < valueNum; i++)
	{
		if (i == 0) printf("0 ");
		else if (i == 1) printf("1 ");
		else {
			numSum = numOne + numTwo;
			printf("%d ", numSum);
			numOne = numTwo;
			numTwo = numSum;
		}
	}
	printf("\n");
}

// 0 1 1 2 3 5 8 13
int FabonacciByRecursively(int valueNum)
{
	if (valueNum <= 0) return 0;
	if (valueNum == 1) return 1;
	
	return FabonacciByRecursively(valueNum - 1) + FabonacciByRecursively(valueNum - 2);
}

int main()
{
	//printf("%d ", FabonacciByRecursively(8));
	//FabonacciByIterator("Fabonacci value by iterator:\n", 10);
	printf("Fabonacci by recursive:\n");
	for (int i = 0; i < 11; i++)
	{
		printf("%d ", FabonacciByRecursively(i));
	}
	printf("\n");

	FabonacciByIterator("Fabonacci by iterator:\n", 11);

	return 0;
}