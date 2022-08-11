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
	Node* first;
	Node* last;
	{
		List l;
		l.push_back(10);
		l.push_back(20);
		l.push_back(30);
		l.print();
		first = l.begin();
		last = l.end();
	}
	
	while (first != last)
	{
		cout << first->data << " ";
		first = first->next;
	}
	

	return 0;
}
