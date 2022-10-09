#pragma once

struct BINARYTREENODE {
	int m_nValue;
	BINARYTREENODE* m_pLeft;
	BINARYTREENODE* m_pRight;
};
typedef BINARYTREENODE* PBINARYTREENODE;
typedef BINARYTREENODE BinaryTreeNode;

__declspec(dllexport) PBINARYTREENODE CreateBinaryTreeNode(int value);
__declspec(dllexport) void ConnectBinaryTreeNode(PBINARYTREENODE pBinaryTreeRoot, PBINARYTREENODE pLeftNode, PBINARYTREENODE pRightNode);
__declspec(dllexport) void DestroyBinaryTree(PBINARYTREENODE pBinaryTreeRoot);
__declspec(dllexport) void PrintBinaryTree(const PBINARYTREENODE pBinaryTreeRoot);

