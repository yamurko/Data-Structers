#include<iostream>

using namespace std;

class Node
{
public:
	int data;
	Node* next;
	Node(const int& data = int(), Node* next = NULL) : data(data), next(next) { }
};

int main()
{
	Node* n1 = new Node(15);
	Node* n2 = new Node(12);
	Node* n3 = new Node(32);
	n1->next = n2;
	n2->next = n3;
	cout << n1->data << endl;
	cout << n2->data << endl;
	cout << n1->next->data << endl;
	cout << n3->data << endl;
	cout << n2->next->data << endl;
	cout << n1->next->next->data << endl;
	Node* tmp = n1;
	while (tmp != NULL)
	{
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	cout << endl << endl;
	return 0;
}
