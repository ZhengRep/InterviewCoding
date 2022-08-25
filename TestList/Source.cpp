#include "../Utils/List.h"
#include<stdio.h>

#pragma comment(lib, "..//Debug//Utils.lib")

void PrintExpectList(int expectList[], int length)
{

	printf("Expect List:\n");
	for (int i = 0; i < length; i++) {
		printf("%d ", expectList[i]);
	}
	printf("\n");
}

//create list and add node to tail
void Test1(PLISTNODE* pHeaderAddr, int expectList[], int length)
{
	printf("Test1: create list and add node to tail\n");

	//create a new list
	if (*pHeaderAddr != nullptr) return;
	
	*pHeaderAddr = CreateNode(1);
	LISTNODE* node2 = CreateNode(2);
	LISTNODE* node3 = CreateNode(3);
	LISTNODE* node4 = CreateNode(4);
	ConnectNode(*pHeaderAddr, node2);
	ConnectNode(node2, node3);
	ConnectNode(node3, node4);

	AddNodeToTail(*pHeaderAddr, 3);

	PrintListForward(*pHeaderAddr);

	PrintExpectList(expectList, length);
}

//test delete function
void TestDelete(const char* testDescription, PLISTNODE* pHeaderAddr, int value, int expectList[], int length)
{
	printf(testDescription);

	if (*pHeaderAddr == nullptr) return;

	DeleteNodeByValue(pHeaderAddr, value);
	
	PrintListForward(*pHeaderAddr);

	PrintExpectList(expectList, length);
}

int main()
{
	LISTNODE* pHead = nullptr;

	int expectList[5] = { 1, 2, 3, 4, 3 };
	Test1(&pHead, expectList, 5);

	int expectList1[4] = {2, 3, 4, 3 };
	TestDelete("Test2: delete head node\n", &pHead, 1, expectList1, 4);
	
	int expectList2[3] = {2, 4, 3 };
	TestDelete("Test2: delete middle node\n", &pHead, 3, expectList2, 3);
	
	int expectList3[2] = {2, 4};
	TestDelete("Test2: delete tail node\n", &pHead, 3, expectList3, 2);
	
	int expectList4[1] = {2};
	TestDelete("Test2: delete tail node\n", &pHead, 4, expectList4, 1);

	int expectList5[1] = {};
	TestDelete("Test2: delete tail node\n", &pHead, 2, expectList5, 0);


	return 0;
}