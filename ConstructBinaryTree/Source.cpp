#include<exception>
#include<stdio.h>
#include "../Utils/BinaryTree.h"

#pragma comment(lib, "../Debug/Utils.lib")

/*
principal£º
the first node in preorder is root
the left part in inorder by root is left child tree
			1
		2		3
	4				5

Preorder: 1 2 4 3 5
Inorder:  4 2 1 3 5

*/


PBINARYTREENODE ConstructBinaryTreeCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder)
{
	if (startPreorder == endPreorder || startInorder == endInorder) throw std::exception("Argument error");

	int rootValue = *startPreorder;
	PBINARYTREENODE pRoot = CreateBinaryTreeNode(rootValue);

	//to find rootValue in inorder
	while (*startInorder != rootValue)
	{
		++startInorder;
	}
	if (startInorder == endInorder) {
		if (*startInorder != rootValue) throw std::exception("Invalide input");
		else return pRoot;
	}
	int leftLength = endInorder - startInorder;
	int* rootInorder = startInorder;

	pRoot->m_pLeft = ConstructBinaryTreeCore(startPreorder + 1, startPreorder + leftLength, startInorder - leftLength, startInorder - 1);
	pRoot->m_pRight = ConstructBinaryTreeCore(startPreorder + leftLength + 1, endPreorder, startInorder + 1, endInorder);

	return pRoot;
}

void ConstructBinaryTree(PBINARYTREENODE* pRootAddr, int preorder[], int inorder[], int length)
{
	if (*pRootAddr != nullptr || preorder == nullptr || inorder == nullptr || length == 0) return;
	*pRootAddr = ConstructBinaryTreeCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

int main()
{
	PBINARYTREENODE pRoot = nullptr;
	int preorder[5] = { 1, 2, 4, 3, 5 };
	int inorder[5] = { 4, 2, 1, 3, 5 };

	ConstructBinaryTree(&pRoot, preorder, inorder, 5);
	printf("Construct tree:\n");
	PrintBinaryTree(pRoot);
	printf("\n");

	printf("Expect tree:\n");
	printf("1 2 4 3 5\n");

	return 0;
}