#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <map>
#include <string>
#include <algorithm>
#include <cassert>
#include <fstream>
using namespace std;

struct Matrix
{
    Matrix() {}
    Matrix(size_t n, size_t m) {
        resize(n, m);
    }

    size_t n() const { 
        return a.size();
    }

    size_t m() const {
        return !a.empty() ? a[0].size() : 0;
    }

    void resize(size_t n, size_t m) {
        a.resize(n);
        for (size_t i = 0; i < n; i++) {
            a[i].resize(m);
        }
    }

    double det() const {
        assert(n() == m());
        if (n() != m()) return 0;
        double det = 1;
        vector< vector<double> > b(a);
        for (size_t i=0; i<n(); ++i) {
            size_t k = i;
            for (size_t j=i+1; j<n(); ++j)
                if (abs (b[j][i]) > abs (b[k][i]))
                    k = j;
            if (abs (b[k][i]) < 1e-9) {
                det = 0;
                break;
            }
            swap (b[i], b[k]);
            if (i != k)
                det = -det;
            det *= b[i][i];
            for (size_t j=i+1; j<n(); ++j)
                b[i][j] /= b[i][i];
            for (size_t j=0; j<n(); ++j)
                if (j != i && abs (b[j][i]) > 1e-9)
                    for (size_t k=i+1; k<n(); ++k)
                        b[j][k] -= b[i][k] * b[j][i];
        }
        return det;
    }

    Matrix transponite() const {
        Matrix b(m(), n());
        for (size_t i = 0; i < n(); ++i) {
            for (size_t j = 0; j < m(); ++j) {
                b.a[i][j] = a[j][i];
            }
        }
        return b;
    }

    Matrix algebraic() const {
        Matrix b(n(), m());
        for (size_t i = 0; i < n(); ++i) {
            for (size_t j = 0; j < m(); ++j) {
                Matrix tmp(n() - 1, m() - 1);
                for (size_t k = 0; k < n() - 1; ++k) {
                    for (size_t l = 0; l < m() - 1; ++l) {
                        tmp.a[k][l] = a[k < i ? k : k + 1][l < j ? l : l +1];
                    }
                }
                b.a[i][j] = tmp.det();
                if ((i+j) % 2 == 1) {
                    b.a[i][j] *= -1;
                }
            }
        }
        return b.transponite();
    }

    Matrix inverse() const {
        assert(n() == m());
        return algebraic() * (1.0 / det());
    }

    Matrix operator*(double alpha) const {
        Matrix b(*this);
        for (size_t i = 0; i < n(); ++i) {
            for (size_t j = 0; j < m(); ++j) {
                b.a[i][j] *= alpha;
            }
        }
        return b;
    }

    double norm() const {
        double result = 0;
        for (size_t i = 0; i < n(); i++) {
            double tmp = 0;
            for (size_t j = 0; j < m(); j++) {
                tmp += std::fabs(a[i][j]);
            }
            result = max(result, tmp);
        }
        return result;
    }

    vector< vector<double> > a;
};
