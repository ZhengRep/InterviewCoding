#include<stdio.h>
#include "../Utils/List.h"

#pragma comment(lib, "../Debug/Utils.lib")

bool deleteNodeInList(PLISTNODE pListHeader, PLISTNODE pDeleteListNode)
{
	if (pListHeader == nullptr || pDeleteListNode == nullptr) return false;
	while (pListHeader->m_pNext != pDeleteListNode)
	{
		if (pListHeader->m_pNext == nullptr) return false;
		pListHeader = pListHeader->m_pNext;
	}
	if (pListHeader->m_pNext == nullptr) {
		pListHeader = nullptr;
	}
	else {
		pListHeader->m_pNext = pListHeader->m_pNext->m_pNext;
	}
	delete pDeleteListNode;
}

bool deleteNodeListByO1(PLISTNODE pListHeader, PLISTNODE pDeleteListNode)
{
	if (pListHeader == nullptr || pDeleteListNode == nullptr) return false;

	if (pListHeader == pDeleteListNode) {
		pListHeader = pListHeader->m_pNext;
		delete pDeleteListNode;
		pDeleteListNode == nullptr;
		return true;
	}
	
	//swap value with next node
	if (pDeleteListNode->m_pNext == nullptr) {
		delete pDeleteListNode;
		pDeleteListNode == nullptr;
		return true;
	}
	pDeleteListNode->m_nValue = pDeleteListNode->m_pNext->m_nValue;
	PLISTNODE pTempListNode = pDeleteListNode->m_pNext;
	pDeleteListNode->m_pNext = pTempListNode->m_pNext;
	delete pTempListNode;
	pTempListNode == nullptr;
	return true;
}

int main()
{
	PLISTNODE pListHeader = CreateNode(1);
	PLISTNODE pNode2 = CreateNode(2);
	PLISTNODE pNode3 = CreateNode(3);
	PLISTNODE pNode4 = CreateNode(4);
	ConnectNode(pListHeader, pNode2);
	ConnectNode(pNode2, pNode3);
	ConnectNode(pNode3, pNode4);

	printf("Origion list:\n");
	PrintListForward(pListHeader);

	printf("Delete one Node:\n");
	deleteNodeListByO1(pListHeader, pNode4);
	PrintListForward(pListHeader);
	printf("Expect deleted list:\n");
	printf("1 2 3 \n");
	
	printf("Delete one Node:\n");
	deleteNodeListByO1(pListHeader, pNode2);
	PrintListForward(pListHeader);
	printf("Expect deleted list:\n");
	printf("1 3 \n");

	printf("Delete one Node:\n");
	deleteNodeListByO1(pListHeader, pListHeader);
	PrintListForward(pListHeader);
	printf("Expect deleted list:\n");
	printf("3 \n");
	
	printf("Delete one Node:\n");
	deleteNodeListByO1(pListHeader, pListHeader);
	PrintListForward(pListHeader);
	printf("Expect deleted list:\n");
	printf("\n");

	return 0;
}
/*
test case:
nullptr
one
two
four

header and tailer
*/