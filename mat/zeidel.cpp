#include <iostream>
#include <cmath>

using namespace std;

const int MAX_N = 110;
const double eps = 1e-9;
double a[MAX_N][MAX_N], b[MAX_N], x[MAX_N], y[MAX_N];

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
        error = 0;
        for (i = 0; i < n; i++) {
            y[i] = (b[i] / a[i][i]);
            for (j = 0; j < n; j++) {
                if (j == i) continue;
                y[i] = y[i] - ((a[i][j] / a[i][i]) * x[j]);
            }
            error = max(error, fabs(y[i] - x[i]));
            x[i] = y[i];
            //printf("x%d = %.1lf     ", i + 1, y[i]);
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
