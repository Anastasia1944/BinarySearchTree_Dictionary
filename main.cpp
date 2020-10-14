#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	try{
	BinarySearchTree<string> Tree;
	Tree.input();
	char k[20];
	Tree.out();
	cout << "������� ����� ��� ��������: ";
	cin >> k;
	cout << "�������: ";
	Tree.search(k);
	}
	catch (const char* errorString) {
		cerr << endl << errorString << endl;
		return -1;
	}
	return 0;
}