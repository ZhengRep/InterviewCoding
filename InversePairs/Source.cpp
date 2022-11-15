#include<stdio.h>

int InversePairsCore(int* data, int* copy, int start, int end)
{
	if(!data || !copy || start > end) return 0;

	if (start == end) return 0;

	int length = (end - start) / 2;
	int leftInversePairs = InversePairsCore(data, copy, start, start + length);
	int rightInversePairs = InversePairsCore(data, copy, start + length + 1, end);

	//left sub array end index
	int i = start + length;
	//right sub array end index
	int j = end;
	int copyIndex = end;
	int count = 0;
	while (i >= start && j >= start + length + 1) {
		if (data[i] > data[j]) {
			//count++;
			//count += j - (start + length);
			copy[copyIndex--] = data[i--];
		}
		else {
			copy[copyIndex--] = data[j--];
		}
	}

	while (i >= start) {
		copy[copyIndex--] = data[i--];
	}
	while (j >= start + length + 1) {
		copy[copyIndex--] = data[j--];
	}
	return leftInversePairs + rightInversePairs + count;
}

int InversePairs(int* data, int length)
{
	if (!data || length < 2) return 0;

	int* copy = new int[length];
	/*for (int i = 0; i < length; i++) {
		copy[i] = data[i];
	}*/

	int ret = InversePairsCore(data, copy, 0, length - 1);
	delete[] copy;
	return ret;
}

// ====================测试代码====================
void Test(const char* testName, int* data, int length, int expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	if (InversePairs(data, length) == expected)
		printf("Passed.\n");
	else
		printf("Failed.\n");
}

void Test1()
{
	int data[] = { 1, 2, 3, 4, 7, 6, 5 };
	int expected = 3;

	Test("Test1", data, sizeof(data) / sizeof(int), expected);
}

// 递减排序数组
void Test2()
{
	int data[] = { 6, 5, 4, 3, 2, 1 };
	int expected = 15;

	Test("Test2", data, sizeof(data) / sizeof(int), expected);
}

// 递增排序数组
void Test3()
{
	int data[] = { 1, 2, 3, 4, 5, 6 };
	int expected = 0;

	Test("Test3", data, sizeof(data) / sizeof(int), expected);
}

// 数组中只有一个数字
void Test4()
{
	int data[] = { 1 };
	int expected = 0;

	Test("Test4", data, sizeof(data) / sizeof(int), expected);
}


// 数组中只有两个数字，递增排序
void Test5()
{
	int data[] = { 1, 2 };
	int expected = 0;

	Test("Test5", data, sizeof(data) / sizeof(int), expected);
}

// 数组中只有两个数字，递减排序
void Test6()
{
	int data[] = { 2, 1 };
	int expected = 1;

	Test("Test6", data, sizeof(data) / sizeof(int), expected);
}

// 数组中有相等的数字
void Test7()
{
	int data[] = { 1, 2, 1, 2, 1 };
	int expected = 3;

	Test("Test7", data, sizeof(data) / sizeof(int), expected);
}

void Test8()
{
	int expected = 0;

	Test("Test8", nullptr, 0, expected);
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();
	Test8();

	return 0;
}