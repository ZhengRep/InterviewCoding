#include "../Utils/List.h"
#include<stdio.h>

void PrintExpectList(int expectList[], int length)
{
	for (int i = 0; i < length; i++) {
		printf("%d ", expectList[i]);
	}
	printf("\n");
}

//create list and add node to tail
void Test1(LISTNODE* pHead, int expectList[], int length)
{
	printf("Test1: create list and add node to tail\n");

	if (pHead != nullptr) return;
	
	pHead = CreateNode(1);
	LISTNODE* node2 = CreateNode(2);
	LISTNODE* node3 = CreateNode(3);
	LISTNODE* node4 = CreateNode(4);
	ConnectNode(pHead, node2);
	ConnectNode(node3, node4);

	AddNodeToTail(pHead, 3);

	PrintListForward(pHead);

	PrintExpectList(expectList, length);
}

//test delete function
void TestDelete(const char* testDescription, LISTNODE* pHead, int value, int expectList[], int length)
{
	printf(testDescription);

	if (pHead == nullptr) return;

	DeleteNodeByValue(pHead, value);
	
	PrintListForward(pHead);

	PrintExpectList(expectList, length);
}

int main()
{
	LISTNODE* pHead = nullptr;

	int expectList[5] = { 1, 2, 3, 4, 3 };
	Test1(pHead, expectList, 5);

	int expectList1[5] = {2, 3, 4, 3 };
	TestDelete("Test2: delete head node\n", pHead, 1, expectList1, 4);
	
	int expectList2[5] = {2, 4, 3 };
	TestDelete("Test2: delete middle node\n", pHead, 3, expectList2, 3);
	
	int expectList3[5] = {2, 4};
	TestDelete("Test2: delete middle node\n", pHead, 3, expectList3, 2);


	return 0;
}