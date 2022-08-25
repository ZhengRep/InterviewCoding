#pragma once
#include<stdio.h>

struct LISTNODE {
	int m_nValue;
	LISTNODE* m_pNext;
};

__declspec(dllexport) LISTNODE * CreateNode(int value);
__declspec(dllexport) void ConnectNode(LISTNODE* pCurrent, LISTNODE* pNext);
__declspec(dllexport) bool DeleteNodeByValue(LISTNODE* pHead, int value);
__declspec(dllexport) void AddNodeToTail(LISTNODE* pHead, int value);
__declspec(dllexport) void PrintNode(LISTNODE node);
__declspec(dllexport) void PrintListForward(LISTNODE* pHead);