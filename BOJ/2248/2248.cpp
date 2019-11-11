#include<bits/stdc++.h>

using namespace std;

using lld = long long int;
using llf = long double;
using uint = unsigned int;
using ulld = unsigned long long int;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int D[32][32];
char rst[32];
int N, L;
lld I;

int DP(int n, int l) {
    int& ret = D[n][l];
    if (ret != -1) return ret;
    if (n == 0 || l == 0) return ret = 1;
    ret = DP(n-1, l);
    if (l) ret += DP(n-1, l-1);
    return ret;
}

void f(int n, int l, int i, int p) {
    if (!n) return;
    if (!l) {
        for (int i = 0; i < n; i++)
            rst[p+i] = '0';
        return;
    }
    int t = DP(n-1, l);
    if (i < t) {
        rst[p] = '0';
        f(n-1, l, i, p+1);
    } else {
        rst[p] = '1';
        f(n-1, l-1, i-t, p+1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> L >> I;
    memset(D, -1, sizeof(D));
    f(N, L, I-1, 0);
    for (int i = 0; i < N; i++)
        cout << rst[i];
    return 0;
}