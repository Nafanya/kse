#include <iostream>
#include <cmath>

using namespace std;

const int MAX_N = 110;
const double eps = 1e-9;
double a[MAX_N][MAX_N], b[MAX_N], x[MAX_N], x_new[MAX_N];

int main() {
    int n = 0, i = 0, j = 0;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (i = 0; i < n; i++) {
        cin >> x[i];
    }
    double error = 1;
    int cnt = 0;
    while (error >= eps) {
        for (i = 0; i < n; i++) {
            x_new[i] = (b[i] / a[i][i]);
            for (j = 0; j < n; j++) {
                if (j == i) continue;
                x_new[i] -= ((a[i][j] / a[i][i]) * x[j]);
            }
        }
        error = 0;
        for(int i = 0; i < n; i++) {
            error = max(error, fabs(x_new[i] - x[i]));
            x[i] = x_new[i];
        }
        //cout << error << endl;
        cnt++;
    }
    cout << "Iterations: " << cnt << endl;
    for(int i = 0; i < n; i++) {
        cout << "x[" << (i + 1) << "] = " << x[i] << endl;
    }
    return 0;
}

