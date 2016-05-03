#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <map>
#include <string>
#include <algorithm>
#include <cassert>
#include <fstream>

#include "matrix.hpp"

using namespace std;

Matrix input(std::istream& s) {
    size_t n, m;
    double tmp;
    s >> n >> tmp;
    m = n;
    Matrix ans(n, m);
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            s >> ans.a[i][j];
        }
    }
    return ans;
}

int main() {
    //std::ifstream fin("cond.in");
    Matrix a(input(cin));
    cout << "Cond: " << a.norm() * a.inverse().norm() << "\n";
    return 0;
}
