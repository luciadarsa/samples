#pragma once
#include <assert.h>

//
// Templated list class with doubly linked elements
//

template <class T> 
class ListNode
{
	template<class> friend class List;

public:
	ListNode(T& value) :
		_value(value)
	{ 
	}

	~ListNode()
	{
		assert(_pNext == nullptr);
		assert(_pPrev == nullptr);
	}

	T& value()
	{
		return _value;
	}

	ListNode<T>* next() { return _pNext; }
	ListNode<T>* prev() { return _pPrev; }

protected:
	T _value;
	ListNode<T>* _pNext = nullptr;
	ListNode<T>* _pPrev = nullptr;
};

template <class T>
class List
{
public:
	List()
	{
	}

	~List()
	{
		ListNode<T>* pHead;
		while (pHead = pop_front())
		{
			delete pHead;
		}
	}

	ListNode<T>* push_front(T& val)
	{
		ListNode<T>* pNewNode = new ListNode<T>(val);
		if (pNewNode)
		{
			pNewNode->_pNext = _pHead;
			if (_pHead)
			{
				_pHead->_pPrev = pNewNode;
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

	ListNode<T>* push_back(T& val)
	{
		ListNode<T>* pNewNode = new ListNode<T>(val);
		if (pNewNode)
		{
			pNewNode->_pPrev = _pTail;
			if (_pTail)
			{
				_pTail->_pNext = pNewNode;
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

	ListNode<T>* pop_front()
	{
		return erase(_pHead);
	}

	ListNode<T>* pop_back()
	{
		return erase(_pTail);
	}

	ListNode<T>* find(T& val)
	{
		ListNode<T>* pPrev = nullptr;
		ListNode<T>* pListNode = _pHead;
		while (pListNode && !(pListNode->_value == val))
		{
			pPrev = pListNode;
			pListNode = pListNode->_pNext;
		}
		return pListNode;
	}

	ListNode<T>* erase(T& val)
	{
		return erase(find(val));
	}

	ListNode<T>* erase(ListNode<T>* pNode)
	{
		if (pNode)
		{
			ListNode<T>* pTmp = pNode->_pPrev;
			if (pNode->_pPrev)
			{
				pNode->_pPrev->_pNext = pNode->_pNext;
			}
			else
			{
				_pHead = pNode->_pNext;
			}

			if (pNode->_pNext)
			{
				pNode->_pNext->_pPrev = pTmp;
			}
			else
			{
				_pTail = pNode->_pPrev;
			}
			--_count;
			pNode->_pPrev = nullptr;
			pNode->_pNext = nullptr;
		}
		return pNode;
	}

	ListNode<T>* front()
	{ 
		return _pHead;
	}
	
	ListNode<T>* back() 
	{ 
		return _pTail;
	}
	
	int size()
	{ 
		return _count;
	}

protected:

	ListNode<T>* _pHead = nullptr;
	ListNode<T>* _pTail = nullptr;
	int _count = 0;
};

