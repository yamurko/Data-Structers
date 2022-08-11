#include<iostream>

using namespace std;

template <class T>
class Node
{
public:
	T data;
	Node<T>* next;
	Node(const T& data = T(), Node<T>* next = NULL) : data(data), next(next) { }
};

template <class T>
class List
{
	Node<T>* root;
	Node<T>* tail;
	int length;
	Node<T>* findPrev(Node<T>* pos)
	{
		Node<T>* prev = root;
		Node<T>* stop = end();
		while (prev != stop && prev->next != pos)
			prev = prev->next;
		return prev;
	}
public:
	List()
	{
		length = 0;
		root = new Node<T>();
		tail = root;
		tail->next = new Node<T>();
	}
	List(int n, const T& value = 0) : List<T>()
	{
		insert(end(), n, value);
	}
	List(Node<T>* first, Node<T>* last) : List<T>()
	{
		while (first != last)
		{
			insert(end(), first->data);
			first = first->next;
		}
	}
	List(const List& rhs) : List<T>(rhs.begin(), rhs.end()) { }
	~List()
	{
		clear();
		delete tail->next;
		delete tail;
	}

	Node<T>* begin() const { return root->next; }
	Node<T>* end() const { return tail->next; }
	bool isEmpty() const { return begin() == end(); }

	int size()
	{
		/*int counter = 0;
		Node<T>* tmp = begin();
		while (tmp != end())
		{
			tmp = tmp->next;
			counter++;
		}
		return counter;*/
		return length;
	}

	void push_back(const T& value)
	{
		try
		{
			insert(end(), value);
		}
		catch (const char* exception)
		{
			throw "List is empty";
		}
	}
	void push_front(const T& value)
	{
		try
		{
			insert(begin(), value);
		}
		catch (const char* exception)
		{
			throw "List is empty";
		}
	}
	void insert(Node<T>* ind, const T& value)
	{
		if (ind == end())
		{
			tail->next = new Node<T>(value, end());
			tail = tail->next;
		}
		else
		{
			Node<T>* tmp = findPrev(ind);
			if (tmp == end())
				throw "Pos is not in list.";
			tmp->next = new Node<T>(value, tmp->next);
		}
		length++;
	}
	void insert(Node<T>* ind, int n, const T& value)
	{
		for (int i = 0; i < n; i++)
		{
			insert(ind, value);
		}
	}
	void insert(Node<T>* pos, Node<T>* first, Node<T>* last)
	{
		while (first != last)
		{
			insert(pos, first->data);
			first = first->next;
		}
	}
	void pop_back()
	{
		erase(end());
	}
	void pop_front()
	{
		erase(begin());
	}
	void erase(Node<T>* ind)
	{
		if (isEmpty())
			throw "List is empty";
		Node<T>* prev = root;
		if (ind == end() || ind == tail)
		{
			ind = tail;
			prev = findPrev(ind);
			prev->next = ind->next;
			tail = prev;
		}
		else
		{
			prev = findPrev(ind);
			if (prev == end())
				throw "Pos is not in list.";
			prev->next = ind->next;
		}
		delete ind;
		length--;
	}
	void erase(Node<T>* first, Node<T>* last)
	{
		Node<T>* tmp;
		while (first != last)
		{
			tmp = first;
			first = first->next;
			erase(tmp);
		}
	}
	void clear()
	{
		erase(begin(), end());
	}
	T front()
	{
		if (isEmpty())
			throw "List is empty";
		return begin()->data;
	}
	T last()
	{
		if (isEmpty())
			throw "List is empty";
		return tail->data;
	}
	Node<T>* find(const T& value) const
	{
		Node<T>* tmp = begin();
		Node<T>* stop = end();
		while (tmp != stop && tmp->data != value)
		{
			tmp = tmp->next;
			if (tmp == end())
			{
				cout << "Value is not in list.";
				break;
			}
		}
		return tmp;
	}
	Node<T>* find(Node<T>* pos, const T& value) const
	{
		Node<T>* tmp = pos;
		Node<T>* stop = end();
		while (tmp != stop && tmp->data != value)
			tmp = tmp->next;
		return tmp;
	}
	List<T>& assign(const List<T>& rhs)
	{
		clear();
		Node<T>* tmp = rhs.begin();
		while (tmp != rhs.end())
		{
			push_back(tmp->data);
			tmp = tmp->next;
		}
		return *this;
	}
	List<T>& operator=(const List<T>& rhs)
	{
		return assign(rhs);
	}
	void print() const
	{
		Node<T>* first = begin();
		while (first != end())
		{
			cout << first->data << " ";
			first = first->next;
		}
		cout << endl;
	}
};

class Complex
{
	double re, im;
public:
	Complex(double re = 0.0, double im = 0.0) : re(re), im(im) { }
	friend ostream& operator<<(ostream& out, Complex& c)
	{
		out << c.re << " , " << c.im;
		return out;
	}
};

int main()
{
	List<char> l1(4, 'a');
	List<string> l2(4, "hello");
	l1.print();
	l2.print();
	List<Complex> l3(2, 301);
	l3.push_back(Complex(4, 8));
	l3.print();
	Complex tmp;
	tmp = l3.front();
	cout << "Front: " << tmp << endl;
	tmp = l3.last();
	cout << "Last: " << tmp << endl;
	return 0;
}