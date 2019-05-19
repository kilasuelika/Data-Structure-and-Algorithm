#include<vector>
#include<iostream>
using namespace std;

// Merge two orderd list.
// Note: STL has a template merge can do the same thing.
// Set three pointers. Two of them point to two passed vectors. The third points to result vector.
template<typename T>
vector<T> merge_ordered_list(vector<T>& v1, vector<T>& v2)
{
	size_t n1 = v1.size();
	size_t n2 = v2.size();
	size_t n = n1 + n2;

	// A new vector to store result.
	vector<T> res;
	res.resize(n);

	// Pointers.
	size_t p1, p2, p3;
	p1 = p2 = p3 = 0;

	// Note stopping condition. 1. Internal. 2. Boundary.
	while (p3 < n) {
		if ((p1 != n1 && p2 != n2 && v1[p1] > v2[p2]) ||
			(p1 == n1)) {
			res[p3] = v2[p2];
			++p2;
			++p3;
		}
		else if ((p1 != n1 && p2 != n2 && v1[p1] <= v2[p2]) ||
			(p2 == n2)) {
			res[p3] = v1[p1];
			++p1;
			++p3;
		};
	}
	
	return res;
}