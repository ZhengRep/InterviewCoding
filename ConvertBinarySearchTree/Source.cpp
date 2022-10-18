#include<cstdio>
#include "../Utils/BinaryTree.h"

#pragma comment(lib, "../Debug/Utils.lib")

/*
want to traslate a sorted binary tree to a double link list
*/

//recursively is not convenience with return value
void ConvertNode(BinaryTreeNode* pRoot, BinaryTreeNode** pLastListNode)
{
	if (pRoot == nullptr) return;

	if (pRoot->m_pLeft != nullptr) {
		ConvertNode(pRoot->m_pLeft, pLastListNode);
	}

	pRoot->m_pLeft = *pLastListNode;
	if (*pLastListNode != nullptr) {
		(*pLastListNode)->m_pRight = pRoot;
	}
	*pLastListNode = pRoot;

	if (pRoot->m_pRight != nullptr) {
		ConvertNode(pRoot->m_pRight, pLastListNode);
	}

}

/*
Binary's unit is tree node: value pLeft pRight
the next parameter is very important, because it record the the last deal state in recurseive !!!
*/

BinaryTreeNode* Convert(BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr) return nullptr;

	BinaryTreeNode* pLastListNode = nullptr;
	ConvertNode(pRoot, &pLastListNode);

	//reverse list
	while (pLastListNode != nullptr && pLastListNode->m_pLeft != nullptr)
	{
		pLastListNode = pLastListNode->m_pLeft;
	}
	return pLastListNode;
}


void Test(const char* testDescription, BinaryTreeNode* pRoot)
{
	printf("%s\n", testDescription);
	printf("Original Tree:\n");
	PrintBinaryTree(pRoot);
	printf("\nConverted:\n");
	BinaryTreeNode* pNewList = Convert(pRoot);
	while (pNewList)
	{
		printf("%d ", pNewList->m_nValue);
		pNewList = pNewList->m_pRight;
	}
	printf("\n");
}

void Test1()
{
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);

	ConnectTreeNodes(pNode10, pNode7, nullptr);
	ConnectTreeNodes(pNode7, pNode5, nullptr);
	ConnectTreeNodes(pNode5, pNode4, nullptr);
	ConnectTreeNodes(pNode4, nullptr, nullptr);

	Test("only left tree:", pNode10);
}

void Test2()
{
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
	BinaryTreeNode* pNode13 = CreateBinaryTreeNode(13);
	BinaryTreeNode* pNode14 = CreateBinaryTreeNode(14);

	ConnectTreeNodes(pNode10, nullptr, pNode12);
	ConnectTreeNodes(pNode12, nullptr, pNode13);
	ConnectTreeNodes(pNode13, nullptr, pNode14);
	ConnectTreeNodes(pNode14, nullptr, nullptr);

	Test("only right tree:", pNode10);
}

void Test3()
{
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
	BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);
	BinaryTreeNode* pNode13 = CreateBinaryTreeNode(13);

	ConnectTreeNodes(pNode10, pNode7, pNode12);
	ConnectTreeNodes(pNode7, pNode5, pNode8);
	ConnectTreeNodes(pNode12, pNode11, pNode13);

	Test("Nomal test:", pNode10);
}

int main()
{
	Test1();
	Test2();
	Test3();
	return 0;
}