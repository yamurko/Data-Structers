#include<iostream>
using namespace std;

class vector
{
	int* data;
	int* tmp;
	int capacity;
	int index;
	void growth() {
		if (size() >= cap())
		{
			capacity *= 2;
			tmp = new int[capacity];

			for (int i = 0; i < size(); i++)
			{
				tmp[i] = data[i];
			}
			delete[] data;
			data = tmp;
		}
	}

public:
	vector() : data(NULL), capacity(1), index(0) {
		data = new int[capacity];
	}
	int cap() const { return capacity; }
	int size() const { return index; }
	void push_back(const int& value) {
		growth();
		data[index++] = value;
	}
	void pop_back() { index--; }
	bool isEmpty() const { return size() == 0; }
	int front() const
	{
		if (isEmpty())
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
	cout << "Size: " << v.size() << endl;
	cout << "Capacity: " << v.cap() << endl;
	v.push_back(8);
	cout << "Size: " << v.size() << endl;
	cout << "Capacity: " << v.cap() << endl;
	v.push_back(75);
	cout << "Size: " << v.size() << endl;
	cout << "Capacity: " << v.cap() << endl;
	v.push_back(86);
	cout << "Size: " << v.size() << endl;
	cout << "Capacity: " << v.cap() << endl;
	v.pop_back();
	cout << "Size: " << v.size() << endl;
	cout << "Capacity: " << v.cap() << endl;

	try
	{
		cout << "Size: " << v.size() << endl;
		cout << "Capacity: " << v.cap() << endl;
		v.push_back(8);
		cout << "Size: " << v.size() << endl;
		cout << "Capacity: " << v.cap() << endl;
		v.push_back(75);
		cout << "Size: " << v.size() << endl;
		cout << "Capacity: " << v.cap() << endl;
		v.push_back(86);
		cout << "Size: " << v.size() << endl;
		cout << "Capacity: " << v.cap() << endl;
		v.pop_back();
		cout << "Size: " << v.size() << endl;
		cout << "Capacity: " << v.cap() << endl;
	}
	catch (const char* exception)
	{
		cout << exception;
	}
	return 0;
}

