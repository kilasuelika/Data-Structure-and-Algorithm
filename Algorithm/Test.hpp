#include "List_OP.hpp"
#include "Util.hpp"
#include<iostream>

using namespace std;

template<typename T>
void test_merge_ordered_list(vector<T>& v1, vector<T>& v2) {
	cout << "v1: ";
	print_vec<T>(v1);
	cout << "v2: ";
	print_vec<T>(v2);
	cout << "Merges: ";
	print_vec<T>(merge_ordered_list<T>(v1, v2));
};

void test_List_OP(){
	cout << "Testing merge_ordered_list..." << endl;
	cout << "Case 1:" << endl;
	test_merge_ordered_list<int>(vector<int>{ 1,2,5,6,9 }, vector<int>{ 1,2,3 });
	cout << "Case 2:" << endl;
	test_merge_ordered_list<double>(vector<double>{ 1.9, 2.1, 5, 6, 9.1 }, vector<double>{ 1.05, 2, 3 });
}