#include<bits/stdc++.h>

using namespace std;

using lld = long long int;
using llf = long double;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N;
int x[1005], y[1005], mx, my, A[1005][1005], P[1005][1005];
unordered_map<int, int> xH, yH;
set<int> xS, yS;

int f(int a, int b, int c, int d) {
    return P[c][d] - P[a][d] - P[c][b] + P[a][b];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
        xS.insert(x[i]);
        yS.insert(y[i]);
    }
    for (int i: xS)
        xH[i] = mx++;
    for (int i: yS)
        yH[i] = my++;
    
    for (int i = 0; i < N; i++)
        A[xH[x[i]]][yH[y[i]]]++;
    
    for (int i = 0; i < mx; i++)
        for (int j = 0; j < my; j++)
            P[i+1][j+1] = P[i][j+1] + P[i+1][j] - P[i][j] + A[i][j];

    int ret = N;
    for (int i = 0; i <= mx; i++) {
        for (int j = 0; j <= my; j++) {
            int tmp = max(f(0, 0, i, j), f(0, j, i, my));
            tmp = max(tmp, f(i, 0, mx, j));
            tmp = max(tmp, f(i, j, mx, my));
            ret = min(ret, tmp);
        }
    } 
    cout << ret;
    return 0;
}