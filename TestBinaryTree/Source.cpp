#include<stdio.h>
#include "../Utils/BinaryTree.h"

#pragma comment(lib, "..//Debug//Utils.lib")

/*
			1
		2		3
	4				5
*/

int main()
{
	PBINARYTREENODE pRoot = CreateBinaryTreeNode(1);
	PBINARYTREENODE node2 = CreateBinaryTreeNode(2);
	PBINARYTREENODE node3 = CreateBinaryTreeNode(3);
	ConnectTreeNodes(pRoot, node2, node3);
	PBINARYTREENODE node4 = CreateBinaryTreeNode(4);
	ConnectTreeNodes(node2, node4, nullptr);
	PBINARYTREENODE node5 = CreateBinaryTreeNode(5);
	ConnectTreeNodes(node3, nullptr, node5);

	PrintBinaryTree(pRoot);
	printf("\n");

	ConnectTreeNodes(pRoot);
	return 0;
}