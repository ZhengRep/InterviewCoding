#include<stdio.h>

void printMatrixCircle(int* matrix, int rows, int cols)
{
	if (matrix == nullptr || rows < 1 || cols < 1) return;

	//print top row
	if (rows > 0)
	{
		int i = 0;
		do {
			printf("%d\t", *(matrix + i));
			i++;
		} while (i < cols - 1);
	}

	//print right col
	//the first element in the right col
	//have right col
	if (cols > 1) {
		int i = cols - 1;
		do {
			printf("%d\t", *(matrix + i));
			i += cols;
		} while (i < cols * (rows - 1));
	}

	//print bottom row
	//have bottom row
	if (cols > 1 && rows > 1)
	{
		int i = rows * cols - 1;
		do {
			printf("%d\t", *(matrix + i));
			i --;
		} while (i > cols * (rows - 1));
	}

	//print left col
	//have left col
	if (rows > 1) {
		//deal one col specialy
		if (cols == 1) {
			int i = cols;
			do {
				printf("%d\t", *(matrix + i));
				i += cols;
			} while (i < cols * rows);
		}
		else {
			int i = cols * (rows - 1);
			do {
				printf("%d\t", *(matrix + i));
				i -= cols;
			} while (i > 0);
		}
	}
}

void printMatrix(int* matrix, int rows, int cols)
{
	if (matrix == nullptr || rows < 1 || cols < 1) return;

	printMatrixCircle(matrix, rows, cols);

	printMatrix(matrix + cols + 1, rows - 2, cols - 2);
}

void test(const char* description, int* matrix, int rows, int cols, int expect[], int length)
{
	printf(description);
	printMatrix(matrix, rows, cols);
	printf("\nexpect array:\n");
	for (int i = 0; i < length; i++)
	{
		printf("%d\t", expect[i]);
	}
	printf("\n");
}

void test1()
{
	int matrix[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	int expect[9] = { 1, 2, 3, 6, 9, 8, 7, 4, 5};
	test("one element:\n", (int*)matrix, 3, 3, expect, sizeof(expect) / sizeof(int));
}

/*
1
2
*/
void test2()
{
	int matrix[2][1] = { {1}, {2} };
	int expect[2] = { 1, 2};
	test("one col:\n", (int*)matrix, 2, 1, expect, sizeof(expect) / sizeof(int));
}

/*
1 2 3
4 5 6
*/
void test3()
{
	int matrix[2][3] = { {1, 2, 3}, {4, 5, 6} };
	int expect[6] = { 1, 2, 3, 6, 5, 4 };
	test("two row:\n", (int*)matrix, 2, 3, expect, sizeof(expect) / sizeof(int));
}

/*
1 2 3
4 5 6
7 8 9
10 11 12
*/
void test4()
{
	int matrix[4][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12} };
	int expect[12] = { 1, 2, 3, 6, 9, 12, 11, 10, 7, 4, 5, 8 };
	test("4 * 3 :\n", (int*)matrix, 4, 3, expect, sizeof(expect) / sizeof(int));
}

int main()
{
	test1();
	test2();
	test3();
	test4();
	return 0;
}