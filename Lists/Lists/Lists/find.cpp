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
	List l;
	try
	{
		l.push_back(15);
		l.push_back(859);
		l.push_back(65);
		l.push_back(648);
		l.push_back(98);
		l.push_back(6);
		l.print();
		Node* wanted;
		wanted = l.find(859);
		cout << wanted->data << endl;
		wanted = l.find(9);
		cout << endl << wanted->data;
		cout << endl << endl;
	}
	catch (const char* exception)
	{
		cout << exception;
	}

	return 0;
}
