#include <cstdio>
#include "../Utils/BinaryTree.h"
#include <stack>

void MirrorRecursively(BinaryTreeNode* pNode)
{
	if ((pNode == nullptr) || (pNode->m_pLeft == nullptr && pNode->m_pRight))
		return;

	BinaryTreeNode* pTemp = pNode->m_pLeft;
	pNode->m_pLeft = pNode->m_pRight;
	pNode->m_pRight = pTemp;

	if (pNode->m_pLeft)
		MirrorRecursively(pNode->m_pLeft);

	if (pNode->m_pRight)
		MirrorRecursively(pNode->m_pRight);
}

void MirrorIteratively(BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr)
		return;

	std::stack<BinaryTreeNode*> stackTreeNode;
	stackTreeNode.push(pRoot);

	while (stackTreeNode.size() > 0)
	{
		BinaryTreeNode* pNode = stackTreeNode.top();
		stackTreeNode.pop();

		BinaryTreeNode* pTemp = pNode->m_pLeft;
		pNode->m_pLeft = pNode->m_pRight;
		pNode->m_pRight = pTemp;

		if (pNode->m_pLeft)
			stackTreeNode.push(pNode->m_pLeft);

		if (pNode->m_pRight)
			stackTreeNode.push(pNode->m_pRight);
	}
}

// ====================测试代码====================
// 测试完全二叉树：除了叶子节点，其他节点都有两个子节点
//            8
//        6      10
//       5 7    9  11
void Test1()
{
	printf("=====Test1 starts:=====\n");
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
	BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);

	ConnectBinaryTreeNode(pNode8, pNode6, pNode10);
	ConnectBinaryTreeNode(pNode6, pNode5, pNode7);
	ConnectBinaryTreeNode(pNode10, pNode9, pNode11);

	PrintBinaryTree(pNode8);

	printf("=====Test1: MirrorRecursively=====\n");
	MirrorRecursively(pNode8);
	PrintBinaryTree(pNode8);

	printf("=====Test1: MirrorIteratively=====\n");
	MirrorIteratively(pNode8);
	PrintBinaryTree(pNode8);

	DestroyBinaryTree(pNode8);
}

// 测试二叉树：出叶子结点之外，左右的结点都有且只有一个左子结点
//            8
//          7   
//        6 
//      5
//    4
void Test2()
{
	printf("=====Test2 starts:=====\n");
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);

	ConnectBinaryTreeNode(pNode8, pNode7, nullptr);
	ConnectBinaryTreeNode(pNode7, pNode6, nullptr);
	ConnectBinaryTreeNode(pNode6, pNode5, nullptr);
	ConnectBinaryTreeNode(pNode5, pNode4, nullptr);

	PrintBinaryTree(pNode8);

	printf("=====Test2: MirrorRecursively=====\n");
	MirrorRecursively(pNode8);
	PrintBinaryTree(pNode8);

	printf("=====Test2: MirrorIteratively=====\n");
	MirrorIteratively(pNode8);
	PrintBinaryTree(pNode8);

	DestroyBinaryTree(pNode8);
}

// 测试二叉树：出叶子结点之外，左右的结点都有且只有一个右子结点
//            8
//             7   
//              6 
//               5
//                4
void Test3()
{
	printf("=====Test3 starts:=====\n");
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);

	ConnectBinaryTreeNode(pNode8, nullptr, pNode7);
	ConnectBinaryTreeNode(pNode7, nullptr, pNode6);
	ConnectBinaryTreeNode(pNode6, nullptr, pNode5);
	ConnectBinaryTreeNode(pNode5, nullptr, pNode4);

	PrintBinaryTree(pNode8);

	printf("=====Test3: MirrorRecursively=====\n");
	MirrorRecursively(pNode8);
	PrintBinaryTree(pNode8);

	printf("=====Test3: MirrorIteratively=====\n");
	MirrorIteratively(pNode8);
	PrintBinaryTree(pNode8);

	DestroyBinaryTree(pNode8);
}

// 测试空二叉树：根结点为空指针
void Test4()
{
	printf("=====Test4 starts:=====\n");
	BinaryTreeNode* pNode = nullptr;

	PrintBinaryTree(pNode);

	printf("=====Test4: MirrorRecursively=====\n");
	MirrorRecursively(pNode);
	PrintBinaryTree(pNode);

	printf("=====Test4: MirrorIteratively=====\n");
	MirrorIteratively(pNode);
	PrintBinaryTree(pNode);
}

// 测试只有一个结点的二叉树
void Test5()
{
	printf("=====Test5 starts:=====\n");
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);

	PrintBinaryTree(pNode8);

	printf("=====Test4: MirrorRecursively=====\n");
	MirrorRecursively(pNode8);
	PrintBinaryTree(pNode8);

	printf("=====Test4: MirrorIteratively=====\n");
	MirrorIteratively(pNode8);
	PrintBinaryTree(pNode8);
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