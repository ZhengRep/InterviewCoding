#include<stdio.h>

void printNumber(int num)
{
	printf("%d\t", num);
}

void printMatrixCircle(int** matrix, int rows, int cols, int start)
{
	int endX = cols - start - 1;
	int endY = rows - start - 1;

	//top row
	for (int i = start; i <= endX; i++)
	{
		printNumber(matrix[start][i]);
	}

	//right col
	if (endY > start)
	{
		for (int i = start + 1; i <= endY; i++)
		{
			printNumber(matrix[i][endX]);
		}
	}

	//bottom row
	if (endY > start && endX > start)
	{
		for (int i = endX - 1; i >= start; i--)
		{
			printNumber(matrix[endY][i]);
		}
	}

	//left col
	if (endX > start && endY > start + 1)
	{
		for (int i = endY - 1; i > start; i--)
		{
			printNumber(matrix[i][start]);
		}
	}
}

void printMatrix(int** matrix, int rows, int cols)
{
	if (matrix == nullptr || rows < 1 || cols < 1) return;

	int start = 0;

	while (start * 2 < rows && start * 2 < cols)
	{
		printMatrixCircle(matrix, rows, cols, start);
		start++;
	}
}


// ====================²âÊÔ´úÂë====================
void Test(int columns, int rows)
{
    printf("Test Begin: %d columns, %d rows.\n", columns, rows);

    if (columns < 1 || rows < 1)
        return;

    int** numbers = new int* [rows];
    for (int i = 0; i < rows; ++i)
    {
        numbers[i] = new int[columns];
        for (int j = 0; j < columns; ++j)
        {
            numbers[i][j] = i * columns + j + 1;
        }
    }

    printMatrix(numbers, rows, columns);
    printf("\n");

    for (int i = 0; i < rows; ++i)
        delete[](int*)numbers[i];

    delete[] numbers;
}

int main(int argc, char* argv[])
{
    /*
    1
    */
    Test(1, 1);

    /*
    1    2
    3    4
    */
    Test(2, 2);

    /*
    1    2    3    4
    5    6    7    8
    9    10   11   12
    13   14   15   16
    */
    Test(4, 4);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14   15
    16   17   18   19   20
    21   22   23   24   25
    */
    Test(5, 5);

    /*
    1
    2
    3
    4
    5
    */
    Test(1, 5);

    /*
    1    2
    3    4
    5    6
    7    8
    9    10
    */
    Test(2, 5);

    /*
    1    2    3
    4    5    6
    7    8    9
    10   11   12
    13   14   15
    */
    Test(3, 5);

    /*
    1    2    3    4
    5    6    7    8
    9    10   11   12
    13   14   15   16
    17   18   19   20-
+    */
    Test(4, 5);

    /*
    1    2    3    4    5
    */
    Test(5, 1);

    /*
    1    2    3    4    5
    6    7    8    9    10
    */
    Test(5, 2);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14    15
    */
    Test(5, 3);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14   15
    16   17   18   19   20
    */
    Test(5, 4);

    return 0;
}