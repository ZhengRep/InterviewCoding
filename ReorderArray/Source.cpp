#include<stdio.h>

/*
what is array?
array is sequence of same type value

problem:
presequence is odds
postrequence is evens

*/

//void swap(int* num1, int* num2)
//{
//	int temp = *num1;
//	*num1 = *num2;
//	*num2 = temp;
//}

void swap(int& num1, int& num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

//odd value & 1 == 1 is odd
void reorderArray(int* array, int length)
{
	if (array == nullptr || length < 2) return;
	int evenIndex = 0;
	int oddIndex = length - 1;
	while (evenIndex < oddIndex)
	{
		//get pre even value
		while(array[evenIndex] % 2 != 0 && evenIndex <= length) evenIndex++;
		if (evenIndex == length) return;

		//get post odd value
		while (array[oddIndex] % 2 != 1 && oddIndex > -1) oddIndex--;
		if (oddIndex == -1) return;

		if (oddIndex + 1 != evenIndex) swap(array[oddIndex], array[evenIndex]);
	}
}
/*
void Test((char*)int* array, int length, char* description)
{
	printf("%s\n Origin:\n", description);
	for (int i = 0; i < length; i++) printf("%d \t", array[i]);

	printf("\nreorder:\n");
	reorderArray(array, length);
	for (int i = 0; i < length; i++) printf("%d \t", array[i]);
	printf("\n");
}

//all is odd
void test1()
{
	int array[5] = { 1, 1, 1, 1, 1 };
	Test((char*)array, 5, "all is odd");
}

//all is even
void test2()
{
	int array[5] = {2, 2, 2, 2, 2};
	Test((char*)array, 5, "all is even");
}

//all is even
void test3()
{
	int array[5] = { 2, 1, 2, 1, 2 };
	Test((char*)array, 5, "all is normal");
}

//all is reverse
void test4()
{
	int array[5] = { 2, 2, 2, 2, 1 };
	Test((char*)array, 5, "tail is odd");
}

//all is even
void test5()
{
	int array[5] = {1, 2, 2, 2, 2};
	Test((char*)array, 5, "head is odd");
}


//none
// 1 1 2
// 
//1
//two
*/
// ====================²âÊÔ´úÂë====================
void PrintArray(int numbers[], int length)
{
	if (length < 0)
		return;

	for (int i = 0; i < length; ++i)
		printf("%d\t", numbers[i]);

	printf("\n");
}

void Test(char* testName, int numbers[], int length)
{
	if (testName != nullptr)
		printf("%s begins:\n", testName);

	int* copy = new int[length];
	for (int i = 0; i < length; ++i)
	{
		copy[i] = numbers[i];
	}

	printf("Test for solution 1:\n");
	PrintArray(numbers, length);
	reorderArray(numbers, length);
	PrintArray(numbers, length);

	delete[] copy;
}

void Test1()
{
	int numbers[] = { 1, 2, 3, 4, 5, 6, 7 };
	Test((char*)"Test1", numbers, sizeof(numbers) / sizeof(int));
}

void Test2()
{
	int numbers[] = { 2, 4, 6, 1, 3, 5, 7 };
	Test((char*)"Test2", numbers, sizeof(numbers) / sizeof(int));
}

void Test3()
{
	int numbers[] = { 1, 3, 5, 7, 2, 4, 6 };
	Test((char*)"Test3", numbers, sizeof(numbers) / sizeof(int));
}

void Test4()
{
	int numbers[] = { 1 };
	Test((char*)"Test4", numbers, sizeof(numbers) / sizeof(int));
}

void Test5()
{
	int numbers[] = { 2 };
	Test((char*)"Test5", numbers, sizeof(numbers) / sizeof(int));
}

void Test6()
{
	Test((char*)"Test6", nullptr, 0);
}

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	return 0;
}
