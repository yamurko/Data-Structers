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
	vector(int n, const int& t = int()) : vector()
	{
		for (int i = 0; i < n; i++)
		{
			push_back(t);
		}
	}
	vector(const int* first, const int* last) : vector()
	{
		while (first != last)
		{
			push_back(*first++);
		}
	}
	vector(const vector& v)
	{
		*this = v;
	}
	~vector() { reset(); }
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
	void erase(const int* first_indis, const int* last_indis)
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

	vector& assign(const vector& v)
	{
		reset(v.size(), v.cap());
		data = new int[capacity];
		for (int i = 0; i < size(); i++)
		{
			data[i] = v.data[i];
		}
		return *this;
	}
	vector& operator= (const vector& v)
	{
		return assign(v);
	}
};

int main() {
	vector v;
	vector v2(5);
	vector v3(3);
	vector v4(3,1);
	int dizi[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector v5(dizi + 2, dizi + 8);
	vector v6(8, 4);
	vector v7(&v6[2], &v6[6]);
	cout << "Size of v: " << v.size() << endl;
	cout << "Capacity of v: " << v.cap() << endl;

	cout << "Size of v2: " << v2.size() << endl;
	cout << "Capacity of v2: " << v2.cap() << endl;

	int* begin3 = v3.begin();
	int* end3 = v3.end();

	cout << "v3: ";
	while (begin3 != end3)
	{
		cout << *begin3 << " ";
		begin3++;
	}
	cout << endl;

	int* begin4 = v4.begin();
	int* end4 = v4.end();

	cout << "v4: ";
	while (begin4 != end4)
	{
		cout << *begin4 << " ";
		begin4++;
	}
	cout << endl;

	int* begin5 = v5.begin();
	int* end5 = v5.end();

	cout << "v5: ";
	while (begin5 != end5)
	{
		cout << *begin5 << " ";
		begin5++;
	}
	cout << endl;

	int* begin7 = v7.begin();
	int* end7 = v7.end();

	cout << "v7: ";
	while (begin7 != end7)
	{
		cout << *begin7 << " ";
		begin7++;
	}
	cout << endl;

	cout << endl << endl << endl;
	return 0;
}