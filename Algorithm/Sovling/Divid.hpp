#ifndef _ALG_DIVID_
#define _ALG_DIVID_

#include<vector>
using namespace std;

/* Reversed pairs count.
 We use a new variable vx to store the original vector.
 step 1: count left.
 step 2: count right.
 step 3: count left with right.
 After the first two step, left and right part have been sorted.
*/
template<typename T>
int count_reversed_pair(vector<T> v) {
	if (v.size() <= 1) return 0;
	if (v.size() == 2)return v[0] > v[1];

	int n = v.size();
	int mid = (n - 1) / 2;
	return count_reversed_pair<T>(v, 0, mid) + count_reversed_pair<T>(v, mid + 1, n - 1) +
		count_reversed_pair<T>(v, 0, mid, n - 1);
};

template<typename T>
int count_reversed_pair(vector<T> & v, int n1, int n2) {
	if (n1 == n2) return 0;

	if (n2 - n1 == 1) {
		if (v[n1] > v[n2]) {
			swap(v[n1], v[n2]);
			return 1;
		}
		else return 0;
	}
	else {
		int mid = (n1 + n2) / 2;
		return count_reversed_pair<T>(v, n1, mid) + count_reversed_pair<T>(v, mid + 1, n2) +
			count_reversed_pair<T>(v, n1, mid, n2);
	}
};

template<typename T>
int count_reversed_pair(vector<T> & v, int n1, int mid, int n3) {

	// {1,2,3},{4,5,6}: No reversed pair.
	if (v[mid] <= v[mid + 1]) return 0;

	// mv: A temporary vector to store merged vector.
	vector<T> mv;
	int n = n3 - n1 + 1;
	mv.resize(n);

	// {4,5,6},{1,2,3}: 3*3 reversed pairs.
	if (v[n1] > v[n3]) {
		for (int i = 0; i < n; i++) {
			if (i < n3 - mid) {
				mv[i] = v[mid + 1 + i];
			}
			else {
				mv[i] = v[n1 + i - n3 + mid];
			};
		};
		return (mid - n1 + 1) * (n3 - mid);
	};

	// rc: count.
	int p1 = n1, p2 = mid + 1, p3 = 0, rc = 0, idx;

	// Sort and count.
	// Loop over each element in left part.
	for (; p1 <= mid; ++p1) {
		idx = inf_index<T>(v, p1, p2, n3);
		if (idx == -1) {
			mv[p3] = v[p1];
			++p3;
			continue;
		}
		else {
			for (int i = p2; i <= idx; ++i) {
				mv[p3] = v[i];
				rc += idx - p2 + 1;
				p3++;
			};

			if ((p2 = idx + 1) > n3) break;
		};

	};

	//Write back merged vector.
	for (int i = n1, j = 0; i <= n3; ++i, ++j) {
		v[i] = mv[j];
	};

	return rc;
}

// Given an int n, find the maximimum index x between l and u so that v[n]> v[x].
// If all elements in range are larger than v[n], return -1.
template<typename T>
int inf_index(vector<T> & v, int n, int l, int u) {
	if (u == l) {
		if (v[n] > v[l]) return l;
		else return -1;
	};

	if (v[l] > v[n]) return -1;
	if (v[u] < v[n])return u;

	int mid;
	while (u - l > 1) {
		mid = l + (u - l) / 2;
		if (v[n] <= v[mid]) {
			u = mid;
		}
		else {
			l = mid;
		};
	};

	if (v[l] == v[n]) return -1;
	if (v[l] < v[n] && v[u] >= v[n]) return l;
	if (v[u] < v[n]) return u;
};

#endif // !_ALG_DIVID_
