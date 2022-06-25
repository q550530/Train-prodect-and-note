#include <iostream>

using namespace std;

template <class T>
class Listnode {
public:
	T data;
	Listnode* next;
	Listnode<T>(T a = 0) :data(a), next(0) {};
};

template <class T>
class LinkedList :public Listnode<T>
{
private:
	Listnode<T>* first;
public:
	LinkedList<T>() :first(0) {};
	void PrintList();           // 印出list的所有資料
	void Push_front(T x);     // 在list的開頭新增node
	void Push_back(T x);      // 在list的尾巴新增node
	void Delete(T x);         // 刪除list中的 int x
	void Clear();               // 把整串list刪除
	void Reverse();             // 將list反轉: 7->3->14 => 14->3->
	
};


template <class T>
void LinkedList<T>:: PrintList() {
	if (first==0)
	{
		cout << "List is empty.\n";
		return;
	}
	else {
		Listnode<T>* current = first;
		while (current !=0)
		{
			cout << current->data <<" ";
			current = current->next;
		}
		cout << endl;
	}

}

template <class T>
void LinkedList<T>::Push_back(T input) {
	Listnode<T> *NewNode= new Listnode<T>(input);
	if (first == 0) {                      // 若list沒有node, 令newNode為first
		first = NewNode;
		return;
	}
	Listnode<T>* current=first;
	while (current->next !=0)
	{
		current = current->next;
	}
	current->next = NewNode;
	

}

template <class T>
void LinkedList<T>::Push_front(T input) {
	 Listnode<T>* NewNode = new Listnode<T>(input);
	 NewNode->next = first;// 先把first接在newNode後面
	 first = NewNode;      // 再把first指向newNode所指向的記憶體位置

}
template <class T>
void LinkedList<T> ::Delete(T target) {
	Listnode<T>* current = first, *previous =0;

	while (current != 0 && current->data != target) {
		previous = current;                       // 如果current指向NULL
		current = current->next;                  // 或是current->data == x
	}                                             // 即結束while loop
	if (current == 0)                  // list沒有要刪的node, 或是list為empty
		cout << "There is no " << target << " in list.\n";
	else if (current == first) {        // 要刪除的node剛好在list的開頭
		first = current->next;          // 把first移到下一個node
		delete current;                 // 如果list只有一個node, 那麼first就會指向NULL
		current = 0;                    // 當指標被delete後, 將其指向NULL, 可以避免不必要bug
		                   
	}
	else {                              // 其餘情況, list中有欲刪除的node, 
		previous->next = current->next; // 而且node不為first, 此時previous不為NULL
		delete current;
		current = 0;
		
	}

}

template <class T>
void LinkedList<T> ::Clear() {
	while (first != 0) {
		Listnode<T>* current = first;
		first = current->next;
		delete current;
		current = 0;

	}
}

template <class T>
void LinkedList<T> ::Reverse() {
	if (first == 0 || first->next == 0) {
		// list is empty or list has only one node
		return;
	}
	Listnode<T>*previous = 0,* current = first,* preceding = current->next;
	while (preceding != 0) {
		current->next = previous;      // 把current->next轉向
		previous = current;            // previous往後挪
		current = preceding;           // current往後挪
		preceding = preceding->next;   // preceding往後挪
	}                                  // preceding更新成NULL即跳出while loop
	current->next = previous;          // 此時current位於最後一個node, 將current->next轉向
	first = current;

}



int main()
{
	LinkedList<int> a;
	a.Push_back(5);
	a.Push_back(80);
	a.Push_back(7);
	a.PrintList();
	a.Push_front(9);
	a.PrintList();
	a.Delete(7);
	a.PrintList();
	a.Reverse();
	a.PrintList();
	a.Clear();
	a.PrintList();

	system("pause");
	return 0;
}