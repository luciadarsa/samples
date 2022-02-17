#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void TestAddRemove()
{
	List* pList = CreateList();
	assert(pList);

	AddHead(pList, 1);
	ListNode* pListNode = RemoveHead(pList);
	assert(pListNode->id == 1);
	DestroyNode(&pListNode);
	PrintList(__FUNCTION__, pList);
	DestroyList(&pList);
}

void TestAddHead(int numElements)
{
	List* pList = CreateList();
	assert(pList);

	for (int i = 0; i < numElements; i++)
	{
		AddHead(pList, i);
	}

	ListNode* pNode = pList->pHead;
	for (int i = numElements-1; i >= 0; i--)
	{
		assert(pNode->id == i);
		pNode = pNode->pNext;
	}
	int count = ListCount(pList);
	assert(count == numElements);

	PrintList(__FUNCTION__, pList);
	DestroyList(&pList);
}

void TestAddTail(int numElements)
{
	List* pList = CreateList();
	assert(pList);

	for (int i = 0; i < numElements; i++)
	{
		AddTail(pList, i);
	}

	ListNode* pNode = pList->pHead;
	for (int i = 0; i < numElements; i++)
	{
		assert(pNode->id == i);
		pNode = pNode->pNext;
	}
	int count = ListCount(pList);
	assert(count == numElements);

	PrintList(__FUNCTION__, pList);
	DestroyList(&pList);
}


void TestRemoveHead(int numElements)
{
	List* pList = CreateList();
	assert(pList);

	for (int i = 0; i < numElements; i++)
	{
		AddHead(pList, i);
	}

	int index = numElements-1;
	while (pList->pHead)
	{
		ListNode* pNode = RemoveHead(pList);
		assert(pNode->id == index);
		--index;
		free(pNode);
	}

	int count = ListCount(pList);
	assert(count == 0);

	PrintList(__FUNCTION__, pList);
	DestroyList(&pList);
}

void TestRemoveTail(int numElements)
{
	List* pList = CreateList();
	assert(pList);

	for (int i = 0; i < numElements; i++)
	{
		AddHead(pList, i);
	}

	int index = 0;
	while (pList->pHead)
	{
		ListNode* pNode = RemoveTail(pList);
		assert(pNode->id == index);
		++index;
		free(pNode);
	}

	int count = ListCount(pList);
	assert(count == 0);

	PrintList(__FUNCTION__, pList);
	DestroyList(&pList);
}


void TestRemoveNodeExists(int numElements, int id)
{
	List* pList = CreateList();
	assert(pList);

	for (int i = 0; i < numElements; i++)
	{
		AddHead(pList, i);
	}

	ListNode* pNode = RemoveNode(pList, id);
	assert(pNode != nullptr);
	assert(pNode->id == id);
	free(pNode);

	int count = ListCount(pList);
	assert(count == numElements - 1);

	PrintList(__FUNCTION__, pList);
	DestroyList(&pList);
}


void TestRemoveNodeDoesntExist(int numElements, int id)
{
	List* pList = CreateList();
	assert(pList);

	for (int i = 0; i < numElements; i++)
	{
		AddHead(pList, i);
	}

	ListNode* pNode = RemoveNode(pList, id);
	assert(pNode == nullptr);

	int count = ListCount(pList);
	assert(count == numElements);

	PrintList(__FUNCTION__,  pList);
	DestroyList(&pList);
}

int main(void)
{
	TestAddRemove();
	TestAddHead(1);
	TestAddHead(5);
	TestAddTail(1);
	TestAddTail(5);
	TestRemoveHead(1);
	TestRemoveHead(5);
	TestRemoveTail(1);
	TestRemoveTail(5);
	TestRemoveNodeExists(1, 0);
	TestRemoveNodeExists(5, 2);
	TestRemoveNodeExists(5, 2);
	TestRemoveNodeExists(5, 4);
	TestRemoveNodeExists(5, 0);
	TestRemoveNodeDoesntExist(1, 1);
	TestRemoveNodeDoesntExist(5, 6);

	return 1;
}