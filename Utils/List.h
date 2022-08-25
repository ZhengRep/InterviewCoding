#pragma once
#include<stdio.h>

struct LISTNODE {
	int m_nValue;
	LISTNODE* m_pNext;
};
typedef LISTNODE* PLISTNODE;

__declspec(dllexport) LISTNODE * CreateNode(int value);
__declspec(dllexport) void ConnectNode(LISTNODE* pCurrent, LISTNODE* pNext);
__declspec(dllexport) bool DeleteNodeByValue(PLISTNODE* pHeaderAddr, int value);
__declspec(dllexport) void AddNodeToTail(LISTNODE* pHead, int value);
__declspec(dllexport) void PrintNode(LISTNODE* pNode);
__declspec(dllexport) void PrintListForward(LISTNODE* pHead);
__declspec(dllexport) void DestroyList(LISTNODE* pHead);