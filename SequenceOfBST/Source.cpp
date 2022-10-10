#include<cstdio>

bool sequenceIsPostOrderOfBST(int* sequence, int startIndex, int endIndex)
{
	if (!sequence || startIndex > endIndex || startIndex < 0 || endIndex < 0) return false;

	if (startIndex == endIndex) return true;

	//get root node
	int rightChildTreeStartIndex = startIndex;
	while (rightChildTreeStartIndex < endIndex && sequence[rightChildTreeStartIndex] < sequence[endIndex])
	{
		rightChildTreeStartIndex++; //if this value is changed then have left child tree
	}
	//right child tree is correct?
	for (int i = rightChildTreeStartIndex; i < endIndex; i++)
	{
		if (sequence[i] <= sequence[endIndex]) return false;
	}			
	
	bool result = true;
	if (rightChildTreeStartIndex != startIndex) result = result && sequenceIsPostOrderOfBST(sequence, startIndex, rightChildTreeStartIndex - 1);
	if(result && rightChildTreeStartIndex < endIndex) result = result && sequenceIsPostOrderOfBST(sequence + rightChildTreeStartIndex, rightChildTreeStartIndex, endIndex - 1);

	return result;
	//get left child tree root node and right as well
}

void Test(const char* testDescription, int* sequence, int length, bool expect)
{
	printf("%s:\t", testDescription);
	if (sequenceIsPostOrderOfBST(sequence, 0, length - 1) == expect) printf("Passed!\n");
	else printf("Faild!\n");
}

void Test1()
{
	int sequence[7] = { 5, 7, 6, 9, 11, 10, 8};
	Test("Test nomal", sequence, 7, true);
}

void Test2()
{
	int sequence[4] = {7, 4, 6, 5};
	Test("Test nomal", sequence, 4, false);
}

void Test3()
{
	int sequence[1] = { 1 };
	Test("Test one value", sequence, 1, true);
}

void Test4()
{
	int sequence[2] = {2, 1};
	Test("Test right two value", sequence, 2, true);
}

void Test5()
{
	int sequence[2] = {1, 2};
	Test("Test right two value", sequence, 2, true);
}

void Test6()
{
	int sequence[2] = { 1, 1};
	Test("Test same value", sequence, 2, false);
}

//only right tree
void Test7()
{
	int sequence[] = { 1, 2, 3, 4, 5 };
	Test("Test only right tree", sequence, sizeof(sequence) / sizeof(int), true);
}

//only left tree
void Test8()
{
	int sequence[] = { 5, 4, 3, 2, 1 };
	Test("Test only left tree", sequence, sizeof(sequence) / sizeof(int), true);
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
	Test8();
	return 0;
}