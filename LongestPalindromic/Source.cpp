#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#pragma warning(disable: 4996)

bool isPalindrome(char* str, int start, int end)
{
	if (!str) return false;

	if (start == end) return true;

	// a b a
	while (start <= end) {
		if (str[start] != str[end]) {
			return false;
		}
		start++; end--;
	}
	return true;
}

char* getLogestPalindrome(char* str)
{
	if (!str) return nullptr;

	int len = strlen(str);
	int max = -1;
	int flagStart = 0, flagEnd = len - 1;
	int i, j;
	for (i = 0; i < len; i++)
	{
		for (j = 0; j < len; j++)
		{
			if (isPalindrome(str, i, j)) {
				if (j - i > max) {
					flagStart = i;
					flagEnd = j;
					max = j - i;
				}
			}
		}
	}
	str[flagEnd + 1] = '\0';
	return str + flagStart;
}

int main()
{
	char str[100] = "abcdcb";

	printf("%s\n", getLogestPalindrome(str));

	return 0;
}