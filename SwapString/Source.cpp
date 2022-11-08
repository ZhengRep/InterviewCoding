#include<stdio.h>
#include<string.h>

void swapString(char* str, int start, int end)
{
	if (start >= end) return;
	int temp;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++; end--;
	}
}

char* parseAndReverseString(char* str)
{
	if (!str) return nullptr;
	//erase head space
	while (*str == ' ') str++;
	if (*str == '\0') return nullptr;

	//erase tail space
	int len = strlen(str);
	while (str[--len] == ' ');
	str[len + 1] = '\0';

	//swap sentence
	swapString(str, 0, strlen(str) - 1);

	//swap word
	int wordTailIndex = 0;
	while (str[wordTailIndex] != ' ' && str[wordTailIndex] != '\0') {
		wordTailIndex++;
	}
	swapString(str, 0, wordTailIndex - 1);
	if (wordTailIndex == strlen(str)) {
		return str;
	}

	int preWordTailIndex = wordTailIndex;
	while (str[wordTailIndex] != '\0') {
		while (!(str[preWordTailIndex] != ' ' && str[preWordTailIndex + 1] == ' ') && str[preWordTailIndex + 1] != '\0') {
			preWordTailIndex++;
		}
		swapString(str, wordTailIndex + 1, preWordTailIndex);
		wordTailIndex = preWordTailIndex + 1;
	}
	return str;
}

int main()
{
	char str[100] = "   I  am    Fine!   ";
	parseAndReverseString(str);
	return 0;
}