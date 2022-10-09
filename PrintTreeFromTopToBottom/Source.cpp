#include<stdio.h>
#include<deque>
#include "../Utils/BinaryTree.h"

#pragma comment(lib, "../Debug/Utils.lib")

void printTreeFromTopToBottom(PBINARYTREENODE pRoot)
{
	if (!pRoot) return;

	std::deque<PBINARYTREENODE> deque;

	//push node , print node from deque and push node's child
	deque.push_back(pRoot);
	PBINARYTREENODE pNode;
	while (!deque.empty())
	{
		pNode = deque.front();
		printf("%d\t", pNode->m_nValue);
		if (pNode->m_pLeft) deque.push_back(pNode->m_pLeft);
		if (pNode->m_pRight) deque.push_back(pNode->m_pRight);
		deque.pop_front();
		
	}
}



// ====================测试代码====================
void Test(const char* testName, BinaryTreeNode* pRoot)
{
	if (testName != nullptr)
		printf("%s begins: \n", testName);

	PrintBinaryTree(pRoot);

	printf("\nThe nodes from top to bottom, from left to right are: \n");
	printTreeFromTopToBottom(pRoot);

	printf("\n\n");
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void Test1()
{
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode14 = CreateBinaryTreeNode(14);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
	BinaryTreeNode* pNode16 = CreateBinaryTreeNode(16);

	ConnectBinaryTreeNode(pNode10, pNode6, pNode14);
	ConnectBinaryTreeNode(pNode6, pNode4, pNode8);
	ConnectBinaryTreeNode(pNode14, pNode12, pNode16);

	Test("Test1", pNode10);

	DestroyBinaryTree(pNode10);
}

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
void Test2()
{
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);

	ConnectBinaryTreeNode(pNode5, pNode4, nullptr);
	ConnectBinaryTreeNode(pNode4, pNode3, nullptr);
	ConnectBinaryTreeNode(pNode3, pNode2, nullptr);
	ConnectBinaryTreeNode(pNode2, pNode1, nullptr);

	Test("Test2", pNode5);

	DestroyBinaryTree(pNode5);
}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
void Test3()
{
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

	ConnectBinaryTreeNode(pNode1, nullptr, pNode2);
	ConnectBinaryTreeNode(pNode2, nullptr, pNode3);
	ConnectBinaryTreeNode(pNode3, nullptr, pNode4);
	ConnectBinaryTreeNode(pNode4, nullptr, pNode5);

	Test("Test3", pNode1);

	(pNode1);
}

// 树中只有1个结点
void Test4()
{
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
	Test("Test4", pNode1);

	DestroyBinaryTree(pNode1);
}

// 树中没有结点
void Test5()
{
	Test("Test5", nullptr);
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