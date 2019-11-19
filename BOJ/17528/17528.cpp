#include<bits/stdc++.h>

using namespace std;

using lld = long long int;
using lf = long double;
using uint = unsigned int;
using ulld = unsigned long long int;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N, A[255], B[255], D[255][62505];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i] >> B[i];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < 62500; j++)
            D[i][j] = 10000000;
    D[0][A[0]] = 0;
    D[0][0] = B[0];
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 62500; j++) {
            if (j + A[i] <= 62500)
                D[i][j+A[i]] = min(D[i][j+A[i]], D[i-1][j]);
            D[i][j] = min(D[i][j], D[i-1][j] + B[i]);
        }
    }
    int rst = INT_MAX;
    for (int i = 0; i <= 62500; i++)
        rst = min(rst, max(i, D[N-1][i]));
    cout << rst;
    return 0;
}