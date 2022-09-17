#include<stdio.h>
#include<stdlib.h>
#include<string.h>

static int lineNum = 1;

bool Increment(char* numArray)
{
	int addIndex = strlen(numArray) - 1;
	numArray[addIndex]++;
	
	int carry = 0;
	if (numArray[addIndex] - '0' > 9) {
		carry = 1;
		numArray[addIndex] -= 10;
	}

	int carrySum = addIndex + 1;
	while (carry)
	{
		if (--carrySum == 0) return false;
		numArray[--addIndex]++;
		carry = 0;
		if (numArray[addIndex] - '0' > 9) {
			carry = 1;
			numArray[addIndex] -= 10;
		}
	}
	return true;
}

void printNumArray(char* numArray)
{
	int leftValueIndex = 0;
	while (numArray[leftValueIndex] == '0')
	{
		leftValueIndex++;
	};
	if (*(numArray + leftValueIndex) != '\0') printf("%s\t", numArray + leftValueIndex);
	else return;
	if ((++lineNum % 10) == 0) printf("\n");
}

void PrintToNMaxNum(int n)
{
	if (n <= 0) return;
	char* numArray = new char[n + 1];
	if (numArray == nullptr) return;
	memset(numArray, '0', n);
	numArray[n] = '\0';
	numArray[n - 1] = '1';

	do 
	{
		printNumArray(numArray);
	} while (Increment(numArray)); //when add to n+1 to return false

}

void fillArrayWithZeroToNine(char* arrayBuffer, int length, int index)
{
	if (index == length) {
		printNumArray(arrayBuffer);
		return;
	}
	for (int i = 0; i < 10; i++)
	{
		arrayBuffer[index] = '0' + i;
		fillArrayWithZeroToNine(arrayBuffer, length, index + 1);
	}
}

void printNumByRecursively(int n)
{
	if (n <= 0) return;
	char* numArray = new char[n + 1];
	if (numArray == nullptr) return;
	//memset(numArray, '\0', n);
	numArray[n] = '\0';
	
	fillArrayWithZeroToNine(numArray, n, 0);
	delete[] numArray;
}

void Test(int n)
{
	printf("Test for %d begins:\n", n);

	PrintToNMaxNum(n);
	//printNumByRecursively(n);

	printf("\nTest for %d ends.\n\n", n);
}

int main(int argc, char* argv[])
{
 	Test(1);
	Test(2);
	Test(3);
	Test(0);
	Test(-1);

	return 0;
}