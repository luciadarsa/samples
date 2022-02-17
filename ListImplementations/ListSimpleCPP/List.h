#pragma once

//
// List structure with singly linked elements
//
struct ListNode
{
	int id;
	ListNode* pNext;
};

struct List
{
	ListNode* pHead;
};

List* CreateList();
bool DestroyList(List** ppList);
bool DestroyNode(ListNode** ppNode);

ListNode* AddHead(List *pList, int id);
ListNode* AddTail(List* pList, int id);
ListNode* RemoveHead(List* pList);
ListNode* RemoveTail(List* pList);
ListNode* RemoveNode(List* pList, int id);
int ListCount(List* pList);
ListNode* GetHead(List* pList);
ListNode* GetTail(List* pTail);

void PrintList(const char* functionName, List* pList);			// debugging functionality

