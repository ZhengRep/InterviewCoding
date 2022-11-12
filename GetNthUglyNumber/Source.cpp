#include<stdio.h>

bool isUglyNumber(int number)
{
	if (number < 1) return false;

	while (number % 2 == 0) {
		number /= 2;
	}
	while (number % 3 == 0) {
		number /= 3;
	}
	while (number % 5 == 0) {
		number /= 5;
	}

	return number == 1 ? true : false;
}

int min(int a, int b, int c)
{
	int min = a < b ? a : b;
	return min < c ? min : c;
}

int getNthUglyNumberByArray(int index)
{
	if (index < 1) return 0;

	int* uglyNumbers = new int[index];
	uglyNumbers[0] = 1;
	int nextUglyNumberIndex = 1;

	int* multipleTwoUglyNumber = uglyNumbers;
	int* multipleThreeUglyNumber = uglyNumbers;
	int* multipleFiveUglyNumber = uglyNumbers;

	while (nextUglyNumberIndex < index) {
		uglyNumbers[nextUglyNumberIndex] = min(*multipleTwoUglyNumber * 2, *multipleThreeUglyNumber * 3, *multipleFiveUglyNumber * 5);

		//update multiple pointer
		while (*multipleTwoUglyNumber * 2 <= uglyNumbers[nextUglyNumberIndex]) {
			multipleTwoUglyNumber++;
		}
		while (*multipleThreeUglyNumber * 3 <= uglyNumbers[nextUglyNumberIndex]) {
			multipleThreeUglyNumber++;
		}
		while (*multipleFiveUglyNumber * 5 <= uglyNumbers[nextUglyNumberIndex]) {
			multipleFiveUglyNumber++;
		}
		nextUglyNumberIndex++;
	}

	int result = uglyNumbers[nextUglyNumberIndex - 1];
	delete[] uglyNumbers;
	return result;
}

int getNthUglyNumber(int index)
{
	if (index < 1) return 0;

	int foundSum = 0;
	int number = 0;
	while (foundSum < index) {
		number++;
		if (isUglyNumber(number)) {
			foundSum++;
		}
	}
	return number;
}

/*
ugly number:
1 2 3 4 5 6 8 9 10 12 

*/

void Test(int index, int expected)
{
    if (getNthUglyNumberByArray(index) == expected)
        printf("solution1 passed\n");
    else
        printf("solution1 failed\n");
}

int main(int argc, char* argv[])
{
    Test(1, 1);

    Test(2, 2);
    Test(3, 3);
    Test(4, 4);
    Test(5, 5);
    Test(6, 6);
    Test(7, 8);
    Test(8, 9);
    Test(9, 10);
    Test(10, 12);
    Test(11, 15);

    Test(1500, 859963392);

    Test(0, 0);

    return 0;
}