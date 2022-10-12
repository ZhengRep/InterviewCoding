#include<cstdio>
#include "../Utils/BinaryTree.h"

#pragma comment(lib, "../Debug/Utils.lib")

BinaryTreeNode* ConvertBinarySearchTree(BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr) return nullptr;

	if (pRoot->m_pLeft == nullptr) return pRoot;

	BinaryTreeNode* pMostLeftLeafNodeInLeftTree = ConvertBinarySearchTree(pRoot->m_pLeft);

	//left tree have converted
	pMostLeftLeafNodeInLeftTree->m_pRight = pRoot;

	BinaryTreeNode* pMostLeftLeafNodeInRightTree = ConvertBinarySearchTree(pRoot->m_pRight);

	BinaryTreeNode* pRightTreeRoot = pRoot->m_pRight;
	
	pRoot->m_pRight = pMostLeftLeafNodeInRightTree;
	pMostLeftLeafNodeInRightTree->m_pLeft = pRoot;
	
	ConvertBinarySearchTree(pRightTreeRoot);
	return pRoot->m_pRight;
}

void Test(const char* testDescription, BinaryTreeNode* pRoot)
{
	printf("%s\n", testDescription);
	printf("Original Tree:\n");
	PrintBinaryTree(pRoot);
	printf("\nConverted:\n");
	BinaryTreeNode* pRightMostNode = ConvertBinarySearchTree(pRoot);
	while (pRightMostNode)
	{
		printf("%d\t", pRightMostNode->m_nValue);
		pRightMostNode = pRightMostNode->m_pLeft;
	}
	printf("\n");
}

void Test1()
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
	return 0;
}