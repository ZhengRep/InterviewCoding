#include<cstdio>
#include<vector>
#include<set>
#include<cstdlib>
#include<exception>

int Random(int min, int max)
{
	if (min > max) throw std::exception("Invalid parameter!\n");

	return rand() % (max - min + 1) + min;
}

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

//must input all, can copy array to avoid change array values
int Partition(int* array, int length)
{
	if (array == nullptr || length <= 0) throw std::exception("Invalid parameter!\n");

	int start = 0, end = length - 1;
	int randomIndex = Random(start, end);
	Swap(array[randomIndex], array[end]);
	int small = start - 1;
	for (int i = start; i < end; i++)
	{
		if (array[i] < array[end]) {
			small++;
			Swap(array[i], array[small]);
		}
	}
	//special: sorted array
	if (small == start - 1) {
		Swap(array[randomIndex], array[end]);
		return randomIndex;
	}
	small++;
	Swap(array[small], array[end]);

	return small;
}

//O(n)
void LeastKNumberInArray(int* array, int length, int k)
{
	if (array == nullptr || length <= 0 || k < 1 || k > length) return;

	while (Partition(array, length) != k - 1) {};
}

typedef std::multiset<int, std::greater<int>> intSet;
typedef std::multiset<int, std::greater<int>>::iterator setIterator;


void LeasKNumberWithSet(std::vector<int>& array, int k, intSet& leastNumbers)
{
	if (k < 1 || array.empty()) return;

	std::vector<int>::iterator iter = array.begin();
	for (; iter != array.end(); iter++)
	{
		if (leastNumbers.size() < k) {
			leastNumbers.insert(*iter);
		}
		else {
			setIterator iterGreater = leastNumbers.begin();
			if (*iter < *(iterGreater)) {
				leastNumbers.erase(iterGreater);
				leastNumbers.insert(*iter);
			}
		}
	}


}

void Test(const char* testName, int* array, int length, int k, int* expectValues)
{
	printf("%s\n", testName);

	LeastKNumberInArray(array, length, k);
	printf("Get least %d number:\n", k);
	for (int i = 0; i < k; i++)
	{
		printf("%d  ", array[i]);
	}
	printf("\nexpectValues:\n");
	for (int i = 0; i < k; i++)
	{
		printf("%d  ", expectValues[i]);
	}
	printf("\n");
}

void Test1()
{
	int array[] = { 2, 1, 3, 4, 2, 5 };
	int expectValues[] = { 2, 1, 3, 2 };
	int k = 4;
	Test("Normal test:", array, sizeof(array) / sizeof(int), k, expectValues);
}

void Test2()
{
	int array[] = { 2};
	int expectValues[] = { 2};
	int k = 1;
	Test("One value test:", array, sizeof(array) / sizeof(int), k, expectValues);
}

void Test3()
{
	int array[] = { 2, 2, 3, 3};
	int expectValues[] = {2, 2};
	int k = 2;
	Test("Same k value test:", array, sizeof(array) / sizeof(int), k, expectValues);
}

void Test4()
{
	int array[] = { 1, 2, 3, 4};
	int expectValues[] = {1, 2, 3};
	int k = 3;
	Test("Increase list test:", array, sizeof(array) / sizeof(int), k, expectValues);
}

void Test5()
{
	int array[] = { 1, 2, 3, 4};
	int expectValues[] = {1, 2, 3, 4};
	int k = 4;
	Test("k is equal length test:", array, sizeof(array) / sizeof(int), k, expectValues);
}



int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	return 0;
}