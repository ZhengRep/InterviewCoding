#include<cstdio>
#include<cstdlib>

bool g_InvalidInput = true;

int GreatestSumOfSubarray(int* array, int length)
{
	if (array == nullptr || length <= 0) {
		g_InvalidInput = true;
		return 0;
	}
	g_InvalidInput = false;

	int nGreatestValue = 0x80000000; //minumum
	int nCurSum = 0;

	for (int i = 0; i < length; i++)
	{
		//if (array[i] > 0) {
		//	//may be this value is greatest
		//	if (nCurSum < 0)
		//	{
		//		nCurSum = array[i];
		//	}
		//	else {
		//		nCurSum += array[i];
		//	}
		//}
		//else { //value is minus
		//	if (nCurSum < 0) {
		//		nCurSum = array[i]; // more less than
		//	}
		//	else {
		//		nCurSum += array[i];
		//	}
		//}

		if (nCurSum <= 0) {
			nCurSum = array[i];
		}
		else {
			nCurSum += array[i];
		}

		if (nCurSum > nGreatestValue) {
			nGreatestValue = nCurSum;
		}
	}

	return nGreatestValue;
}

// ====================���Դ���====================
void Test(const char* testName, int* pData, int nLength, int expected, bool expectedFlag)
{
	if (testName != nullptr)
		printf("%s begins: \n", testName);

	int result = GreatestSumOfSubarray(pData, nLength);
	if (result == expected && expectedFlag == g_InvalidInput)
		printf("Passed.\n");
	else
		printf("Failed.\n");
}

// 1, -2, 3, 10, -4, 7, 2, -5
void Test1()
{
	int data[] = { 1, -2, 3, 10, -4, 7, 2, -5 };
	Test("Test1", data, sizeof(data) / sizeof(int), 18, false);
}

// �������ֶ��Ǹ���
// -2, -8, -1, -5, -9
void Test2()
{
	int data[] = { -2, -8, -1, -5, -9 };
	Test("Test2", data, sizeof(data) / sizeof(int), -1, false);
}

// �������ֶ�������
// 2, 8, 1, 5, 9
void Test3()
{
	int data[] = { 2, 8, 1, 5, 9 };
	Test("Test3", data, sizeof(data) / sizeof(int), 25, false);
}

// ��Ч����
void Test4()
{
	Test("Test4", nullptr, 0, 0, true);
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();

	return 0;
}