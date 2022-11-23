#include<stdio.h>
#include "../Utils/List.h"

#pragma comment(lib, "../debug/Utils.lib")

void deleteListNode(PLISTNODE* pListHeaderAddr, PLISTNODE pDeleteNode)
{
	if ((*pListHeaderAddr) == nullptr || pDeleteNode == nullptr) return;

    PLISTNODE pListHeader = *pListHeaderAddr;
    if (pListHeader == pDeleteNode) {
        if (pListHeader->m_pNext == nullptr) {
            pListHeader = nullptr;
        }
        else {
		    pListHeader = pListHeader->m_pNext;
        }
        delete pDeleteNode;
        pDeleteNode = nullptr;
        *pListHeaderAddr = pListHeader;
        return;
	}

	PLISTNODE pNextNode = pListHeader;
	while (pNextNode->m_pNext != pDeleteNode && pNextNode->m_pNext != nullptr)
	{
		pNextNode = pNextNode->m_pNext;
	}

	if (pNextNode->m_pNext != pDeleteNode) return;
	pNextNode->m_pNext = pDeleteNode->m_pNext;
	delete pDeleteNode;
	pDeleteNode = nullptr;
}

//it is sure that to be deleted node exsit in list
void deleteListNodeO1(PLISTNODE* pListHeaderAddr, PLISTNODE pToBeDeletedNode) 
{
    if (*pListHeaderAddr == nullptr || pToBeDeletedNode == nullptr) return;

    PLISTNODE pListHeader = *pListHeaderAddr;

    //delete last tail
    if (pToBeDeletedNode->m_pNext == nullptr) {
        if (pListHeader->m_pNext == nullptr) {
            *pListHeaderAddr = nullptr;
        }
        else {
            while (pListHeader->m_pNext != pToBeDeletedNode)
            {
                pListHeader = pListHeader->m_pNext;
            }
            pListHeader->m_pNext = nullptr;
        }
        delete pToBeDeletedNode;
        pToBeDeletedNode = nullptr;
    }
    else {
        pToBeDeletedNode->m_nValue = pToBeDeletedNode->m_pNext->m_nValue;
        PLISTNODE pDeleteNode = pToBeDeletedNode->m_pNext;
        pToBeDeletedNode->m_pNext = pDeleteNode->m_pNext;
        delete pDeleteNode;
        pDeleteNode = nullptr;
    }

}

// ====================测试代码====================
void Test(ListNode* pListHead, ListNode* pNode)
{
    printf("The original list is: \n");
    PrintListForward(pListHead);

    printf("The node to be deleted is: \n");
    PrintNode(pNode);

    deleteListNodeO1(&pListHead, pNode);//what do you want to change
    //deleteListNode(&pListHead, pNode);//what do you want to change

    printf("\nThe result list is: \n");
    PrintListForward(pListHead);
}

// 链表中有多个结点，删除中间的结点
void Test1()
{
    ListNode* pNode1 = CreateNode(1);
    ListNode* pNode2 = CreateNode(2);
    ListNode* pNode3 = CreateNode(3);
    ListNode* pNode4 = CreateNode(4);
    ListNode* pNode5 = CreateNode(5);

    ConnectNode(pNode1, pNode2);
    ConnectNode(pNode2, pNode3);
    ConnectNode(pNode3, pNode4);
    ConnectNode(pNode4, pNode5);

    Test(pNode1, pNode3);

    DestroyList(pNode1);
}

// 链表中有多个结点，删除尾结点
void Test2()
{
    ListNode* pNode1 = CreateNode(1);
    ListNode* pNode2 = CreateNode(2);
    ListNode* pNode3 = CreateNode(3);
    ListNode* pNode4 = CreateNode(4);
    ListNode* pNode5 = CreateNode(5);

    ConnectNode(pNode1, pNode2);
    ConnectNode(pNode2, pNode3);
    ConnectNode(pNode3, pNode4);
    ConnectNode(pNode4, pNode5);

    Test(pNode1, pNode5);

    DestroyList(pNode1);
}

// 链表中有多个结点，删除头结点
void Test3()
{
    ListNode* pNode1 = CreateNode(1);
    ListNode* pNode2 = CreateNode(2);
    ListNode* pNode3 = CreateNode(3);
    ListNode* pNode4 = CreateNode(4);
    ListNode* pNode5 = CreateNode(5);

    ConnectNode(pNode1, pNode2);
    ConnectNode(pNode2, pNode3);
    ConnectNode(pNode3, pNode4);
    ConnectNode(pNode4, pNode5);

    Test(pNode1, pNode1);

    //DestroyList(pNode1);
}

// 链表中只有一个结点，删除头结点
void Test4()
{
    ListNode* pNode1 = CreateNode(1);

    Test(pNode1, pNode1);
}

// 链表为空
void Test5()
{
    Test(nullptr, nullptr);
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