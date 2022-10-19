#include<cstdio>

void permutation(char* pStr, char* pBegin)
{
	if (*pBegin == '\0') {
		printf("%s\n", pStr);
		return;
	}
	else {
		for (char* pCharElement = pBegin; *pCharElement != '\0'; pCharElement++)
		{
			char temp = *pCharElement;
			*pCharElement = *pStr;
			*pStr = temp;

			permutation(pStr, pBegin + 1);

			temp = *pBegin;
			*pBegin = *pStr;
			*pStr = temp;
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