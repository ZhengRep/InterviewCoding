#include<iostream>

bool FindNumIn2DArrary(int* array, int rows, int columns, int num)
{
	if (array == nullptr || columns < 0 || rows < 0) return false;

	int row = rows - 1, col = columns - 1;

	for (int i = 0; i <= row; i++) {
		while (col != -1)
		{
			if (num == *(array + i * rows + col)) {
				return true;
			}
			else if (num > *(array + i * rows + col)) {
				break;
			}
			else{
				col--;
			}
		}
		
	}
	return false;
}

void Test(const char* testName, int* array, int rows, int columns, int num, bool expect)
{
	printf("%s begin:\n", testName);
	bool result = FindNumIn2DArrary(array, rows, columns, num);
	if (result == expect) {
		printf("Test pass!\n");
	}
	else {
		printf("Test fail!\n");
	}
}

/*
	Test Code
*/

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ�����������
void Test1()
{
	int matrix[][4] = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
	Test("Test1", (int*)matrix, 4, 4, 7, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ�������������
void Test2()
{
	int matrix[][4] = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
	Test("Test2", (int*)matrix, 4, 4, 5, false);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ�������������С������
void Test3()
{
	int matrix[][4] = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
	Test("Test3", (int*)matrix, 4, 4, 1, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ�������������������
void Test4()
{
	int matrix[][4] = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
	Test("Test4", (int*)matrix, 4, 4, 15, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ�������������С�����ֻ�С
void Test5()
{
	int matrix[][4] = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
	Test("Test5", (int*)matrix, 4, 4, 0, false);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ������������������ֻ���
void Test6()
{
	int matrix[][4] = { {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15} };
	Test("Test6", (int*)matrix, 4, 4, 16, false);
}

// ³���Բ��ԣ������ָ��
void Test7()
{
	Test("Test7", nullptr, 0, 0, 16, false);
}

int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();
	return 0;
}