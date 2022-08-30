#include<exception>
#include<stdio.h>
#include "../Utils/BinaryTree.h"

#pragma comment(lib, "../Debug/Utils.lib")

/*
principal：
the first node in preorder is root
the left part in inorder by root is left child tree
			1
		2		3
	4				5

Preorder: 1 2 4 3 5
Inorder:  4 2 1 3 5

what is substract:

*/


PBINARYTREENODE ConstructBinaryTreeCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder)
{
	if (startInorder == nullptr || endPreorder == nullptr || startInorder > endPreorder || startInorder == nullptr || endInorder == nullptr || startInorder > endInorder) return nullptr;

    if (startPreorder == endPreorder && startInorder == endInorder) {
        if (*startPreorder != *startInorder) throw std::exception("Invalid input");
        return CreateBinaryTreeNode(*startPreorder);
    }
	
	int rootValue = *startPreorder;
	PBINARYTREENODE pRoot = CreateBinaryTreeNode(rootValue);

	int* startInorderOriginal = startInorder;
	while (*startInorder != rootValue && startInorder != endInorder)
	{
		++startInorder;
	}
	if (startInorder == endInorder && *startInorder != rootValue) throw std::exception("Invalid input");

	int leftNodeNum = startInorder - startInorderOriginal;
	int rightNodeNum = endInorder - startInorder;

	if (leftNodeNum > 0) {
		pRoot->m_pLeft = ConstructBinaryTreeCore(startPreorder + 1, startPreorder + leftNodeNum, startInorderOriginal, startInorder - 1);
	}
	if (rightNodeNum > 0) {
		pRoot->m_pRight = ConstructBinaryTreeCore(startPreorder + leftNodeNum + 1, endPreorder, startInorder + 1, endInorder);
	}

	return pRoot;
}

void ConstructBinaryTree(PBINARYTREENODE* pRootAddr, int preorder[], int inorder[], int nodeNum)
{
	if (*pRootAddr != nullptr || preorder == nullptr || inorder == nullptr || nodeNum == 0) return;
	*pRootAddr = ConstructBinaryTreeCore(preorder, preorder - 1 + nodeNum, inorder, inorder - 1 + nodeNum);
}


// ====================测试代码====================
/*
1. ordinary binary tree
2. full binary tree
3. only left
4. only right
5. one child
6. null
7. wrong input
*/
void Test(const char* testName, int* preorder, int* inorder, int length)
{
    if (testName != nullptr)
        printf("%s begins:\n", testName);

    printf("The preorder sequence is: ");
    for (int i = 0; i < length; ++i)
        printf("%d ", preorder[i]);
    printf("\n");

    printf("The inorder sequence is: ");
    for (int i = 0; i < length; ++i)
        printf("%d ", inorder[i]);
    printf("\n");

    try
    {
        PBINARYTREENODE pRoot =  nullptr;
        ConstructBinaryTree(&pRoot, preorder, inorder, length);
        PrintBinaryTree(pRoot);
        printf("\n");
        DestoryBinaryTree(pRoot);

    }
    catch (std::exception& exception)
    {
        printf("Invalid Input.\n");
    }
}

// 普通二叉树
//              1
//           /     \
//          2       3  
//         /       / \
//        4       5   6
//         \         /
//          7       8
void Test1()
{
    const int length = 8;
    int preorder[length] = { 1, 2, 4, 7, 3, 5, 6, 8 };
    int inorder[length] = { 4, 7, 2, 1, 5, 3, 8, 6 };
    int expect[length] = { 4, 7, 2, 1, 5, 3, 8, 6 };

    Test("Test1", preorder, inorder, length);
}

// 所有结点都没有右子结点
//            1
//           / 
//          2   
//         / 
//        3 
//       /
//      4
//     /
//    5
void Test2()
{
    const int length = 5;
    int preorder[length] = { 1, 2, 3, 4, 5 };
    int inorder[length] = { 5, 4, 3, 2, 1 };
    Test("Test2", preorder, inorder, length);
}

// 所有结点都没有左子结点
//            1
//             \ 
//              2   
//               \ 
//                3 
//                 \
//                  4
//                   \
//                    5
void Test3()
{
    const int length = 5;
    int preorder[length] = { 1, 2, 3, 4, 5 };
    int inorder[length] = { 1, 2, 3, 4, 5 };

    Test("Test3", preorder, inorder, length);
}

// 树中只有一个结点
void Test4()
{
    const int length = 1;
    int preorder[length] = { 1 };
    int inorder[length] = { 1 };

    Test("Test4", preorder, inorder, length);
}

// 完全二叉树
//              1
//           /     \
//          2       3  
//         / \     / \
//        4   5   6   7
void Test5()
{
    const int length = 7;
    int preorder[length] = { 1, 2, 4, 5, 3, 6, 7 };
    int inorder[length] = { 4, 2, 5, 1, 6, 3, 7 };

    Test("Test5", preorder, inorder, length);
}

// 输入空指针
void Test6()
{
    Test("Test6", nullptr, nullptr, 0);
}

// 输入的两个序列不匹配
void Test7()
{
    const int length = 7;
    int preorder[length] = { 1, 2, 4, 5, 3, 6, 7 };
    int inorder[length] = { 4, 2, 8, 1, 6, 3, 7 };

    Test("Test7: for unmatched input", preorder, inorder, length);
}

int main()
{
	/*PBINARYTREENODE pRoot = nullptr;
	int preorder[5] = { 1, 2, 4, 3, 5 };
	int inorder[5] = { 4, 2, 1, 3, 5 };

	ConstructBinaryTree(&pRoot, preorder, inorder, 5);
	printf("Construct tree:\n");
	PrintBinaryTree(pRoot);
	printf("\n");

	printf("Expect tree:\n");
	printf("4 2 1 3 5\n");*/

    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
	
	return 0;
}