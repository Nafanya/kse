#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);

	int n;
	double eps = 1e-9;

	cin >> n;

	double norm = eps + 1.0;
	vector< vector<double> > matr(n, vector<double>(n, 0.0));
	vector<double> free(n, 0);
	vector<double> x(n, 0.0);
	double w = 0.1;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> matr[i][j];
		}
	}
	for(int i = 0; i < n; i++) {
        cin >> free[i];
		x[i] = free[i];
	}

	for(int i = 0; i < n; i++) {
		//double temp = 0;;
		for(int j = 0; j < n; j++) {
			if(i != j) {
				matr[i][j] = -matr[i][j] / matr[i][i];
			}
		}

		free[i] /= matr[i][i];
		matr[i][i] = 0;
	}
	int cnt_it = 0;
	while(norm > eps) {
        cnt_it++;
		vector<double> temp_x(n, 0.0);
		for(int i = 0; i < n; i++) {
			temp_x[i] = free[i];
			for(int j = 0; j < n; j++) {
				if(i != j) {
					temp_x[i] += (matr[i][j] * x[j]);
				}
			}
			temp_x[i] += (w - 1) * (temp_x[i] - x[i]);
		}

		norm = fabs(x[0] - temp_x[0]);
		for(int i = 0; i < n; i++) {
			norm = max(norm, fabs(temp_x[i] - x[i]));
			x[i] = temp_x[i];
		}
	}
	cout << "Iterations: " << cnt_it << endl;
	for(int i = 0; i < n; i++) {
		cout << x[i] << endl;
	}
	return 0;
}
