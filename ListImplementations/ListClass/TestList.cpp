#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void TestAddRemove()
{
	List* pList = new List();
	assert(pList);

	pList->AddHead(1);
	ListNode* pListNode = pList->RemoveHead();
	assert(pListNode->id == 1);
	delete pListNode;
	pList->Print(__FUNCTION__);
	delete pList;
}

void TestAddHead(int numElements)
{
	List *pList = new List();
	assert(pList);

	for (int i = 0; i < numElements; i++)
	{
		pList->AddHead(i);
	}

	ListNode* pNode = pList->GetHead();
	for (int i = numElements - 1; i >= 0; i--)
	{
		assert(pNode->id == i);
		pNode = pNode->pNext;
	}
	assert(pList->Count() == numElements);

	pList->Print(__FUNCTION__);
	delete pList;
}

void TestAddTail(int numElements)
{
	List *pList = new List();
	assert(pList);

	for (int i = 0; i < numElements; i++)
	{
		pList->AddTail(i);
	}

	ListNode* pNode = pList->GetHead();
	for (int i = 0; i < numElements; i++)
	{
		assert(pNode->id == i);
		pNode = pNode->pNext;
	}
	assert(pList->Count() == numElements);

	pList->Print(__FUNCTION__);
	delete pList;
}


void TestRemoveHead(int numElements)
{
	List *pList = new List();
	assert(pList);

	for (int i = 0; i < numElements; i++)
	{
		pList->AddHead(i);
	}

	int index = numElements - 1;
	while (pList->GetHead())
	{
		ListNode* pNode = pList->RemoveHead();
		assert(pNode->id == index);
		--index;
		delete pNode;
	}

	assert(pList->Count() == 0);

	pList->Print(__FUNCTION__);
	delete pList;
}

void TestRemoveTail(int numElements)
{
	List *pList = new List();
	assert(pList);

	for (int i = 0; i < numElements; i++)
	{
		pList->AddHead(i);
	}

	int index = 0;
	while (pList->GetHead())
	{
		ListNode* pNode = pList->RemoveTail();
		assert(pNode->id == index);
		++index;
		delete pNode;
	}

	assert(pList->Count() == 0);

	pList->Print(__FUNCTION__);
	delete pList;
}


void TestRemoveNodeExists(int numElements, int id)
{
	List *pList = new List();
	assert(pList);

	for (int i = 0; i < numElements; i++)
	{
		pList->AddHead(i);
	}

	ListNode* pNode = pList->RemoveNode(id);
	assert(pNode != nullptr);
	assert(pNode->id == id);
	delete pNode;

	assert(pList->Count() == numElements - 1);

	pList->Print(__FUNCTION__);
	delete pList;
}


void TestRemoveNodeDoesntExist(int numElements, int id)
{
	List *pList = new List();
	assert(pList);

	for (int i = 0; i < numElements; i++)
	{
		pList->AddHead(i);
	}

	ListNode* pNode = pList->RemoveNode(id);
	assert(pNode == nullptr);

	assert(pList->Count() == numElements);

	pList->Print(__FUNCTION__);
	delete pList;
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