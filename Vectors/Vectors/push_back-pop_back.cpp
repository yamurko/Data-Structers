#include<iostream>
using namespace std;

class vector
{
	int* data;
	int capacity;
	int index;

public:
	vector() : data(NULL), capacity(1), index(0)
	{ data = new int[capacity]; }

	int cap() const { return capacity; }

	int size() const { return index; }

	void push_back(const int& value) { data[index++] = value; }

	void pop_back() { index--; }

	bool isEmpty() const { return size() == 0; }

	int front() const 
	{
		if(isEmpty())
			throw ("Error! Vector is empty.");
		return data[0];
	}

	int back() const
	{
		if (isEmpty())
			throw ("Error! Vector is empty.");
		return data[index - 1];
	}
};

int main()
{
	vector v;
	try
	{
		v.front();
		cout << v.cap() << " " << v.size() << endl;
		v.push_back(2);
		cout << v.cap() << " " << v.size() << endl;
		v.push_back(3);
		cout << v.cap() << " " << v.size() << endl;
		v.pop_back();
		cout << v.cap() << " " << v.size() << endl;
	}
	catch (const char* exception)
	{
		cout << exception;
	}
	

	return 0;
}

