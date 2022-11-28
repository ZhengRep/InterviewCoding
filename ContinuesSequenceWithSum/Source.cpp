#include<stdio.h>

void PrintContinuesSequence(int small, int big)
{
	while (small <= big) {
		printf("%d ", small);
		small++;
	}
	printf("\n");
}

void FindContinuesSequence(int sum)
{
	if (sum < 3) return;

	int small = 1, big = 2, middle = (sum + 1) / 2;
	int curSum = 3;
	while (small < middle) {
		if (curSum == sum) {
			PrintContinuesSequence(small, big);
		}
		while (curSum > sum && small < middle) {
			curSum -= small;
			small++;
			if (curSum == sum) {
				PrintContinuesSequence(small, big);
			}
		}
		big++;
		curSum += big;
	}
}

// ====================²âÊÔ´úÂë====================
void Test(const char* testName, int sum)
{
	if (testName != nullptr)
		printf("%s for %d begins: \n", testName, sum);

	FindContinuesSequence(sum);
}

int main(int argc, char* argv[])
{
	Test("test1", 1);
	Test("test2", 3);
	Test("test3", 4);
	Test("test4", 9);
	Test("test5", 15);
	Test("test6", 100);

	return 0;
}