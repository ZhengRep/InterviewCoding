#include<cstdio>
#include "../Utils//BinaryTree.h"
#include<vector>

#pragma comment(lib, "../Debug/Utils.lib")

bool checkVectorNodeSum(std::vector<PBINARYTREENODE>& vector,int sum) //use currentSum to replace this function
{
	int tempSum = 0;
	for (auto i = vector.begin(); i != vector.end(); i++)
	{
		tempSum += (*i)->m_nValue;
	}
	if (tempSum == sum) {
		
		return true;
	}
	return false;
}

void traversalTreeByPreOrderAndCheckSumToPrint(PBINARYTREENODE pRoot, std::vector<PBINARYTREENODE>& vector, int& curentSum, int sum) //add currentsum 
{
	if (!pRoot) return;

	vector.push_back(pRoot);
	curentSum += pRoot->m_nValue;

	if (curentSum == sum) {
		if (!pRoot->m_pLeft && !pRoot->m_pRight) { //print and pop must be leaf node
			for (auto i = vector.begin(); i != vector.end(); i++)
			{
				printf("%d\t", (*i)->m_nValue);
			}
			printf("\n");
		}
	}
	traversalTreeByPreOrderAndCheckSumToPrint(pRoot->m_pLeft, vector, curentSum, sum);
	traversalTreeByPreOrderAndCheckSumToPrint(pRoot->m_pRight, vector, curentSum, sum);

	vector.pop_back();
	curentSum -= pRoot->m_nValue;
}

void printPathInTreeBySum(PBINARYTREENODE pRoot, int sum)
{
	if (!pRoot) return;

	std::vector<PBINARYTREENODE> vector;

	//traversal tree by preorder 
	
	int currentSum = 0;
	traversalTreeByPreOrderAndCheckSumToPrint(pRoot, vector, currentSum, sum);
}



// ====================���Դ���====================
void Test(const char* testName, BinaryTreeNode* pRoot, int expectedSum)
{
	if (testName != nullptr)
		printf("%s begins:\n", testName);

	printPathInTreeBySum(pRoot, expectedSum);

	printf("\n");
}

//            10
//         /      \
//        5        12
//       /\        
//      4  7     
// ������·���ϵĽ���Ϊ22
void Test1()
{
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode0 = CreateBinaryTreeNode(0);

	ConnectTreeNodes(pNode10, pNode5, pNode12);
	ConnectTreeNodes(pNode5, pNode4, pNode7);
	ConnectTreeNodes(pNode7, pNode0, nullptr);

	printf("Two paths should be found in Test1.\n");
	Test("Test1", pNode10, 22);

	DestroyTree(pNode10);
}

//            10
//         /      \
//        5        12
//       /\        
//      4  7     
// û��·���ϵĽ���Ϊ15
void Test2()
{
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

	ConnectTreeNodes(pNode10, pNode5, pNode12);
	ConnectTreeNodes(pNode5, pNode4, pNode7);

	printf("No paths should be found in Test2.\n");
	Test("Test2", pNode10, 15);

	DestroyTree(pNode10);
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
// ��һ��·������Ľ���Ϊ15
void Test3()
{
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);

	ConnectTreeNodes(pNode5, pNode4, nullptr);
	ConnectTreeNodes(pNode4, pNode3, nullptr);
	ConnectTreeNodes(pNode3, pNode2, nullptr);
	ConnectTreeNodes(pNode2, pNode1, nullptr);

	printf("One path should be found in Test3.\n");
	Test("Test3", pNode5, 15);

	DestroyTree(pNode5);
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
// û��·������Ľ���Ϊ16
void Test4()
{
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

	ConnectTreeNodes(pNode1, nullptr, pNode2);
	ConnectTreeNodes(pNode2, nullptr, pNode3);
	ConnectTreeNodes(pNode3, nullptr, pNode4);
	ConnectTreeNodes(pNode4, nullptr, pNode5);

	printf("No paths should be found in Test4.\n");
	Test("Test4", pNode1, 16);

	DestroyTree(pNode1);
}

// ����ֻ��1�����
void Test5()
{
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);

	printf("One path should be found in Test5.\n");
	Test("Test5", pNode1, 1);

	DestroyTree(pNode1);
}

// ����û�н��
void Test6()
{
	printf("No paths should be found in Test6.\n");
	Test("Test6", nullptr, 0);
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();

	return 0;
}