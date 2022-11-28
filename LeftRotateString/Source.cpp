#include<stdio.h>
#include<string.h>

void Reverse(char* pBegin, char* pEnd)
{
	if (!pBegin || !pEnd) return;
	char temp;
	while (pBegin < pEnd) {
		temp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = temp;
		pBegin++; pEnd--;
	}
}

char* LeftRotateString(char* str, int k)
{
	if (!str) return nullptr;
	if (k >= 0 && k < strlen(str)) {
		char* pFirstBegin = str, * pFirstEnd = str + k - 1;
		char* pSecondBegin = str + k, * pSecondEnd = str + strlen(str) - 1;
		//reverse part
		Reverse(pFirstBegin, pFirstEnd); Reverse(pSecondBegin, pSecondEnd);
		Reverse(pFirstBegin, pSecondEnd);
	}
    return str;
}

// ====================²âÊÔ´úÂë====================
void Test(const char* testName, char* input, int num, const char* expectedResult)
{
    if (testName != nullptr)
        printf("%s begins: ", testName);

    char* result = LeftRotateString(input, num);

    if ((input == nullptr && expectedResult == nullptr)
        || (input != nullptr && strcmp(result, expectedResult) == 0))
        printf("Passed.\n\n");
    else
        printf("Failed.\n\n");
}

// ¹¦ÄÜ²âÊÔ
void Test1()
{
    char input[] = "abcdefg";
    char expected[] = "cdefgab";

    Test("Test1", input, 2, expected);
}

// ±ß½çÖµ²âÊÔ
void Test2()
{
    char input[] = "abcdefg";
    char expected[] = "bcdefga";

    Test("Test2", input, 1, expected);
}

// ±ß½çÖµ²âÊÔ
void Test3()
{
    char input[] = "abcdefg";
    char expected[] = "gabcdef";

    Test("Test3", input, 6, expected);
}

// Â³°ôÐÔ²âÊÔ
void Test4()
{
    Test("Test4", nullptr, 6, nullptr);
}

// Â³°ôÐÔ²âÊÔ
void Test5()
{
    char input[] = "abcdefg";
    char expected[] = "abcdefg";

    Test("Test5", input, 0, expected);
}

// Â³°ôÐÔ²âÊÔ
void Test6()
{
    char input[] = "abcdefg";
    char expected[] = "abcdefg";

    Test("Test6", input, 7, expected);
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