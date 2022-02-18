#pragma once

class SampleClass
{
public:
	SampleClass(int identifier) { id = identifier;  }

	bool operator==(const SampleClass& other) const
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
