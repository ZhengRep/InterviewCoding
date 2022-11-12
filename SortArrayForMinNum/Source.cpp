#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#pragma warning(disable: 4996)

/*
qsort 
*/
const int g_MaxNumberLength = 10;

char* g_StrCombine1 = new char[g_MaxNumberLength * 2 + 1];
char* g_StrCombine2 = new char[g_MaxNumberLength * 2 + 1];

int compare(const void* strNumber1, const void* strNumber2) //to define sort rule
{
	strcpy(g_StrCombine1, *(const char**)strNumber1); // the address of string
	strcat(g_StrCombine1, *(const char**)strNumber2);
	
	strcpy(g_StrCombine2, *(const char**)strNumber2);
	strcat(g_StrCombine2, *(const char**)strNumber1);

	return strcmp(g_StrCombine1, g_StrCombine2);
}

void PrintMinNumber(int* numbers, int length)
{
	if (numbers == nullptr || length <= 0) return;

	char** strNumbers = (char**)(new int[length]);
	for (int i = 0; i < length; i++) {
		strNumbers[i] = new char[g_MaxNumberLength + 1];
		sprintf(strNumbers[i], "%d", numbers[i]);
	}

    //if ab > ba then swap two value
	qsort(strNumbers, length, sizeof(char*), compare); //default is increase, qsort is implement by QuickSort

    for (int i = 0; i < length; i++) {
	    printf("%s", strNumbers[i]);
    }
    printf("\r\n");

	for (int i = 0; i < length; i++) {
		delete [] strNumbers[i];
	}
	delete [] strNumbers;
}

// ====================测试代码====================
void Test(const char* testName, int* numbers, int length, const char* expectedResult)
{
    if (testName != nullptr)
        printf("%s begins:\n", testName);

    if (expectedResult != nullptr)
        printf("Expected result is: \t%s\n", expectedResult);

    printf("Actual result is: \t");
    PrintMinNumber(numbers, length);

    printf("\n");
}

void Test1()
{
    int numbers[] = { 3, 5, 1, 4, 2 };
    Test("Test1", numbers, sizeof(numbers) / sizeof(int), "12345");
}

void Test2()
{
    int numbers[] = { 3, 32, 321 };
    Test("Test2", numbers, sizeof(numbers) / sizeof(int), "321323");
}

void Test3()
{
    int numbers[] = { 3, 323, 32123 };
    Test("Test3", numbers, sizeof(numbers) / sizeof(int), "321233233");
}

void Test4()
{
    int numbers[] = { 1, 11, 111 };
    Test("Test4", numbers, sizeof(numbers) / sizeof(int), "111111");
}

// 数组中只有一个数字
void Test5()
{
    int numbers[] = { 321 };
    Test("Test5", numbers, sizeof(numbers) / sizeof(int), "321");
}

void Test6()
{
    Test("Test6", nullptr, 0, "Don't print anything.");
}


int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}