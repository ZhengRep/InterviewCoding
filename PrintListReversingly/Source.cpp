#include<iostream>
#include<stack>
#include "../Utils/List.h"

#pragma comment(lib, "../Debug/Utils.lib")

void PrintListReversinglyByIterative(PLISTNODE ListHead)
{
	if (ListHead == nullptr) return;

	PLISTNODE pNode = ListHead;
	std::stack<PLISTNODE> NodesPointerStack;
	while (pNode)
	{
		NodesPointerStack.push(pNode);
		pNode = pNode->m_pNext;
	}

	while (!NodesPointerStack.empty())
	{
		printf("%d ", NodesPointerStack.top()->m_nValue);
		NodesPointerStack.pop();
	}

	printf("\n");
}

void PrintListReversinglyByRecursively(PLISTNODE pHead)
{
	if (pHead == nullptr) return;

	PrintListReversinglyByRecursively(pHead->m_pNext);

	printf("%d ", pHead->m_nValue);
}

/*
Test case:
1. empty list
2. long?
*/

int main()
{
	PLISTNODE pHead = nullptr;
	/*PLISTNODE pHead = CreateNode(1);
	LISTNODE* node2 = CreateNode(2);
	LISTNODE* node3 = CreateNode(3);
	LISTNODE* node4 = CreateNode(4);
	ConnectNode(pHead, node2);
	ConnectNode(node2, node3);
	ConnectNode(node3, node4);*/

	printf("Create list:");
	PrintListForward(pHead);

	printf("PrintList Reversingly by Inerative:\n");
	PrintListReversinglyByIterative(pHead);
	
	printf("PrintList Reversingly by Recursively:\n");
	PrintListReversinglyByRecursively(pHead);
	printf("\n");


	return 0;
}