#include<stdio.h>

int NumberOfOneInBinary(int value)
{
	int sum = 0;
	if (value == 0) return 0;
	if (value < 0) {
		sum++;
		value <<= 1;
		value >>= 1;
	}
	return 0;

}

int main()
{
	NumberOfOneInBinary(-3);
	return 0;
}