#include<stdio.h>
#include "../Utils/List.h"

#pragma comment(lib, "../Debug/Utils.lib")

PLISTNODE mergeSortedListRecursively(PLISTNODE pListOne, PLISTNODE pListTwo)
{
    if (!pListOne) return pListTwo;
    if (!pListTwo) return pListOne;

    if (pListOne->m_nValue < pListTwo->m_nValue) {
        pListOne->m_pNext = mergeSortedListRecursively(pListOne->m_pNext, pListTwo);
        return pListOne;
    }
    else {
        pListTwo->m_pNext = mergeSortedListRecursively(pListOne, pListTwo->m_pNext);
        return pListTwo;
    }

}

PLISTNODE mergeSortedList(PLISTNODE pListOne, PLISTNODE pListTwo)
{
	if (pListOne == nullptr) return pListTwo;
	if (pListTwo == nullptr) return pListOne;
	//sorted list and ascending
	//find header
	PLISTNODE pListNewHeader;
	PLISTNODE pOther;
	if (pListOne->m_nValue > pListTwo->m_nValue) {
		pListNewHeader = pListTwo;
		pOther = pListOne;
	}
	else {
		pListNewHeader = pListOne;
		pOther = pListTwo;
	}

	//traversal
	PLISTNODE pMove = pListNewHeader;

	do
	{
		PLISTNODE pPreMove = pMove;
		if(pMove->m_pNext != nullptr) pMove = pMove->m_pNext;
		while (pMove != nullptr && pMove->m_nValue < pOther->m_nValue)
		{
			pMove = pMove->m_pNext;
			pPreMove = pPreMove->m_pNext;
		}
		if (pMove == nullptr) break;
		pPreMove->m_pNext = pOther;
		
		PLISTNODE pPreOther = pOther;
		if(pOther != nullptr) pOther = pOther->m_pNext;
		while (pOther != nullptr && pOther->m_nValue < pMove->m_nValue)
		{
			pOther = pOther->m_pNext;
			pPreOther = pPreOther->m_pNext;
		}
		if (pOther == nullptr) break;
		pPreOther->m_pNext = pMove;
	} while (1);


	return pListNewHeader;
}

// ====================测试代码====================
ListNode* Test(const char* testName, ListNode* pHead1, ListNode* pHead2)
{
    if (testName != nullptr)
        printf("%s begins:\n", testName);

    printf("The first list is:\n");
    PrintListForward(pHead1);

    printf("The second list is:\n");
    PrintListForward(pHead2);

    printf("The merged list is:\n");
    ListNode* pMergedHead = mergeSortedListRecursively(pHead1, pHead2);
    PrintListForward(pMergedHead);

    printf("\n\n");

    return pMergedHead;
}

// list1: 1->3->5
// list2: 2->4->6
void Test1()
{
    ListNode* pNode1 = CreateNode(1);
    ListNode* pNode3 = CreateNode(3);
    ListNode* pNode5 = CreateNode(5);

    ConnectNode(pNode1, pNode3);
    ConnectNode(pNode3, pNode5);

    ListNode* pNode2 = CreateNode(2);
    ListNode* pNode4 = CreateNode(4);
    ListNode* pNode6 = CreateNode(6);

    ConnectNode(pNode2, pNode4);
    ConnectNode(pNode4, pNode6);

    ListNode* pMergedHead = Test("Test1", pNode1, pNode2);

    DestroyList(pMergedHead);
}

// 两个链表中有重复的数字
// list1: 1->3->5
// list2: 1->3->5
void Test2()
{
    ListNode* pNode1 = CreateNode(1);
    ListNode* pNode3 = CreateNode(3);
    ListNode* pNode5 = CreateNode(5);

    ConnectNode(pNode1, pNode3);
    ConnectNode(pNode3, pNode5);

    ListNode* pNode2 = CreateNode(1);
    ListNode* pNode4 = CreateNode(3);
    ListNode* pNode6 = CreateNode(5);

    ConnectNode(pNode2, pNode4);
    ConnectNode(pNode4, pNode6);

    ListNode* pMergedHead = Test("Test2", pNode1, pNode2);

    DestroyList(pMergedHead);
}

// 两个链表都只有一个数字
// list1: 1
// list2: 2
void Test3()
{
    ListNode* pNode1 = CreateNode(1);
    ListNode* pNode2 = CreateNode(2);

    ListNode* pMergedHead = Test("Test3", pNode1, pNode2);

    DestroyList(pMergedHead);
}

// 一个链表为空链表
// list1: 1->3->5
// list2: 空链表
void Test4()
{
    ListNode* pNode1 = CreateNode(1);
    ListNode* pNode3 = CreateNode(3);
    ListNode* pNode5 = CreateNode(5);

    ConnectNode(pNode1, pNode3);
    ConnectNode(pNode3, pNode5);

    ListNode* pMergedHead = Test("Test4", pNode1, nullptr);

    DestroyList(pMergedHead);
}

// 两个链表都为空链表
// list1: 空链表
// list2: 空链表
void Test5()
{
    ListNode* pMergedHead = Test("Test5", nullptr, nullptr);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}