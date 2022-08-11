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
	void print()
	{
		Node* first = begin();
		while (first != end())
		{
			cout << first->data << " ";
			first = first->next;
		}
	}
};

int main()
{
	List l;
	l.push_back(15);
	l.push_back(682);
	l.push_back(87);
	l.push_back(965);
	l.print();
	
	cout << endl << endl;
	return 0;
}
