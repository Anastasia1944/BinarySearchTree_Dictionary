#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <iostream>
using namespace std;
//template <class T>
class LinkedList {
private:
	struct Node
	{
		string item_;
		Node* next_;
		Node(string item, Node* next = nullptr, Node* prev = nullptr) :
			item_(item), next_(next) { }
	};
	int count_;
	Node* head_;
public:
	LinkedList() : count_(0), head_(nullptr) { };

	void insert(string str) {		
		Node* x = new Node(str);
		x->item_ = str;
		if (head_ == nullptr){
			head_ = x;
		}
		else {
			if (str < head_->item_) {
				x->next_ = head_;
				head_ = x;
			}
			else{
				Node* temp2 = head_->next_;	
				Node* temp1 = head_;
				while (temp2!=nullptr && str > temp2->item_) 
					temp2 = temp2->next_;
				if (temp2 != nullptr)
					x->next_ = temp2;
				temp1->next_ = x;
			}
		}
		count_++;
	};
	void outAll() {
		if (count_ != 0)
		{
			Node* temp = head_;
			while (temp != NULL)
			{
				cout << "|" << temp->item_ << "| ";
				temp = temp->next_;
			}
		}
		cout << endl;
	}

	void deleteList() {
		Node* x = head_;
		while (x->next_ != nullptr) {
			head_ = x->next_;
			delete x;
			x = head_;
		}
	}

	~LinkedList() {
		this->deleteList();
	};
};
#endif

