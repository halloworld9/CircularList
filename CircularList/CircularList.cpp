#include <iostream>
#include <fstream>
#include "list.h"
using namespace std;

template <typename T>
bool isCycle(list2<T> &l) {
	return l.last->next != nullptr || l.first->prev != nullptr;
}

int main() {
	list2<int> l;
	for (int i = 0; i < 10; i++) {
		add(l, i);
	}
	cout << isCycle(l) << endl;
	l.last->next = l.first;
	cout << isCycle(l) << endl;
	l.last->next = nullptr;
	l.first->prev = l.last;
	cout << isCycle(l) << endl;
	l.first->prev = nullptr;
	l.last->next = l.first->next->next;
	cout << isCycle(l) << endl;
	l.last->next = nullptr;
	cout << isCycle(l) << endl;
}