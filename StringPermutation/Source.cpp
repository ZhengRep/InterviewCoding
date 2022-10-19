#include<cstdio>

void permutation(char* pStr, char* pBegin)
{
	if (*pBegin == '\0') {
		printf("%s\n", pStr);
		return;
	}
	else {
		for (char* pElement = pBegin; *pElement != '\0'; pElement++)
		{
			char temp = *pElement;
			*pElement = *pStr;
			*pStr = temp;

			permutation(pStr, pBegin + 1);

			temp = *pStr;
			*pStr = *pElement;
			*pElement = temp;
		}

	}
}

void permutation(char* pStr)
{
	if (pStr == nullptr) return;

	permutation(pStr, pStr);
}

int main()
{
	char str[4] = "abc";

	permutation(str);

	return 0;
}