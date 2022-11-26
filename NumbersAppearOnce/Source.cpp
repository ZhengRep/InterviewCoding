#include<stdio.h>

int getFirstBit1Index(int num)
{
	if (num == 0) return 0;

	int indexBit = 0;
	while ((num & 0x1) == 0 && indexBit < 8 * sizeof(int)) {
		num >>= 1;
		indexBit++;
	}
	return indexBit;
}

bool isBit1AtIndex(int num, int index)
{
	return (num >> index & 0x1);
}

void FindNumbersAppearOnce(int* data, int length, int* num1, int* num2)
{
	if (!data || length < 1) return;

	int exclusiveResult = 0;
	for (int i = 0; i < length; i++) {
		exclusiveResult ^= data[i];
	}

	int indexOf1 = getFirstBit1Index(exclusiveResult);

	*num1 = *num2 = 0;
	for (int i = 0; i < length; i++) {
		if (isBit1AtIndex(data[i], indexOf1)) {
			*num1 ^= data[i];
		}
		else {
			*num2 ^= data[i];
		}
	}
}

// ====================²âÊÔ´úÂë====================
void Test(const char* testName, int data[], int length, int expected1, int expected2)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	int result1, result2;
	FindNumbersAppearOnce(data, length, &result1, &result2);

	if ((expected1 == result1 && expected2 == result2) ||
		(expected2 == result1 && expected1 == result2))
		printf("Passed.\n\n");
	else
		printf("Failed.\n\n");
}

void Test1()
{
	int data[] = { 2, 4, 3, 6, 3, 2, 5, 5 };
	Test("Test1", data, sizeof(data) / sizeof(int), 4, 6);
}

void Test2()
{
	int data[] = { 4, 6 };
	Test("Test2", data, sizeof(data) / sizeof(int), 4, 6);
}

void Test3()
{
	int data[] = { 4, 6, 1, 1, 1, 1 };
	Test("Test3", data, sizeof(data) / sizeof(int), 4, 6);
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();

	return 0;
}