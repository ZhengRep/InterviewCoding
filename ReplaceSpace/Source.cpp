#include<iostream>

void ReplaceSpaces(char** str)
{
	if (*str == nullptr) return;

	int strLength = strlen(*str);
	//get spaces num
	int spaceNum = 0;
	for (int i = 0; i < strLength; i++) {
		if ((*str)[i] == ' ') spaceNum++;
	}

	char* tempStr = new char[strLength + spaceNum * 2 + 1];
	if (tempStr == nullptr) return;
	tempStr[strLength + spaceNum * 2] = '\0';

	int sourceIndex = 0, destIndex = 0;

	while ((*str)[sourceIndex] != '\0')
	{
		if ((*str)[sourceIndex] == ' ') {
			tempStr[destIndex++] = '%';
			tempStr[destIndex++] = '2';
			tempStr[destIndex++] = '0';
			sourceIndex++;
		}
		else {
			tempStr[destIndex++] = (*str)[sourceIndex++];
		}
	}

	delete[] *str; //???
	*str = tempStr;
}

/*
To test:
1. does strlen include '\0¡¯ - no
2. 
*/
int main()
{
	char* testStr = (char*)"we are happy";
	ReplaceSpaces(&testStr);
	return 0;
}