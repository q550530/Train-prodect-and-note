// Stack with Fraction(STL)1.cpp : main project file.


#include "stdafx.h"
#include <iostream>
#include "FRACTION.h"

using namespace std;
//STACK : LIFO -> Last In First Out
template <class T, int SIZE = 10>
class STACK{
private:
	T data[SIZE];
	int iTop;
public:
	STACK<T, SIZE>() : iTop(-1){}
	bool push(T);
	bool pop();
	void printStack() const;
	template <class T, int SIZE>
	friend ostream& operator<<(ostream &out, const STACK<T, SIZE> &);
	// cout << myStack -> operator<<(cout, myStack)
};
template <class T, int SIZE>
bool STACK<T, SIZE>::push(T d){
	//檢查stack是否已滿
	if (iTop == SIZE - 1){
		cout << "Stack is full!!\n";
		return false;
	}
	else{
		++iTop;
		data[iTop] = d;
		return true;
	}

}

template <class T, int SIZE>
bool STACK<T, SIZE>::pop(){
	if (iTop == -1){
		cout << "Stack is empty!!\n";
		return false;
	}
	else{
		--iTop;
		return true;
	}
}
template <class T, int SIZE>
void STACK<T, SIZE>::printStack() const{
	if (iTop == -1){
		cout << "Stack is empty!!\n";
	}
	else{
		for (int i = 0; i <= iTop; ++i){
			cout << data[i] << '\0';
		}
		cout << endl;
	}
}
template <class T, int SIZE>
ostream& operator<<(ostream &out, const STACK<T, SIZE> & s){
	if (s.iTop == -1){
		out << "Stack is empty!!\n";
	}
	else{
		for (int i = 0; i <= s.iTop; ++i){
			out << s.data[i] << '\0';
		}
		out << endl;
	}
	return out;
}

int main()
{
	STACK<int> myStack;
	myStack.pop();

	cout << myStack;
	myStack.push(5);
	myStack.push(13);
	myStack.push(17);
	myStack.push(25);
	myStack.push(2);

	cout << myStack;
	myStack.pop();
	myStack.pop();
	cout << myStack;
	//-------------------------------------
	STACK<FRACTION, 5> yourStack;
	yourStack.push(FRACTION(2, 3));
	yourStack.push(FRACTION(5, 4));
	yourStack.push(FRACTION(55, 21));
	cout << yourStack;


	system("pause");
	return 0;
}