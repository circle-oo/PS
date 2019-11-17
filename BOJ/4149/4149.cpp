#include<bits/stdc++.h>

using namespace std;

using lld = long long int;
using lf = long double;
using uint = unsigned int;
using ulld = unsigned long long int;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

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

lld gcd(lld a, lld b) {
    if (b == 0)
        return a;
    return gcd(b, a%b);
}

lld PollardRho(lld n) {
    lld x = rand()%(n-2) + 2;
    lld y = x;
    lld c = rand()%(n-1) + 1;
    while (true) {
        x = (mul(x, x, n) + c) % n;
        y = (mul(y, y, n) + c) % n;
        y = (mul(y, y, n) + c) % n;
        lld d = gcd(abs(x-y), n);
        if (d == 1) continue;
        if (!isPrime(d)) return PollardRho(d);
        else return d;
    }
}

void f(lld n, vector<lld>& v) {
    while (!(n&1)) {
        n >>= 1;
        v.push_back(2);
    }
    if (n == 1) return;
    while (!isPrime(n)) {
        lld d = PollardRho(n);
        while (n%d == 0) {
            v.push_back(d);
            n /= d;
        }
        if (n == 1) break;
    }
    if (n != 1) v.push_back(n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    lld N;
    cin >> N;
    if (N == 1) return 0;
    vector<lld> v;
    f(N, v);
    sort(v.begin(), v.end());
    for (auto e: v) cout << e << '\n';
    return 0;
}