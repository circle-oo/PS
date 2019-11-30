#include<bits/stdc++.h>

using namespace std;

using lld = long long int;
using lf = long double;
using uint = unsigned int;
using ulld = unsigned long long int;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

lld P, B, N;

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> P >> B >> N) {
        lld L = LONG_MAX;
        lld k = sqrt(P);
        vector<pll> G, H;
        for (lld x = 0; x < P; x += k) {
            G.emplace_back(lpow(B, x, P), x);
            //cout << lpow(B, x, P) << endl;
        }
        for (lld x = 0; x < k; x++) {
            H.emplace_back((modulo_inv(lpow(B, x, P), P) * N) % P, x);
            //cout << (modulo_inv(lpow(B, x, P), P) * N) % P << endl;
        }
        sort(G.begin(), G.end());
        sort(H.begin(), H.end());
        int a = 0, b = 0;
        while (a < G.size() && b < H.size()) {
            //cout << G[a].first << ' ' << H[b].first << endl;
            if (G[a].first < H[b].first)
                a++;
            else if (G[a].first > H[b].first)
                b++;
            else {
                L = min(L, G[a].second + H[b].second);
                a++;
                b++;
            }
        }
        if (L == LONG_MAX) 
            cout << "no solution\n";
        else 
            cout << L << '\n';
    }
    return 0;
}
