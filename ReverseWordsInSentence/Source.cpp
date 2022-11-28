#include<stdio.h>
#include<string.h>

void Reverse(char* pBegin, char* pEnd)
{
	if (!pBegin || !pEnd ) return;
	char temp;
	while (pBegin < pEnd) {
		temp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = temp;
		pBegin++; pEnd--;
	}
}

void ReverseWordsInSentence(char* str)
{
	if (!str) return;
	char* pBegin = str, *pEnd = str + strlen(str) - 1;
	//reverse sentence
	Reverse(pBegin, pEnd);
	while (*pBegin != '\0') {
		if (*pBegin == ' ') {
			pBegin++;
		}
		else {
			pEnd = pBegin;
			while (*pEnd != ' ' && *pEnd != '\0') {
				pEnd++;
			}
			Reverse(pBegin, pEnd - 1);
			pBegin = pEnd;
		}
	}
}

// ====================���Դ���====================
void Test(const char* testName, char* input, const char* expectedResult)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	ReverseWordsInSentence(input);

	if ((input == nullptr && expectedResult == nullptr)
		|| (input != nullptr && strcmp(input, expectedResult) == 0))
		printf("Passed.\n\n");
	else
		printf("Failed.\n\n");
}

// ���ܲ��ԣ��������ж������
void Test1()
{
	char input[] = "I am a student.";
	char expected[] = "student. a am I";

	Test("Test1", input, expected);
}

// ���ܲ��ԣ�������ֻ��һ������
void Test2()
{
	char input[] = "Wonderful";
	char expected[] = "Wonderful";

	Test("Test2", input, expected);
}

// ³���Բ���
void Test3()
{
	Test("Test3", nullptr, nullptr);
}

// �߽�ֵ���ԣ����Կ��ַ���
void Test4()
{
	Test("Test4", (char*)"", "");
}

// �߽�ֵ���ԣ��ַ�����ֻ�пո�
void Test5()
{
	char input[] = "   ";
	char expected[] = "   ";
	Test("Test5", input, expected);
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();

	return 0;
}