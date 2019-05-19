#ifndef _ALG_UTIL_
#define _ALG_UTIL_
#include<vector>
#include<iostream>
#include<string>

using namespace std;

template<typename T>
void print_vec(const vector<T>& v,string sep=" ") {
	for (size_t i = 0; i < v.size()-1; i++) {
		cout << v[i]<<sep;
	};

	cout << v[v.size()-1];
}

#endif