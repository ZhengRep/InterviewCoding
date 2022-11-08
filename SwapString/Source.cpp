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

	//swap word and deal space
	//first word is diff
	int tailIndex = 0, nextSwapStringIndex = 0;
	//index to space
	while (str[nextSwapStringIndex] != ' ')
	{
		nextSwapStringIndex++;
	};
	swapString(str, tailIndex, nextSwapStringIndex - 1);
	tailIndex = nextSwapStringIndex + 1;
	nextSwapStringIndex++;
	
	//deal middle word
	while (str[nextSwapStringIndex] != '\0' && nextSwapStringIndex < strlen(str))
	{
		//index to word last num
		while (!(str[nextSwapStringIndex] != ' ' && (str[nextSwapStringIndex + 1] == ' ' || str[nextSwapStringIndex] == '\0')))
		{
			nextSwapStringIndex++;
		};
		swapString(str, tailIndex, nextSwapStringIndex);

	}
	
}

int main()
{
	char str[100] = "   I  am    Fine!   ";
	parseAndReverseString(str);
	return 0;
}