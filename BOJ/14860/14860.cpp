#include<bits/stdc++.h>

using namespace std;

using lld = long long int;
using lf = long double;
using uint = unsigned int;
using ulld = unsigned long long int;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

const lld MOD = 1e9 + 7;
lld N, M;
lld rst = 1;

lld v[15000005];

ulld mul(ulld x, ulld y, ulld m) {
    return (ulld)((__int128)x * y % m);
}

ulld lpow(ulld x, ulld y, ulld m) {
    ulld r = 1;
    x %= m;
    while (y) {
        if (y&1) r = mul(r, x, m);
        x = mul(x, x, m);
        y >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (lld i = 2; i <= N; i += 1) {
        lld t = 0;
        if (!v[i]) {
            for (lld j = i; j <= N; j *= i) t += (N/j) * (M/j);
            rst = mul(rst, lpow(i, t, MOD), MOD);
            for (lld j = 2*i; j <= N; j += i) v[j] = true;
        }
    }
    cout << rst % MOD;
    return 0;
}