#pragma once

class ListNode
{
public:
	ListNode(int identifier) { id = identifier;  }

	bool operator==(const ListNode& other) const
	{
		return id == other.id;
	}

	bool operator==(int otherId) const
	{
		return id == otherId;
	}

public:
	int id;
};
