#include <stdio.h>
#include <assert.h>
#include "SampleClass.h"
#include "list.h"

void PrintList(const char* functionName, List<SampleClass>& list)
{
	printf("%s: ", functionName);
	for (auto pListNode = list.front(); pListNode; pListNode = pListNode->next())
	{
		printf("%d, ", (*pListNode)->id);
	}
	printf("\n");
}


void TestAddRemove()
{
	List<SampleClass> list;
	SampleClass sample(1);

	list.push_front(sample);
	ListNode<SampleClass>* pListNode = list.pop_front();
	assert((*pListNode)->id == 1);
	delete pListNode;
}

void TestAddHead(int numElements)
{
	List<SampleClass> list;

	for (int i = 0; i < numElements; i++)
	{
		SampleClass sample(i);
		list.push_front(sample);
	}

	auto pListNode = list.front();
	for (int i = numElements - 1; i >= 0; i--)
	{
		assert((*pListNode)->id == i);
		pListNode = pListNode->next();
	}

	assert(list.size() == numElements);

	PrintList(__FUNCTION__, list);
}

void TestAddTail(int numElements)
{
	List<SampleClass> list;

	for (int i = 0; i < numElements; i++)
	{
		SampleClass sample(i);
		list.push_back(sample);
	}

	auto pListNode = list.front();
	for (int i = 0; i < numElements; i++)
	{
		assert((*pListNode)->id == i);
		pListNode = pListNode->next();
	}

	assert(list.size() == numElements);

	PrintList(__FUNCTION__, list);
}


void TestRemoveHead(int numElements)
{
	List<SampleClass> list;

	for (int i = 0; i < numElements; i++)
	{
		SampleClass sample(i);
		list.push_front(sample);
	}

	int index = numElements - 1;
	while (list.size() > 0)
	{
		auto pListNode = list.pop_front();
		assert((*pListNode)->id == index);
		--index;
	}
	assert(list.size() == 0);

	PrintList(__FUNCTION__, list);
}

void TestRemoveTail(int numElements)
{
	List<SampleClass> list;

	for (int i = 0; i < numElements; i++)
	{
		SampleClass sample(i);
		list.push_front(sample);
	}

	int index = 0;
	while (list.size() > 0)
	{
		auto pListNode = list.pop_back();
		assert((*pListNode)->id == index);
		++index;
	}
	assert(list.size() == 0);

	PrintList(__FUNCTION__, list);
}

void TestRemoveNodeExists(int numElements, int id)
{
	List<SampleClass> list;

	for (int i = 0; i < numElements; i++)
	{
		SampleClass sample(i);
		list.push_front(sample);
	}

	SampleClass sampleToFind(id);
	auto pListNode = list.find(sampleToFind);

	assert(pListNode != nullptr);
	assert((*pListNode)->id == id);
	list.erase(pListNode);

	assert(list.size() == numElements - 1);

	PrintList(__FUNCTION__, list);
}


void TestRemoveNodeDoesntExist(int numElements, int id)
{
	List<SampleClass> list;

	for (int i = 0; i < numElements; i++)
	{
		SampleClass sample(i);
		list.push_front(sample);
	}

	SampleClass sampleToFind(id);
	auto pListNode = list.find(sampleToFind);
	assert(pListNode == nullptr);

	assert(list.size() == numElements);

	PrintList(__FUNCTION__, list);
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
