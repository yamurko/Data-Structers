#include<iostream>
using namespace std;

class vector
{
	int* data;
	int capacity;
	int index;

public:
	vector() : data(NULL), capacity(1), index(0)
	{
		data = new int[capacity];
	}
	int cap() const
	{
		return capacity;
	}
	int size() const
	{
		return index;
	}

};

int main()
{
	vector v;

	cout << v.cap() << " " << v.size();

	return 0;
}

