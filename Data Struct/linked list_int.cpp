
#include <iostream>

using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node(int a = 0) :data(a), next(0) {};
};

class list:public Node{
public:
	Node* first;
	int size;

	list(){
		first= 0;
		size = 0;
	}
	bool empty() const;
	void printList()const;
	void push_front(int);
	void insert(int ,int);
	void push_back(int);
	void erase(int);
	void clear();
	void reverse();

};

bool list::empty()const{
	return (size == 0);
}

void list::push_front(int _data) {
	Node* p = new Node(_data);
	if (first == 0)
		first = p;
	else
	{
		p->next = first;
		first = p;
	}
	++size;
}

void list::printList()const {
	Node* current = first;
	while (current!=0)
	{
		cout << current->data <<' ';
		current = current->next;
	}
	cout << "Null" << endl;
}
void list::push_back(int _data) {
	Node* NewNode = new Node(_data), * current = first;
	if (current == 0)
		first = NewNode;
	while (current->next!=0)
	{
		current = current->next;
	}
	current->next = NewNode;
}

void list::insert(int index,int _data) {
	Node* current = first, * beforeNode = 0, *NewNode = new Node(_data);
	if (index == 0)
		push_front(_data);
	else
	{
		for (int i = 0; i < index;i++) {
			beforeNode = current;
			current = current->next;
		}
		beforeNode->next = NewNode;
		NewNode->next = current;
		++size;

	}


}

void list::erase(int _target) {
	Node* current = first,*beforeNode=0;
	while (current->data!=_target&&current!=0)
	{
		beforeNode = current;
		current = current->next;
	}
	if (current==0)
		cout << "Did not find!" << endl;
	else if (current==first)
	{
		first = current->next;
		delete current ;
		current = 0;
	}
	else
	{
		beforeNode->next = current->next;
		delete current;
		current = 0;
	}
	
}

void list::clear() 
{
	
	while (first!=0)
	{
		Node* current = first;
		first = current->next;
		delete current;
		current = 0;
	}


}

int main()
{
	list mylist;
	mylist.push_front(1);
	mylist.push_front(2);
	mylist.push_front(3);
	mylist.push_front(4);
	mylist.printList();

	mylist.push_back(9);
	mylist.insert(1, 999);
	mylist.printList();
	mylist.erase(5);
	mylist.printList();
	mylist.clear();
	mylist.printList();
	
	system("pause");
	return 0;
}
