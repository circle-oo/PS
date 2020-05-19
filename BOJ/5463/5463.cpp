#include<bits/stdc++.h>

using namespace std;

using lld = long long int;
using lf = long double;
using uint = unsigned int;
using ulld = unsigned long long int;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N, M;
int R[55][55], P[55][55];
int D[55][55][55][55];

int solve(int a, int b, int c, int d) {
    int& ret = D[a][b][c][d];
    if (a == c && b == d) return 0;
    if (ret != -1) return ret;
    ret = INT_MAX;
    for (int i = a; i < c; i++)
        ret = min(ret, solve(a, b, i, d) + solve(i+1, b, c, d) + P[c][d] - P[a-1][d] - P[c][b-1] + P[a-1][b-1]);
    for (int i = b; i < d; i++)
        ret = min(ret, solve(a, b, c, i) + solve(a, i+1, c, d) + P[c][d] - P[a-1][d] - P[c][b-1] + P[a-1][b-1]);
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(D, -1, sizeof(D));
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> R[i][j];
    
    P[1][1] = R[1][1];

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            P[i][j] = P[i][j-1] + P[i-1][j] - P[i-1][j-1] + R[i][j];
    
    cout << solve(1, 1, N, M);

    return 0;
}