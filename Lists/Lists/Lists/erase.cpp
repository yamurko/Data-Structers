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
public:
	List()
	{
		root = new Node();
		tail = root;
		tail->next = new Node();
	}
	Node* begin() const { return root->next; }
	Node* end() const { return tail->next; }
	bool isEmpty() const { return begin() == end(); }

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
			Node* tmp = root;
			while (tmp->next != ind)
				tmp = tmp->next;
			tmp->next = new Node(value, tmp->next);
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
			while (prev->next != ind)
				prev = prev->next;
			prev->next = ind->next;
			tail = prev;
		}
		else
		{
			while (prev->next != ind)
				prev = prev->next;
			prev->next = ind->next;
		}
		delete ind;
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
	List l;
	try
	{
		l.insert(l.begin(), 9);
		l.print();
		l.insert(l.end(), 19);
		l.print();
		l.push_back(15);
		l.push_back(856);
		l.push_back(962);
		l.push_back(1036);
		l.print();
		cout << l.front() << " " << l.last() << endl;
		l.erase(l.begin());
		l.print();
		l.pop_back();
		l.print();
		l.pop_front();
		l.print();
		cout << endl << endl;
	}
	catch (const char* exception)
	{
		cout << exception;
	}
	
	return 0;
}
