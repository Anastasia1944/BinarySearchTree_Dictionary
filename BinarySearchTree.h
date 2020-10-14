#ifndef __BINARY_SEARCH_TREE_H
#define __BINARY_SEARCH_TREE_H

#include <iostream>
#include <fstream>
#include <string>
#include "BNF.h"
#include "Stack.h"
#include "LinkedList.h"
using namespace std;
template <class T>
class BinarySearchTree {
private:
	struct Node {
		T key_;
		Node* left_;
		Node* right_;
		Node* p_;
		LinkedList list;
		Node(const T& key, Node *left = nullptr, Node *right = nullptr, Node *p = nullptr) :
			key_(key), left_(left), right_(right), p_(p)
		{ };
		Node(BNF& str, Node *left = nullptr, Node *right = nullptr, Node *p = nullptr) :
			key_(str.word()), left_(left), right_(right), p_(p)
		{ 
			list.insert(str.translation());
		};

	};
	Node* root_; 
	int size_;
public:
	// Конструктор бинарного дерева
	BinarySearchTree() : root_(nullptr), size_(0) {};

	// Вставка слова с переводом в бинарное дерево
	void insert(char* ch) {
		BNF tran(ch);
		T str = tran.word();
		Node* x = this->root_;
		Node* y = nullptr;
		while (x != nullptr && x->key_ != str ) {
			y = x;
				if (str < x->key_)
					x = x->left_;
				else
					if (str > x->key_)
						x = x->right_;
			}
		if (x != nullptr && str == x->key_) {
			x->list.insert(tran.translation());
		}
		else{
			Node* z = new Node(tran);
			z->p_ = y;
			if (y == nullptr)
				this->root_ = z;
			else {
				if (z->key_ < y->key_)
					y->left_ = z;
				else
					y->right_ = z;
			}
		}
	};

	void input() {
		string file;
		cout << "Введите название файла для ввода: ";
		cin >> file;
		ifstream F(file);
		if (!F.is_open())
			throw "Неверно указано имя файла или путь к нему";
		const int SIZE = 100;
		char s[SIZE];
		int count = 0;
		while (F.getline(s, SIZE + 1)) {
			if (s == "")
				throw "Файл пуст";
			this->insert(s);
			count++;
		}
		size_ = count;
		F.close();
	}

	void search(char* st) {
		Node* x = root_;
		while (x != nullptr && st != x->key_) {
			if (st < x->key_)
				x = x->left_;
			else
				x = x->right_;
		}
		if (x != nullptr)
			x->list.outAll();
		else
			cout << "Слова не найдено";
	}

	void out() {
		Stack<Node*> stack1(5);
		Node* temp = nullptr;
		if (root_ == nullptr)
			throw "Ошибка";
		temp = root_;
		stack1.push(root_);
		while (temp->left_ != nullptr) {
			temp = temp->left_;
			stack1.push(temp);
		}
		while (!stack1.isStackEmpty()) {
			temp = stack1.pop();
			cout << temp->key_ << ": ";
			temp->list.outAll();
			if (temp->right_ != nullptr) {
				temp = temp->right_;
				stack1.push(temp);
				while (temp->left_ != nullptr) {
					temp = temp->left_;
					stack1.push(temp);
				}
			}
		}
		cout << endl;
	}

	void deleteSubtree(Node* node) {
		if (node->left_)
			deleteSubtree(node->left_);
		if (node->right_)
			deleteSubtree(node->right_);
		node->list.deleteList();
		delete node;
	}

	~BinarySearchTree() {
		if(root_!=nullptr)
			deleteSubtree(root_);
	}

};

#endif