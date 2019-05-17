#include "DataStructure/LinearList/LinearList.h"
#include<iostream>

int main() {
	//Test LinkedList.
	int arr[5] = { 9, 2, 3, 5, 6 };
	LinkedListChain<int, 5> l1 = arr;
	l1.PrintElements();

	l1.Insert(0, 5);
	l1.PrintElements();

	l1.Insert(2, 5);
	l1.PrintElements();

	l1.Delete(2);
	l1.PrintElements();
	l1.Pop();
	l1.PrintElements();

	return 0;
}