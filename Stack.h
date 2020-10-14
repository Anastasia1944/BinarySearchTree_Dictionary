#ifndef _STACK_H
#define _STACK_H

#include <iostream>
using namespace std;
template <typename T>
class Stack {
private:
	// вершина стека
	int top_;
	// размер стека
	int size_;
	// адрес начала стека
	T* stack_;
public:
	// Конструктор стека
	Stack(const int i)
	{
		size_ = i;
		stack_ = new T[i];
		top_ = 0;
	}
	// Вставка в стек
	void push(T x) {
		if (top_ == size_)
			throw "Очередь заполнена!";
		top_++;
		stack_[top_] = x;
	}
	// Удаление из стека
	T pop() {
		if (this->isStackEmpty())
			throw "Стек пустой!";
		else {
			top_--;
			return stack_[top_ + 1];
		}
	}
	// Проверка, есть ли в стеке элементы
	bool isStackEmpty() {
		if (top_ == 0)
			return true;
		else return false;
	}
};

#endif
