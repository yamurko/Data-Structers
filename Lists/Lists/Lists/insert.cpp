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
		insert(end(), value);
	}
	void push_front(const int& value)
	{
		insert(begin(), value);
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
	void pop_back()
	{
		if (isEmpty())
			throw "List is empty";
		if (begin()->next == end())
		{
			delete root;
			root = NULL;
		}
		else
		{
			Node* tmp = begin();
			while (tmp->next->next != end())
				tmp = tmp->next;
			delete tmp->next;
			tmp->next = NULL;
		}
	}
	void pop_front()
	{
		if (isEmpty())
			throw "List is empty";
		Node* tmp = root;
		root = tmp->next;
		delete tmp;
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
	cout << endl << endl;
	return 0;
}
