#include<iostream>

using namespace std;

class Node
{
public:
	int data;
	Node* next;
	Node(const int& data = int(), Node* next = NULL) : data(data), next(next) { }
};

class List
{
	Node* root;
	Node* tail;
	int length;
	Node* findPrev(Node* pos)
	{
		Node* prev = root;
		Node* stop = end();
		while (prev != stop && prev->next != pos)
			prev = prev->next;
		return prev;
	}
public:
	List()
	{
		length = 0;
		root = new Node();
		tail = root;
		tail->next = new Node();
	}
	List(int n, const int& value = 0) : List()
	{
		insert(end(), n, value);
	}
	List(Node* first, Node* last) : List()
	{
		while (first != last)
		{
			insert(end(), first->data);
			first = first->next;
		}
	}
	List(const List& rhs) : List(rhs.begin(), rhs.end()) { }
	~List()
	{
		clear();
		delete tail->next;
		delete tail;
	}

	Node* begin() const { return root->next; }
	Node* end() const { return tail->next; }
	bool isEmpty() const { return begin() == end(); }

	int size()
	{
		/*int counter = 0;
		Node* tmp = begin();
		while (tmp != end())
		{
			tmp = tmp->next;
			counter++;
		}
		return counter;*/
		return length;
	}

	void push_back(const int& value)
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
	void push_front(const int& value)
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
	void insert(Node* ind, const int& value)
	{
		if (ind == end())
		{
			tail->next = new Node(value, end());
			tail = tail->next;
		}
		else
		{
			Node* tmp = findPrev(ind);
			if (tmp == end())
				throw "Pos is not in list.";
			tmp->next = new Node(value, tmp->next);
		}
		length++;
	}
	void insert(Node* ind, int n, const int& value)
	{
		for (int i = 0; i < n; i++)
		{
			insert(ind, value);
		}
	}
	void insert(Node* pos, Node* first, Node* last)
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
	void erase(Node* ind)
	{
		if (isEmpty())
			throw "List is empty";
		Node* prev = root;
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
	void erase(Node* first, Node* last)
	{
		Node* tmp;
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
	int front()
	{
		if (isEmpty())
			throw "List is empty";
		return begin()->data;
	}
	int last()
	{
		if (isEmpty())
			throw "List is empty";
		return tail->data;
	}
	Node* find(const int& value) const
	{
		Node* tmp = begin();
		Node* stop = end();
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
	List& assign(const List& rhs)
	{
		clear();
		Node* tmp = rhs.begin();
		while (tmp != rhs.end())
		{
			push_back(tmp->data);
			tmp = tmp->next;
		}
		return *this;
	}
	List& operator=(const List& rhs)
	{
		return assign(rhs);
	}
	void print() const
	{
		Node* first = begin();
		while (first != end())
		{
			cout << first->data << " ";
			first = first->next;
		}
		cout << endl;
	}
};

int main()
{
	List l1(4,12);
	List l2(l1.begin(), l1.begin()->next->next);
	l1.print();
	l2.print();
	List l3 = l2; // List l3(l2); // kopyalama kurucusu
	//l3 = l2 atama operatörü
	l3.print();
	l3.push_back(45);
	l1.print();
	l2.print();
	l3.print();
	return 0;
}