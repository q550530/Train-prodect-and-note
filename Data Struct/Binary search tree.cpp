
#include <iostream>

using namespace std;

class Node {
public:
	int key;
	//string element;
	Node* left;
	Node* right;

	Node(int a) :key(a) {};

};

class BST {
protected:
	Node* root;
	void insert(Node* p, int _key) {//P can not be NULL
		if (p->key > _key) {
			if (p->left == NULL)
				p->left = new Node(_key);
			else
				insert(p->left, _key);
		}
		else
		{
			if (p->right == NULL)
				p->right = new Node(_key);
			else
				insert(p->right, _key);
		}
	}
	bool search(Node* p, int _key)const {
		if (p->key > _key) {
			if (p->left == NULL)
				return false;
			else
				search(p->left, _key);
		}
		else if (p->key < _key)
		{
			if (p->right == NULL)
				return false;
			else
				search(p->left, _key);
		}
		else
		{
			return true;
		}
	}
	void printInorder(Node *p)const {
		if (p->left != NULL)
			printInorder(p->left);
		cout << p->key << " ";
		if (p->right != NULL)
			printInorder(p->right);
		
	}
	void printPreorder(Node* p)const {
		cout << p->key << " ";
		if (p->left != NULL)
			printInorder(p->left);
		
		if (p->right != NULL)
			printInorder(p->right);

	}
	
public:
	BST() :root(NULL) {};
	void insert(int);
	bool search(int);
	void printInorder() const;
	void printPreorder() const;

};

void BST::insert(int _key) {
	if (root == NULL)
		root = new Node(_key);
	else
		insert(root, _key);
}
bool BST::search(int _key) {
	if (root == NULL)
		return false;
	else
	{
		return search(root, _key);
	}

}

void BST::printInorder()const {
	if (root == NULL)
		cout << "NULL" << endl;
	else
		printInorder(root);

}
void BST::printPreorder()const {
	if (root == NULL)
		cout << "NULL" << endl;
	else
		printPreorder(root);

}
int main()
{
	BST bst;
	bst.insert(5);
	bst.insert(12);
	bst.insert(3);
	
	bst.printInorder();
	bst.printPreorder();

	system("pause");
	return 0;
}

