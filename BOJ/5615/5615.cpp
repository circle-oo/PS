#include<bits/stdc++.h>

using namespace std;

using lld = long long int;
using lf = long double;
using uint = unsigned int;
using ulld = unsigned long long int;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int T;
lld R;

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

bool MR(ulld n, ulld a) {
    if (n % a == 0) return 0;
    int cnt = -1;
    ulld d = n-1;
    while (!(d&1)) {
        d /= 2;
        cnt++;
    }
    ulld p = lpow(a, d, n);
    if (p == 1 or p == n-1) return 1;
    while (cnt--) {
        p = mul(p, p, n);
        if (p == n-1) return 1;
    }
    return 0;
}

bool isPrime(lld n) {
    for (auto p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == p) return 1;
        if (n > 40 && !MR(n, p)) return 0;
    }
    if (n <= 40) return 0;
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        lld N, M;
        vector<lld> P;
        cin >> N;
        M = 2*N + 1;
        if (isPrime(M)) R++;
    }
    cout << R;
    return 0;
}