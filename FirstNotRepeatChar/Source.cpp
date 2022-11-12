#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
int: 0x7fffffff ->	2,147,483,647
					4,294,967,295
long:   9,223,372,036,854,775,807 1 million million 
*/

char firstNotRepeatChar(const char* str)
{
	if (!str) return '\0';

	int* hashTable = new int[256];
	memset(hashTable, 0, 256 * sizeof(int));

	char* pHashKey = (char*)str;
	while (*pHashKey != '\0') {
		hashTable[*pHashKey]++;
		pHashKey++;
	}
	
	pHashKey = (char*)str;
	while (hashTable[*pHashKey] != 1 && hashTable[*pHashKey] != '\0') {
		pHashKey++;
	}



	return *pHashKey;
}

// ====================测试代码====================
void Test(const char* pString, char expected)
{
	if (firstNotRepeatChar(pString) == expected)
		printf("Test passed.\n");
	else
		printf("Test failed.\n");
}

int main(int argc, char* argv[])
{
	// 常规输入测试，存在只出现一次的字符
	Test("google", 'l');

	// 常规输入测试，不存在只出现一次的字符
	Test("aabccdbd", '\0');

	// 常规输入测试，所有字符都只出现一次
	Test("abcdefg", 'a');

	// 鲁棒性测试，输入nullptr
	Test(nullptr, '\0');

	return 0;
}