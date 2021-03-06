#include <list>
#include "SampleClass.h"
#include <assert.h>

void PrintList(const char* functionName, std::list<SampleClass>& list)
{
	printf("%s: ", functionName);
	auto it = list.begin();
	for (auto it = list.begin(); it != list.end(); it++)
	{
		printf("%d, ", (*it).id);
	}
	printf("\n");
}

void TestAddRemove()
{
	std::list<SampleClass> list;

	SampleClass sample(1);
	list.push_front(sample);
	auto const & front = list.begin();
	assert((*front).id == 1);
	list.pop_front();
	PrintList(__FUNCTION__, list);
}

void TestAddHead(int numElements)
{
	std::list<SampleClass> list;

	for (int i = 0; i < numElements; i++)
	{
		SampleClass sample(i);
		list.push_front(sample);
	}

	auto it = list.begin();
	for (int i = numElements - 1; i >= 0; i--)
	{
		assert((*it).id == i);
		++it;
	}

	assert(list.size() == numElements);

	PrintList(__FUNCTION__, list);
}

void TestAddTail(int numElements)
{
	std::list<SampleClass> list;

	for (int i = 0; i < numElements; i++)
	{
		SampleClass sample(i);
		list.push_back(sample);
	}

	auto it = list.begin();
	for (int i = 0; i < numElements; i++)
	{
		assert((*it).id == i);
		++it;
	}

	assert(list.size() == numElements);

	PrintList(__FUNCTION__, list);
}


void TestRemoveHead(int numElements)
{
	std::list<SampleClass> list;

	for (int i = 0; i < numElements; i++)
	{
		SampleClass sample(i);
		list.push_front(sample);
	}

	int index = numElements - 1;
	while (list.size() > 0)
	{
		auto const & head = list.front();
		assert(head.id == index);
		list.pop_front();
		--index;
	}
	assert(list.size() == 0);

	PrintList(__FUNCTION__, list);
}

void TestRemoveTail(int numElements)
{
	std::list<SampleClass> list;

	for (int i = 0; i < numElements; i++)
	{
		SampleClass sample(i);
		list.push_front(sample);
	}

	int index = 0;
	while (list.size() > 0)
	{
		auto const & tail = list.back();
		assert(tail.id == index);
		list.pop_back();
		++index;
	}
	assert(list.size() == 0);

	PrintList(__FUNCTION__, list);
}


void TestRemoveNodeExists(int numElements, int id)
{
	std::list<SampleClass> list;

	for (int i = 0; i < numElements; i++)
	{
		SampleClass sample(i);
		list.push_front(sample);
	}

	auto it = std::find(list.begin(), list.end(), id);

	assert(it != list.end());
	assert((*it).id == id);
	list.erase(it);

	assert(list.size() == numElements - 1);

	PrintList(__FUNCTION__, list);
}


void TestRemoveNodeDoesntExist(int numElements, int id)
{
	std::list<SampleClass> list;

	for (int i = 0; i < numElements; i++)
	{
		SampleClass sample(i);
		list.push_front(sample);
	}

	auto it = std::find(list.begin(), list.end(), id);
	assert(it == list.end());

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