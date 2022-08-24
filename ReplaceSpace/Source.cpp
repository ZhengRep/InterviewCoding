#include<iostream>

#pragma warning(disable: 4996)
#pragma warning(disable: 6386)

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
            strcpy(tempStr + destIndex, "%20");
            destIndex += 3;
			sourceIndex++;
		}
		else {
			tempStr[destIndex++] = (*str)[sourceIndex++];
		}
	}

	//delete[] *str;
	*str = tempStr;
}

/*
To test:
1. does strlen include '\0�� - no
2. 
*/
/*
Test:
*/
void Test(const char* testName, char str[], const char expected[])
{
    if (testName != nullptr)
        printf("%s begins: ", testName);

    ReplaceSpaces(&str);

    if (expected == nullptr && str == nullptr)
        printf("passed.\n");
    else if (expected == nullptr && str != nullptr)
        printf("failed.\n");
    else if (strcmp(str, expected) == 0)
        printf("passed.\n");
    else
        printf("failed.\n");
}

// �ո��ھ����м�
void Test1()
{
    const int length = 100;

    char str[length] = "hello world";
    Test("Test1", str, "hello%20world");
}

// �ո��ھ��ӿ�ͷ
void Test2()
{
    const int length = 100;

    char str[length] = " helloworld";
    Test("Test2", str, "%20helloworld");
}

// �ո��ھ���ĩβ
void Test3()
{
    const int length = 100;

    char str[length] = "helloworld ";
    Test("Test3", str, "helloworld%20");
}

// �����������ո�
void Test4()
{
    const int length = 100;

    char str[length] = "hello  world";
    Test("Test4", str, "hello%20%20world");
}

// ����nullptr
void Test5()
{
    Test("Test5", nullptr, nullptr);
}

// ��������Ϊ�յ��ַ���
void Test6()
{
    const int length = 100;

    char str[length] = "";
    Test("Test6", str, "");
}

//��������Ϊһ���ո���ַ���
void Test7()
{
    const int length = 100;

    char str[length] = " ";
    Test("Test7", str, "%20");
}

// ������ַ���û�пո�
void Test8()
{
    const int length = 100;

    char str[length] = "helloworld";
    Test("Test8", str, "helloworld");
}

// ������ַ���ȫ�ǿո�
void Test9()
{
    const int length = 100;

    char str[length] = "   ";
    Test("Test9", str, "%20%20%20");
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();

    return 0;
}
