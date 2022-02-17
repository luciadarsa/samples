#include <stdlib.h>
#include <stdio.h>
#include "list.h"

List* CreateList()
{
	List* pList = (List *)malloc(sizeof(List));
	if (pList)
	{
		pList->pHead = nullptr;
		return pList;
	}
	return nullptr;
}

bool DestroyList(List** ppList)
{
	List* pList = *ppList;
	if (pList)
	{
		while (pList->pHead)
		{
			ListNode* pHead = RemoveHead(pList);
			free(pHead);
		}
		free(pList);
		return true;
	}
	*ppList = nullptr;
	return false;
}

bool DestroyNode(ListNode** ppNode)
{
	ListNode* pNode = *ppNode;
	if (pNode->pNext)
	{
		return false;
	}
	free(pNode);
	*ppNode = nullptr;
	return true;
}

ListNode* CreateNode(int id)
{
	ListNode* pNode = (ListNode*)malloc(sizeof(ListNode));
	if (pNode)
	{
		pNode->id = id;
		pNode->pNext = nullptr;
	}
	return pNode;
}

ListNode* AddHead(List *pList, int id)
{
	ListNode* pNewNode = CreateNode(id);
	if (pNewNode)
	{
		pNewNode->pNext = pList->pHead;
		pList->pHead = pNewNode;
	}
	return pNewNode;
}


ListNode* AddTail(List* pList, int id)
{
	ListNode* pNewNode = CreateNode(id);
	if (pNewNode)
	{
		ListNode* pPrev = nullptr;
		ListNode* pCurrent = pList->pHead;
		while (pCurrent)
		{
			pPrev = pCurrent;
			pCurrent = pCurrent->pNext;
		}

		if (pPrev)
		{
			pPrev->pNext = pNewNode;
		}
		else
		{
			pList->pHead = pNewNode;
		}
	}
	return pNewNode;
}

ListNode* GetHead(List* pList)
{
	return pList->pHead;
}

ListNode *RemoveHead(List *pList)
{
	ListNode* pHead = pList->pHead;
	if (pHead)
	{
		pList->pHead = pHead->pNext;
	}
	return pHead;
}

ListNode* GetTail(List* pList)
{
	ListNode* pPrev = nullptr;
	ListNode* pTail = pList->pHead;
	while (pTail)
	{
		pPrev = pTail;
		pTail = pTail->pNext;
	}
	return pPrev;
}

ListNode *RemoveTail(List* pList)
{
	ListNode* pPrev = nullptr;
	ListNode* pTail = pList->pHead;
	while (pTail  &&  pTail->pNext)
	{
		pPrev = pTail;
		pTail = pTail->pNext;
	}

	if (pTail)
	{
		if (pPrev)
		{
			pPrev->pNext = nullptr;
		}
		else
		{
			pList->pHead = nullptr;
		}
	}
	return pTail;
}

ListNode* RemoveNode(List* pList, int id)
{
	ListNode* pPrev = nullptr;
	ListNode* pNode = pList->pHead;
	while (pNode  &&  pNode->id != id)
	{
		pPrev = pNode;
		pNode = pNode->pNext;
	}

	if (pNode)
	{
		if (pPrev)
		{
			pPrev->pNext = pNode->pNext;
		}
		else
		{
			pList->pHead = pNode->pNext;
		}
	}
	return pNode;
}

ListNode* FindNode(List* pList, int id)
{
	ListNode* pPrev = nullptr;
	ListNode* pNode = pList->pHead;
	while (pNode && pNode->id != id)
	{
		pPrev = pNode;
		pNode = pNode->pNext;
	}
	return pNode;
}

int ListCount(List* pList)
{
	int count = 0;
	ListNode* pNode = pList->pHead;
	while (pNode)
	{
		pNode = pNode->pNext;
		++count;
	}
	return count;
}

void PrintList(const char* functionName, List* pList)
{
	printf("%s: ", functionName);
	ListNode* pNode = pList->pHead;
	while (pNode)
	{
		printf("%d, ", pNode->id);
		pNode = pNode->pNext;
	}
	printf("\n");
}