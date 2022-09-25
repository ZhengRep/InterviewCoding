#include<stdio.h>
#include "../Utils/List.h"

#pragma comment(lib, "../Debug/Utils.lib")

/*
I want to address this problem with recursive machanism

*/
PLISTNODE g_reversiveListHeader;

void reverseNextNode(PLISTNODE pPreNode)
{
	if (pPreNode == nullptr) return;
	PLISTNODE pCurrenttNode = pPreNode->m_pNext;
	if (pCurrenttNode == nullptr) {
		PrintNode(pPreNode);
		g_reversiveListHeader = pPreNode;
		return;
	}
	reverseNextNode(pCurrenttNode);
	pCurrenttNode->m_pNext = pPreNode;
}



int main()
{
	ListNode* pNode1 = CreateNode(1);
	/*ListNode* pNode2 = CreateNode(2);
	ListNode* pNode3 = CreateNode(3);
	ListNode* pNode4 = CreateNode(4);
	ListNode* pNode5 = CreateNode(5);

	ConnectNode(pNode1, pNode2);
	ConnectNode(pNode2, pNode3);
	ConnectNode(pNode3, pNode4);
	ConnectNode(pNode4, pNode5);*/

	reverseNextNode(pNode1);

	if(pNode1 != nullptr) pNode1->m_pNext = nullptr;

	printf("\n reversive list:\n");
	PrintListForward(g_reversiveListHeader);
	//DestroyList(pNode1);
	return 0;
}