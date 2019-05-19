#include "Divid.hpp"
#include <iostream>
#include "../Util.hpp"
using namespace std;

void test_count_reversed_pair() {
	cout << endl << "Testing counting reversed pairs..." << endl;
	vector<int> v{ 1,2,3 };
	print_vec<int>(v) ;
	cout << " : " << count_reversed_pair<int>(v) << endl;
	v = { 1,3,2 };
	print_vec<int>(v);
	cout << " : " << count_reversed_pair<int>(v) << endl;
	v = { 2,1,4,3 };
	print_vec<int>(v);
	cout << " : " << count_reversed_pair<int>(v) << endl;
}