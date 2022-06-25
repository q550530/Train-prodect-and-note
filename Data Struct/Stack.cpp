
#include <iostream>

using namespace std;

const int STACK_SIZE = 10;

class Stack
{
public:
	Stack() :itop(-1) {};
	bool puch(int);
	bool pop();
	void printStack() const;
	

private:
	int Data[STACK_SIZE];
	int itop;
};

bool Stack::puch(int a) {
	if (itop == STACK_SIZE - 1) {
		cout << "Stack is full!!\n";
		return false;
	}
	else {
		++itop;
		Data[itop] = a;
		return true;
	}

}

bool Stack::pop() {
	if (itop == -1)
	{
		cout << "Stack is empty" << endl;
		return false;
	}
	else
	{
		itop--;
		return true;
	}

}
void Stack::printStack()const {
	if (itop==-1)
	{
		cout << "Stack is empty" << endl;
	}
	else
	{
		for (size_t i = 0; i <= itop; i++)
		{
			cout << Data[i] << ' ';
		}
	}
	

}



int main()
{
	Stack mystack;
	mystack.puch(5);
	mystack.puch(4);
	mystack.puch(8);
	mystack.puch(7);
	mystack.printStack();
	mystack.pop();
	mystack.printStack();
	
	system("pause");
	return 0;
}