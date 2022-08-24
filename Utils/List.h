#pragma once

struct LISTNODE {
	int m_nValue;
	LISTNODE* m_pNext;
};

extern "C" LISTNODE * CreateNode(int value);
extern "C" void ConnectNode(LISTNODE* pCurrent, LISTNODE* pNext);
extern "C" bool DeleteNodeByValue(LISTNODE* pHead, int value);
extern "C" void AddNodeToTail(LISTNODE* pHead, int value);
extern "C" void PrintNode(LISTNODE node);
extern "C" void PrintListForward(LISTNODE* pHead);
 