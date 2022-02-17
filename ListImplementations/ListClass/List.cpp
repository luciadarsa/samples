#include <stdlib.h>
#include <stdio.h>
#include "list.h"

List::~List()
{
	ListNode* pHead;
	while (pHead = RemoveHead())
	{
		delete pHead;
	}
}

ListNode* List::AddHead(int id)
{
	ListNode* pNewNode = new ListNode(id);
	if (pNewNode)
	{
		pNewNode->pNext = _pHead;
		if (_pHead)
		{
			_pHead->pPrev = pNewNode;
		}
		else
		{
			assert(_pTail == nullptr);
			_pTail = pNewNode;
		}
		_pHead = pNewNode;
		++_count;
	}
	return pNewNode;
}


ListNode* List::AddTail(int id)
{
	ListNode* pNewNode = new ListNode(id);
	if (pNewNode)
	{
		pNewNode->pPrev = _pTail;
		if (_pTail)
		{
			_pTail->pNext = pNewNode;
		}
		else
		{
			assert(_pHead == nullptr);
			_pHead = pNewNode;
		}
		_pTail = pNewNode;
		++_count;
	}
	return pNewNode;
}


ListNode* List::RemoveHead()
{
	return RemoveNode(_pHead);
}

ListNode* List::RemoveTail()
{
	return RemoveNode(_pTail);
}

ListNode* List::RemoveNode(int id)
{
	return RemoveNode(FindNode(id));
}

ListNode* List::RemoveNode(ListNode* pNode)
{
	if (pNode)
	{
		ListNode* pTmp = pNode->pPrev;
		if (pNode->pPrev)
		{
			pNode->pPrev->pNext = pNode->pNext;
		}
		else
		{
			_pHead = pNode->pNext;
		}

		if (pNode->pNext)
		{
			pNode->pNext->pPrev = pTmp;
		}
		else
		{
			_pTail = pNode->pPrev;
		}
		--_count;
		pNode->pPrev = nullptr;
		pNode->pNext = nullptr;
	}
	return pNode;
}


ListNode* List::FindNode(int id)
{
	ListNode* pPrev = nullptr;
	ListNode* pNode = _pHead;
	while (pNode && pNode->id != id)
	{
		pPrev = pNode;
		pNode = pNode->pNext;
	}
	return pNode;
}

void List::Print(const char* functionName)
{
	printf("%s: ", functionName);
	ListNode* pNode = _pHead;
	while (pNode)
	{
		printf("%d, ", pNode->id);
		pNode = pNode->pNext;
	}
	printf("\n");
}