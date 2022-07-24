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
				tmp[i] = data[i];
			delete[] data;
			data = tmp;
		}
	}
	void shrink()
	{
		if (size() <= (cap() / 2))
		{
			capacity /= 2;
			tmp = new int[capacity];
			for (int i = 0; i < size(); i++)
				tmp[i] = data[i];
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
	bool isEmpty() const { return size() == 0; }
	void pop_back() { 
		if (isEmpty())
		{
			throw ("Error! This array is empty.");
		}
		index--; 
		shrink();
	}
};

int main()
{
	vector v;
	try
	{
		cout << "Size: " << v.size() << endl;
		cout << "Capacity: " << v.cap() << endl;
		v.push_back(8);
		v.push_back(26);
		v.push_back(125);
		v.push_back(96);
		v.push_back(7589);
		v.push_back(1546);
		cout << "Size: " << v.size() << endl;
		cout << "Capacity: " << v.cap() << endl;
		v.pop_back();
		cout << "Size: " << v.size() << endl;
		cout << "Capacity: " << v.cap() << endl;
		v.pop_back();
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

