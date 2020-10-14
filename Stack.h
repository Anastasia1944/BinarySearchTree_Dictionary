#ifndef _STACK_H
#define _STACK_H

#include <iostream>
using namespace std;
template <typename T>
class Stack {
private:
	// ������� �����
	int top_;
	// ������ �����
	int size_;
	// ����� ������ �����
	T* stack_;
public:
	// ����������� �����
	Stack(const int i)
	{
		size_ = i;
		stack_ = new T[i];
		top_ = 0;
	}
	// ������� � ����
	void push(T x) {
		if (top_ == size_)
			throw "������� ���������!";
		top_++;
		stack_[top_] = x;
	}
	// �������� �� �����
	T pop() {
		if (this->isStackEmpty())
			throw "���� ������!";
		else {
			top_--;
			return stack_[top_ + 1];
		}
	}
	// ��������, ���� �� � ����� ��������
	bool isStackEmpty() {
		if (top_ == 0)
			return true;
		else return false;
	}
};

#endif
