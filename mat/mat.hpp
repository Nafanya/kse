#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>
using namespace std;

struct matrix {
	int n, m;
	vector<vector<double> > a;

	matrix() {}
	matrix(int n, int m) {
		this->n = n;
		this->m = m;
		a.assign(n, vector<double>(m, 0));
	}

	vector<double>& operator[](const int &id) {
		assert(0 <= id && id < n);
		return a[id];
	}

	const vector<double>& operator[](const int &id) const {
		assert(0 <= id && id < n);
		return a[id];
	}

	matrix operator* (const matrix &b) const {
		assert(m == b.n);
		matrix res(n, b.m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < b.m; j++) {
				for (int k = 0; k < m; k++) {
					res[i][j] += a[i][k] * b[k][j];
				}
			}
		}
		return res;
	}

	matrix operator+ (const matrix &b) const {
		assert(n == b.n && m == b.m);
		matrix res = *this;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				res[i][j] += b[i][j];
			}
		}
		return res;
	}

	matrix operator- (const matrix &b) const {
		assert(n == b.n && m == b.m);
		matrix res = *this;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				res[i][j] -= b[i][j];
			}
		}
		return res;
	}

	double operator% (const matrix &b) const {
		assert(n == b.n && m == b.m);
		double ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ans += a[i][j] * b[i][j];
			}
		}
		return ans;
	}

	matrix operator* (double d) const {
		matrix res = *this;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				res[i][j] *= d;
			}
		}
		return res;
	}

	void print() const {
		cout.precision(8);
		cout << fixed;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << a[i][j] << " \n"[j + 1 == m && m != 1];
			}
		}
		if (m == 1) cout << "\n";
	}

	double norm() const {
		double sum = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				sum += a[i][j] * a[i][j];
			}
		}
		return sqrt(sum);
	}
};
