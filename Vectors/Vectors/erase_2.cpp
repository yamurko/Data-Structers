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
	void swap(int& x, int& y)
	{
		int tmp = x;
		x = y;
		y = tmp;
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
	void pop_back() {
		index--;
		shrink();
	}
	int* begin() const { return data; }
	int* end() const { return data + size(); }
	int& at(int ind) {
		if (ind >= 0 && ind <= size())
			return data[ind];
	}
	int& operator[](int ind) { return at(ind); }
	void clear() {
		reset();
		data = new int[capacity];
	}
	void insert(const int* indis, const int& value) {
		if (indis <= end() && indis >= begin()) {
			int nindis = indis - begin();
			push_back(value);
			for (int i = size() - 1; i > nindis; i--) {
				swap(data[i], data[i - 1]);
			}
		}
	}
	void insert(const int* indis, int n, const int& value)
	{
		if (indis <= end() && indis >= begin()) {
			int nindis = indis - begin();
			for (int i = 0; i < n; i++)
			{
				insert(begin() + nindis + i, value);
			}
		}
	}
	void insert(const int* indis, const int* first, const int* last)
	{
		int nindis = indis - begin();
		while (first != last) {
			insert(begin() + nindis++, *first++);
		}
	}
	void erase(const int* indis)
	{
		if (indis <= end() && indis >= begin()) {
			int nindis = indis - begin();
			for (int i = nindis; i < size() - 1; i++) {
				swap(data[i], data[i + 1]);
			}
			pop_back();
		}
	}
	void erase(const int* first_indis,const int* last_indis)
	{
		if (last_indis <= end() && first_indis >= begin()) {
			int first_nindis = first_indis - begin();
			int last_nindis = end() - last_indis;
			while (first_nindis != last_nindis)
			{
				erase(begin() + first_nindis++);
			}
		}
	}
};

int main()
{
	vector v;
	v.push_back(15);
	v.push_back(78);
	v.push_back(658);
	v.push_back(65);
	v.push_back(898);
	v.push_back(222);

	int* begin = v.begin();
	int* end = v.end();
	while (begin != end) {
		cout << *begin << " ";
		begin++;
	}
	cout << endl;

	v.erase(&v[1],&v[3]);
	begin = v.begin();
	end = v.end();
	while (begin != end) {
		cout << *begin << " ";
		begin++;
	}
	cout << endl;


	cout << endl << endl << endl;
	return 0;
}

