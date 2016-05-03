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


#include "mat.hpp"

using namespace std;

const int MAXN = 1 << 10;
const double EPS = 1e-8;

void fast_descent(const matrix &A, const matrix &b);

void f() {
    int n;
    double eps;
    cin >> n;
    cin >> eps;
    matrix a(n, n);
    matrix b(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> a[i][j];
        cin >> b[i][0];
    }

    //exit(0);
    /*b[0][0] = 0.916534;
    b[1][0] = 1.07869;
    b[2][0] = 1.25808;
    b[3][0] = 1.41065;
    b[4][0] = 1.53927;*/
    
    fast_descent(a, b);
    exit(0);
}

matrix gen(int n) {
    matrix a(n, n);
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) if (i != j) {
            if (j > i) {
                a[i][j] = rand() % 30 - 10;
            } else {
                a[i][j] = a[j][i];
            }
            sum += abs(a[i][j]);
        }
        a[i][i] = sum + 1;
    }
    return a;
}

void conjugate_gradients(const matrix &A, const matrix &b) {
    cout << "conj gradients" << endl;
    cout << "matrix A:" << endl;
    A.print();
    cout << "vector B:" << endl;
    b.print();

    srand(111333);
    int n = A.n;
    matrix x(n, 1);
    for (int i = 0; i < n; i++) {
        x[i][0] = rand() % 30 - 11;
    }
    cout << "vector x0:" << endl;
    x.print();

    matrix r = b - A * x;
    matrix z = r;

    bool first = 1;
    for (int k = 1; ; k++) {
        double na = (r % r) / ((A * z) % z);
        matrix nx = x + z * na;
        matrix nr = r - A * z * na;
        double nb = (nr % nr) / (r % r);
        matrix nz = nr + z * nb;

        cout << "vector x" << k << endl;
        nx.print();
        x = nx;
        r = nr;
        z = nz;

        if (r.norm() / b.norm() < EPS) {
            if (!first) {
                break;
            }
            cout << k << " iterations" << endl;
            first = 0;
        }
    }

    cout << "r: ";
    r.print();
    cout << endl;
}

void fast_descent(const matrix &A, const matrix &b) {
    cout << "fast descent" << endl;
    cout << "matrix A:" << endl;
    A.print();
    cout << "vector B:" << endl;
    b.print();

    srand(111333);
    int n = A.n;
    matrix x(n, 1);
    for (int i = 0; i < n; i++) {
        x[i][0] = b[i][0] / A[i][i];
    }
    cout << "vector x0:" << endl;
    x.print();

    const double EPS = 1e-8;
    for (int k = 1; (A * x - b).norm() >= EPS; k++) {
        matrix y = (A * x - b) * 2;
        double AA = (A * y) % y;
        double BB = (A * y) % x + (A * x) % y - (y % b) * 2;
        double CC = (A * x) % x - (x % b) * 2;

        double t = -BB / (2 * AA);
        matrix nx = (x + y * t);        
        cout << "vector x" << k << endl;
        x = nx;
        x.print();
    }
    cout << endl;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("task.out", "w", stdout);
    int n = 5;
    matrix a;
    matrix b(n, 1);
    for (int i = 0; i < n; i++) {
        b[i][0] = rand() % 30 - 11;
    }

    a = gen(n);
    conjugate_gradients(a, b);
    fast_descent(a, b);

    // Hilbert
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = 1.0 / (i + j + 2);
        }
    }
    conjugate_gradients(a, b);
    //fast_descent(a, b);

    return 0;
}
