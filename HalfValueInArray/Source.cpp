#include<stdlib.h>
#include<stdio.h>
#include<exception>

int GetRandom(int min, int max)
{
	return (rand() % (max - min + 1)) + min;
}

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int Partition(int* array, int length, int start, int end)
{
	if (array == nullptr || length <= 0 || start < 0 || end >= length || start > end) {
		throw std::exception("Invalid Parameters!");
	}

	int flagIndex = GetRandom(start, end);
	Swap(&array[flagIndex], &array[end]);

	int small = start - 1;
	for (int index = start; index < end; index++)
	{
		if (array[index] < array[end]) {
			small++;
			Swap(&array[small], &array[index]);
		}
	}

	small++;
	Swap(&array[small], &array[end]);

	return small;
}

//the tow part is sorted basically
void Merge(int* array, int length, int startLeft, int endLeft, int startRight, int endRight)
{
	if (array == nullptr || length <= 0 || startLeft < 0 || endRight >= startRight || endRight >= length) return;

	while (startLeft == endLeft || startRight == endRight)
	{
		if (array[startLeft] > array[startRight]) {
			Swap(&array[startRight], &array[startLeft]);
			startRight++;
		}
		startLeft++;
	}
}

void MergeSort(int* array, int length, int start, int end)
{
	if (array == nullptr || length <= 0 || start > end) return;

	if (start == end) return;

	int middle = Partition(array, length, start, end);
	MergeSort(array, length, start, middle);
	MergeSort(array, length, middle + 1, end);
	Merge(array, length, start, middle, middle + 1, end);
}

bool g_bArrayValid = false;

bool CheckArrayValid(int* array, int length)
{
	if (array == nullptr || length < 0) {
		g_bArrayValid = false;
		return false;
	}
	g_bArrayValid = true;
	return true;
}

bool CheckIsMoreHalfValue(int* array, int length, int value)
{
	if (array == nullptr || length <= 0) return false;

	int times = 0;
	for (int i = 0; i < length; i++)
	{
		if (array[i] == value) times++;
	}

	if (times >= length / 2) return true;
	return false;
}

bool HalfValueInArray(int* array, int length, int* halfValue)
{
	if (CheckArrayValid(array, length)) {
		int divideIndex = Partition(array, length, 0, length - 1);
		while (1)
		{
			if(divideIndex == length / 2) break;
			else if(divideIndex < length / 2)
			{
				divideIndex = Partition(array, length, divideIndex + 1, length - 1);
			}
			else {
				divideIndex = Partition(array, length, 0, divideIndex - 1);
			}
		}

		if (CheckIsMoreHalfValue(array, length, array[divideIndex])) {
			*halfValue = array[divideIndex];
			return true;
		}
	}
	return false;
}

/*
Test
*/

void Test(const char* testDescriptor, int* array, int length, int expectValue, bool isHave)
{
	printf("%s\n", testDescriptor);
	int halfValue;
	if (HalfValueInArray(array, length, &halfValue) == isHave) {
		if (halfValue == expectValue) {
			printf("Passed!  %d\n", halfValue);
		}
		else {
			printf("Passed! not value!\n");
		}
	}
	else {
		printf("Faild!\n");
	}
}

void Test1()
{
	int array[] = { 1, 2, 2, 2, 4 };
	Test("Normal test:", array, sizeof(array) / sizeof(int), 2, true);
}

void Test2()
{
	int array[] = { 1, 2, 4 };
	Test("have not half value:", array, sizeof(array) / sizeof(int), 2, false);
}

void Test3()
{
	int array[] = { 2, 2, 4, 4};
	Test("have one of 2 / 4 half value:", array, sizeof(array) / sizeof(int), 2, true);
}

int main()
{

	Test1();
	Test2();
	Test3();
	return 0;
}