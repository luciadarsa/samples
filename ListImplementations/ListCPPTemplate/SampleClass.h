#pragma once

class SampleClass
{
public:
	SampleClass(int val)
	{ 
	   id = val; 
	}

	~SampleClass() 
	{ 
	}

	bool operator==(const SampleClass& other) const
	{
		return id == other.id;
	}

	bool operator==(int otherId) const
	{
		return id == otherId;
	}

	int id;
};

