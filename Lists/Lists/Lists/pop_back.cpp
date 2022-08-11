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
public:
	List() : root(NULL) { }
	Node* begin() const { return root; }
	Node* end() const { return NULL; }
	bool isEmpty() const { return begin() == end(); }
	void push_back(const int& value)
	{
		if (isEmpty())
			root = new Node(value);
		else
		{
			Node* tmp = begin();
			while (tmp->next != end())
				tmp = tmp->next;
			tmp->next = new Node(value);
		}
	}
	void push_front(const int& value)
	{
		Node* tmp = new Node(value);
		tmp->next = root;
		root = tmp;
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
		Node* tmp = begin();
		while (tmp->next != end())
			tmp = tmp->next;
		return tmp->data;
	}
	void pop_back()
	{
		if (isEmpty())
			throw "List is empty";
		else if (begin()->next == NULL)
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
	void print()
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
	l.push_front(236);
	l.push_back(47);
	l.push_back(1);
	l.push_back(785);
	l.push_front(849);
	l.print();
	l.pop_back();
	l.print();
	cout << endl << endl;
	return 0;
}
