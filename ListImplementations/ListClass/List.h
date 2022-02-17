#pragma once
#include <assert.h>

//
// List class with doubly linked elements
//

class ListNode
{
public:
	ListNode(int identifier)
	{ 
		id = identifier;
	}

	~ListNode()
	{
		assert(pNext == nullptr);
		assert(pPrev == nullptr);
	}

	int id;
	ListNode* pNext = nullptr;
	ListNode* pPrev = nullptr;
};

class List
{
public:
	List() {}
	~List();

	ListNode* AddHead(int id);
	ListNode* AddTail(int id);
	ListNode* RemoveHead();
	ListNode* RemoveTail();
	ListNode* FindNode(int id);
	ListNode* RemoveNode(int id);
	ListNode* GetHead() { return _pHead; }
	ListNode* GetTail() { return _pTail; }
	int Count()         { return _count;  }
	void Print(const char* functionName);			// debugging functionality

protected:
	ListNode* RemoveNode(ListNode* pNode);

	ListNode* _pHead = nullptr;
	ListNode* _pTail = nullptr;
	int _count = 0;
};

