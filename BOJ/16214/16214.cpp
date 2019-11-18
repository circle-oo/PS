#include<bits/stdc++.h>

using namespace std;

using lld = long long int;
using lf = long double;
using uint = unsigned int;
using ulld = unsigned long long int;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int T;


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

lld modulo_inv(lld a, lld m) {
    lld m0 = m, y = 0, x = 1;
    if (m == 1)
        return 0;
    while (a > 1) {
        lld q = a / m;
        lld t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0) x += m0;
    return x;
}

lld totient(lld x) {
    vector<lld> P;
    lld y = x;
    for (int i = 2; i <= sqrt(x); i++) {
        while (!(y%i)) {
            P.push_back(i);
            y /= i;
        }
    }
    if (y != 1) P.push_back(y);
    P.erase(unique(P.begin(), P.end()), P.end());
    sort(P.begin(), P.end());
    for (lld& i : P)
        x = x - x / i;
    return x;
}

lld getm1(lld a, lld b) {
    lld d = gcd(a, b);
    lld r = 1;
    vector<lld> P;
    lld y = d;
    for (int i = 2; i <= sqrt(d); i++) {
        while (!(y%i)) {
            P.push_back(i);
            y /= i;
        }
    }
    if (y != 1) P.push_back(y);
    P.erase(unique(P.begin(), P.end()), P.end());
    sort(P.begin(), P.end());
    for (lld& i : P) {
        while (b % i == 0) {
            r *= i;
            b /= i;
        }
    }
    return r;
}

lld solve(lld N, lld M) {
    if (M == 1)
        return 0;
    if (gcd(N, M) == 1) {
        lld K = totient(M);
        return lpow(N, solve(N, K), M);
    } else {
        lld m1 = getm1(N, M);
        lld m2 = M / m1;
        return (m1 * modulo_inv(m1, m2) % M) * solve(N, m2) % M;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        lld N, M;
        cin >> N >> M;
        cout << solve(N, M) << '\n';
    }
    return 0;
}