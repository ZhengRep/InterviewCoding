#include<stdio.h>

int FindMinnumInRolatedArray(int* pRolatedArray, int low, int high)
{
	if (pRolatedArray == nullptr || low < 0 || high < 0 || low > high) return _CRT_INT_MAX;
	
	if (low == high) return pRolatedArray[low];
	int middle = (low + high) / 2;

	if (pRolatedArray[middle + 1] <= pRolatedArray[middle]) {
		return pRolatedArray[middle + 1];
	}

	int leftMinnum = _CRT_INT_MAX;
	int rightMinnum = _CRT_INT_MAX;
	rightMinnum = FindMinnumInRolatedArray(pRolatedArray, middle + 1, high);
	leftMinnum = FindMinnumInRolatedArray(pRolatedArray, low, middle - 1);
	
	return leftMinnum < rightMinnum ? leftMinnum : rightMinnum;
}

void Test(const char* testDescription, int* pRolatedArray, int length, int expectMinnum)
{
	printf(testDescription);
	int minnum = FindMinnumInRolatedArray(pRolatedArray, 0, length - 1);
	if (expectMinnum == minnum) {
		printf("test passed!\n");
	}
	else {
		printf("test failed!\n");
	}
}

int main()
{
	/*
	Function test:
	Boundary test:
	1. one num
	2. have same num
	Special test:
	1. none
	*/
	int rolatedArray[] = { 3, 4, 5, 1, 2 };
	Test("Original test:\n", rolatedArray, 5, 1);

	int rolatedArray1[] = { 3 };
	Test("one num test:\n", rolatedArray1, 1, 3);

	int rolatedArray2[] = { 3, 3, 4, 1, 1, 2 };
	Test("have same num test:\n", rolatedArray2, 5, 1);
	
	int rolatedArray3[] = { 3, 3, 3, 3};
	Test("have multiple same num test:\n", rolatedArray3, 4, 3);
	
	int rolatedArray4[] = { 1, 2, 3, 4};
	Test("increase sequence test:\n", rolatedArray4, 4, 1);

	return 0;
}