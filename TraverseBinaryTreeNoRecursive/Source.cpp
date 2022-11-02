#include<iostream>
#include<stack>

using namespace std;

typedef struct _BinaryTreeNode_ {
	int m_iValue;
	_BinaryTreeNode_* m_pLeft;
	_BinaryTreeNode_* m_pRight;
}BinaryTreeNode;

BinaryTreeNode* CreateBinaryTreeNode(int value)
{
	BinaryTreeNode* newNode = new BinaryTreeNode;
	newNode->m_iValue = value;
	newNode->m_pLeft = NULL;
	newNode->m_pRight = NULL;
	return newNode;
}

void ConnectNodes(BinaryTreeNode* pParentNode, BinaryTreeNode* pLeftChildNode, BinaryTreeNode* pRightChildNode)
{
	pParentNode->m_pLeft = pLeftChildNode;
	pParentNode->m_pRight = pRightChildNode;
}

void DestroyBinaryTree(BinaryTreeNode* pRoot)
{
	if (pRoot == NULL) return;
	if (pRoot->m_pLeft != NULL) {
		DestroyBinaryTree(pRoot->m_pLeft);
	}
	if (pRoot->m_pRight != NULL) {
		DestroyBinaryTree(pRoot->m_pRight);
	}
	delete pRoot;
	pRoot = NULL;
}

void PreorderNonrecursive(BinaryTreeNode* pRoot)
{
	if (pRoot == NULL) return;

	stack<BinaryTreeNode*> RootNodesStack;
	while (pRoot != NULL || !RootNodesStack.empty())
	{
		while (pRoot != NULL)
		{
			cout << pRoot->m_iValue << " ";
			RootNodesStack.push(pRoot);
			pRoot = pRoot->m_pLeft;
		}
		if (!RootNodesStack.empty()) {
			pRoot = RootNodesStack.top();
			RootNodesStack.pop();
			pRoot = pRoot->m_pRight;
		}
	}
}

void InorderNonrecursive(BinaryTreeNode* pRoot)
{
	if (pRoot == NULL) return;

	stack<BinaryTreeNode*> RootNodesStack;
	while (pRoot != NULL || !RootNodesStack.empty())
	{
		while (pRoot != NULL)
		{
			RootNodesStack.push(pRoot);
			pRoot = pRoot->m_pLeft;
		}
		if (!RootNodesStack.empty()) {
			pRoot = RootNodesStack.top();
			RootNodesStack.pop();
			cout << pRoot->m_iValue << " ";
			pRoot = pRoot->m_pRight;
		}
	}
}

typedef struct _NODEPOINTERWARP_ {
	BinaryTreeNode* m_pTreeNode;
	bool m_bIsFirstVisit = true;
}NodePointerWrap;

void PostorderNonrecursive(BinaryTreeNode* pRoot)
{
	if (pRoot == NULL) return;

	stack<NodePointerWrap*> RootNodesPointerWrapStack;
	while (pRoot != NULL || !RootNodesPointerWrapStack.empty())
	{
		while (pRoot != NULL)
		{
			NodePointerWrap* newWrap = new NodePointerWrap;
			newWrap->m_pTreeNode = pRoot;
			RootNodesPointerWrapStack.push(newWrap);
			pRoot = pRoot->m_pLeft;
		}
		if (!RootNodesPointerWrapStack.empty()) {
			NodePointerWrap* rootPointerWrap = RootNodesPointerWrapStack.top();
			if (rootPointerWrap->m_bIsFirstVisit) {
				rootPointerWrap->m_bIsFirstVisit = false;
				pRoot = rootPointerWrap->m_pTreeNode->m_pRight;
			}
			else {
				RootNodesPointerWrapStack.pop();
				cout << rootPointerWrap->m_pTreeNode->m_iValue << " ";
			}
		}
	}
}

// ====================测试代码====================
void Test(const char* testName, BinaryTreeNode* pRoot, int* expectValues, int length)
{
	if (testName) printf("%s\n", testName);
	PreorderNonrecursive(pRoot);
	printf("\nexpect values:\n");
	for (int i = 0; i < length; i++)
	{
		cout << expectValues[i] << " ";
	}
	printf("\n");
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

	ConnectNodes(pNode10, pNode6, pNode14);
	ConnectNodes(pNode6, pNode4, pNode8);
	ConnectNodes(pNode14, pNode12, pNode16);

	int expectValuesPreorder[] = { 10, 6, 4, 8, 14, 12, 16 };
	Test("Preorder traversal:", pNode10, expectValuesPreorder, 7);
	/*int expectValuesInorder[] = {4, 6, 8, 10, 12, 14, 16};
	Test("Inorder traversal:", pNode10, expectValuesInorder, 7);*/
	/*int expectValuesPostorder[] = {4, 8, 6, 12, 16, 14, 10};
	Test("Inorder traversal:", pNode10, expectValuesPostorder, 7);*/

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

	ConnectNodes(pNode5, pNode4, nullptr);
	ConnectNodes(pNode4, pNode3, nullptr);
	ConnectNodes(pNode3, pNode2, nullptr);
	ConnectNodes(pNode2, pNode1, nullptr);

	int expectValuesInorder[] = { 5, 4, 3, 2, 1 };
	Test("Test2", pNode5, expectValuesInorder, 5);

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

	ConnectNodes(pNode1, nullptr, pNode2);
	ConnectNodes(pNode2, nullptr, pNode3);
	ConnectNodes(pNode3, nullptr, pNode4);
	ConnectNodes(pNode4, nullptr, pNode5);

	int expectValuesInorder[] = {1, 2, 3, 4, 5};
	Test("Test3", pNode1, expectValuesInorder, 5);

	(pNode1);
}

// 树中只有1个结点
void Test4()
{
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);

	int expectValuesInorder[] = { 1};
	Test("Test4", pNode1, expectValuesInorder, 1);

	DestroyBinaryTree(pNode1);
}

int main()
{
	Test1();
	/*Test2();
	Test3();
	Test4();*/

	return 0;
}