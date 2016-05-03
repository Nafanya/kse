#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(int argc, char** argv) {
    if (argc != 3) {
        return cout << "wrong input\n", 0;
    }
    int n = atoi(argv[1]);
    cout << n << endl;
    if (argv[2][0] == 'd') {
        int a[n][n];
        int k = 10;
        for(int i = 0; i < n; i++, cout << endl) {

            for(int j = 0; j < n; j++) {
                a[i][j] = 1 + (i == j) * (k - 1);
                cout << a[i][j] << " ";
            }
        }
        for(int i = 0; i < n; i++) {
            cout << n + k - 1 << " ";
        }
    } else {
        double a[n][n];
        for(int i = 0; i < n; i++, cout << endl) {
            for(int j = 0; j < n; j++) {
                a[i][j] = 1.0 / (i + j + 2);
                printf("%.15lf ", a[i][j]);
            }
        }
        for(int i = 0; i < n; i++) {
            double rnd = (1.0 * rand()) / (1 << 28);
            printf("%.15lf ", rnd);
        }
    }
    return 0;
}

//g++ gen.cpp -o gen && ./gen 10 g
