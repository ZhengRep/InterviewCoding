#include "List.h"
#include "pch.h"

LISTNODE* CreateNode(int value)
{
	LISTNODE* pNode = new LISTNODE();
	if (pNode == nullptr) return nullptr;
	pNode->m_nValue = value;
	pNode->m_pNext = nullptr;
	return pNode;
}

void ConnectNode(LISTNODE* pCurrent, LISTNODE* pNext)
{
	if (pCurrent == nullptr || pNext == nullptr) return;

	pCurrent->m_pNext = pNext;
}

bool DeleteNodeByValue(LISTNODE* pHead, int value)
{
	if (pHead == nullptr) return false;

	LISTNODE* pNode = pHead;
	if (pNode->m_nValue == value) {
		if (pHead->m_pNext != nullptr) pHead = pHead->m_pNext;
		else pHead = nullptr;

		delete pNode;
	}
	else {
		if (pNode->m_pNext == nullptr) return false;
		else {
			while (pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue != value)
			{
				pNode = pNode->m_pNext;
			}
			if (pNode->m_pNext == nullptr) return false;

			LISTNODE* pTempNode = pNode->m_pNext;
			pNode->m_pNext = pTempNode->m_pNext;
			delete pTempNode;
		}
	}
	return true;
}

void AddNodeToTail(LISTNODE* pHead, int value)
{
	if (pHead == nullptr) return;

	LISTNODE* pNode = pHead;
	while (pNode->m_pNext != nullptr)
	{
		pNode = pNode->m_pNext;
	}

	LISTNODE* pNewNode = CreateNode(value);
	if (pNewNode == nullptr) return;
	pNode->m_pNext = pNewNode;

}

void PrintNode(LISTNODE* pNode)
{
	printf("%d ", pNode->m_nValue);
}

void PrintListForward(LISTNODE* pHead)
{
	if (pHead == nullptr) return;

	LISTNODE* pNode = pHead;
	while (pNode != nullptr)
	{
		PrintNode(pNode);
		pNode = pNode->m_pNext;
	}
	printf("\n");
}
