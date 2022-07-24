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
	void reset(int index = 0, int capacity = 1)
	{
		delete[] data;
		data = NULL;
		this->index = index;
		this->capacity = capacity;
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
	int* begin() const
	{
		return data;
	}
	int* end() const
	{
		return data + size();
	}
	int& at(int ind)
	{
		if (ind >= 0 && ind <= size())
			return data[ind];
	}
	int& operator[](int ind)
	{
		return at(ind);
	}
	void clear()
	{
		reset();
		data = new int[capacity];
	}
};

int main()
{
	vector v;

	v.push_back(15);
	v.push_back(78);
	v.push_back(658);
	v.push_back(2698);
	v.push_back(458);
	v.push_back(56);

	int* begin = v.begin();
	int* end = v.end();

	while (begin != end)
	{
		cout << *begin << " - ";
		begin++;
	}
	cout << endl;

	v.clear();

	begin = v.begin();
	end = v.end();

	while (begin != end)
	{
		cout << *begin << " - ";
		begin++;
	}
	cout << endl << endl << endl;
	return 0;
}

