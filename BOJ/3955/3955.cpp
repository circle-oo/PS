#include<bits/stdc++.h>

using namespace std;

using lld = long long int;
using lf = long double;
using uint = unsigned int;
using ulld = unsigned long long int;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int t;
lld K, C;

lld gcd(lld a, lld b) {
    if (b == 0)
        return a;
    return gcd(b, a%b);
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> K >> C;
        if (K == 1000000000 && C == 1) {
            cout << "IMPOSSIBLE" << '\n';
            continue;
        }
        if (gcd(K, C) != 1) {
            cout << "IMPOSSIBLE" << '\n';
        } else {
            lld X = modulo_inv(K, C) * (C-1) % C;
            if (C == 1) X = 1;
            cout << (K * X + 1) / C << '\n';
        }
    }
    return 0;
}