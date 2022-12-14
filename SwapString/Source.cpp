#include<stdio.h>
#include<string.h>

void swapString(char* str, int start, int end)
{
	if (start >= end) return;
	char temp;
	while (start < end){
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++; end--;
	}
}

void parseAndReverseString(char* str)
{
	if (!str) return;

	int startIndex = -1;
	int wordTailIndex = 0;
	int len = strlen(str);
	while (wordTailIndex < len) {
		//index to word tail
		while (!(str[wordTailIndex] != ' ' && (str[wordTailIndex + 1] == ' ' || str[wordTailIndex + 1] == '\0'))) {
			wordTailIndex++;
		}
		swapString(str, ++startIndex, wordTailIndex);
		//startIndex to first space
		while(str[startIndex] != ' '){
			startIndex++;
		}
		wordTailIndex++;
	}
	str[startIndex] = '\0';
	swapString(str, 0, startIndex - 1);
}

int main()
{
	char str[100] = "  ";
	parseAndReverseString(str);
	return 0;
}