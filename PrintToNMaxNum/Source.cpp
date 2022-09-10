#include<stdio.h>
#include<stdlib.h>
#include<string.h>

static int lineNum = 0;

bool Increment(char* numArray)
{
	int addIndex = strlen(numArray) - 1;
	numArray[addIndex]++;
	if (addIndex == 0 && numArray[0] - '0' == 10) return false;
	
	int carry = 0;
	if (numArray[addIndex] - '0' > 9) {
		carry = 1;
		numArray[addIndex] -= 10;
	}

	int carrySum = addIndex + 1;
	while (carry)
	{
		if (carrySum-- == 0) return false;
		//if (numArray[0] - '0' == 9) return false;
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
	printf("%s\t", numArray + leftValueIndex);
	if ((++lineNum % 9) == 0) printf("\n");
}

void PrintToNMaxNum(int n)
{
	if (n <= 0) return;
	char* numArray = new char[n + 1];
	if (numArray == nullptr) return;
	memset(numArray, '0', n);
	numArray[n] = '\0';

	while (Increment(numArray))
	{
		printNumArray(numArray);
	}
}

void Test(int n)
{
	printf("Test for %d begins:\n", n);

	PrintToNMaxNum(n);

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