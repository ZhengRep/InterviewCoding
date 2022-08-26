#include "BinaryTree.h"
#include<stdio.h>

PBINARYTREENODE CreateBinaryTreeNode(int value)
{
	PBINARYTREENODE pNode = new BINARYTREENODE();
	if (pNode == nullptr) return nullptr;
	pNode->m_nValue = value;
	pNode->m_pLeft = nullptr;
	pNode->m_pRight = nullptr;
	return pNode;
}

void ConnetBinaryTreeNode(PBINARYTREENODE pBinaryTreeRoot, PBINARYTREENODE pLeftNode, PBINARYTREENODE pRightNode)
{
	if (pBinaryTreeRoot == nullptr) return;
	if (pLeftNode != nullptr) {
		pBinaryTreeRoot->m_pLeft = pLeftNode;
	}
	if (pRightNode != nullptr) {
		pBinaryTreeRoot->m_pRight = pRightNode;
	}
}

void DestoryBinaryTree(PBINARYTREENODE pBinaryTreeRoot)
{
	if (pBinaryTreeRoot == nullptr) return;
	DestoryBinaryTree(pBinaryTreeRoot->m_pLeft);
	DestoryBinaryTree(pBinaryTreeRoot->m_pRight);

	delete pBinaryTreeRoot;
	pBinaryTreeRoot = nullptr;
}

//inorder traversal
void PrintBinaryTree(const PBINARYTREENODE pBinaryTreeRoot)
{
	if (pBinaryTreeRoot == nullptr) return;

	PrintBinaryTree(pBinaryTreeRoot->m_pLeft);
	printf("%d ", pBinaryTreeRoot->m_nValue);
	PrintBinaryTree(pBinaryTreeRoot->m_pRight);
}
