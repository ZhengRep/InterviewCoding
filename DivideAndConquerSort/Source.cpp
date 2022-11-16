#include<stdio.h>

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void DivideAndConquerSortCore(int* data, int start, int end)
{
	if (!data || start > end) return;

	if (start == end) return;

	int length = (end - start) / 2;
	DivideAndConquerSortCore(data, start, start + length);
	DivideAndConquerSortCore(data, start + length + 1, end);

	int i = start, j = start + length + 1;
	while (j <= end) {
		if (data[i] > data[j]) {
			swap(data[i], data[j]);
		}
		i++;
		if (i == j) {
			j++;
		}
	}
}

void DivideAndConquerSort(int* data, int length)
{
	if (!data || length < 1) return;

	DivideAndConquerSortCore(data, 0, length - 1);
}

int main()
{
	int data[5] = { 5, 2, 3, 4, 1 };
	DivideAndConquerSort(data, 5);
	return 0;
}