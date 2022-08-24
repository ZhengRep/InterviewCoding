#include<iostream>
#include<stack>

typedef struct _LIST_NODE_ {
	int Value;
	_LIST_NODE_* NextNode;
}LIST_NODE, *PLIST_NODE;

void PrintListReversinglyByIterative(PLIST_NODE ListHead)
{
	if (ListHead == nullptr) return;

	PLIST_NODE pNode = ListHead;
	std::stack<PLIST_NODE> NodesPointerStack;
	while (pNode)
	{
		NodesPointerStack.push(pNode);
		pNode = pNode->NextNode;
	}

	printf("Print List Reversingly:\n");
	while (!NodesPointerStack.empty())
	{
		printf("%d ", NodesPointerStack.top()->Value);
		NodesPointerStack.pop();
	}
}


/*
Test case:
1. empty list
2. long?
*/