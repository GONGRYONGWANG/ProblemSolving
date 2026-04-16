#include<iostream>
using namespace std;
#define endl "\n"

#include<vector>
#include<utility>

template <typename T>
class Node {
private:
	Node* Parent;
	Node* Left;
	Node* Right;
	T value;
public:
	Node(T _value, Node* _Left = nullptr, Node* _Right = nullptr,Node* _Parent = nullptr) {
		this->value = _value;
		this->Left = _Left;
		this->Right = _Right;
		this->Parent = _Parent;
		if (_Left != nullptr) {
			_Left->SetParent(this);
		}
	};
	~Node() {};
	void SetParent(Node* x) {
		this->Parent = x;
	}
	void SetLeft(Node* x) {
		this->Left = x;
	}
	void SetRight(Node* x) {
		this->Right = x;
	}

	void PreorderTraversal() {
		cout << this-> value;
		if (this->Left != nullptr) {
			Left->PreorderTraversal();
		}
		if (this->Right != nullptr) {
			Right->PreorderTraversal();
		}
		return;
	}

	void InorderTraversal() {
		if (this->Left != nullptr) {
			Left->InorderTraversal();
		}
		cout << this->value;
		if (this->Right != nullptr) {
			Right->InorderTraversal();
		}
		return;
	}

	void PostorderTraversal() {
		if (this->Left != nullptr) {
			Left->PostorderTraversal();
		}
		if (this->Right != nullptr) {
			Right->PostorderTraversal();
		}
		cout << this->value;
		return;
	}
};





int main() {
	int N;
	cin >> N;
	vector<Node<char>*> tree;
	Node<char>* tmp;
	for (int i = 65; i < 65 + N; i++) {
		tmp = new Node<char>((char)i);
		tree.push_back(tmp);
	}
	char p, l, r;
	for (int i = 0; i < N; i++) {
		cin >> p >> l >> r;
		if (l != '.') {
			tree[(int)p - 65]->SetLeft(tree[(int)l - 65]);
		}
		if (r != '.') {
			tree[(int)p - 65]->SetRight(tree[(int)r - 65]);
		}
	}

	tree[0]->PreorderTraversal();
	cout << endl;
	tree[0]->InorderTraversal();
	cout << endl;
	tree[0]->PostorderTraversal();


	return 0;
}
