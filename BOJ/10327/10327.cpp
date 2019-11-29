#include<bits/stdc++.h>

using namespace std;

using lld = long long int;
using lf = long double;
using uint = unsigned int;
using ulld = unsigned long long int;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int f[100];
int T;
lld N;

bool cmp(int x, int y, int a, int b) {
    return (y < b || y == b && x < a);
}

tuple<lld, lld, lld> extended_euclidean(lld a, lld b) {
    if (b == 0)
        return make_tuple(a, 1, 0);
    lld g, x, y;
    tie(g, x, y) = extended_euclidean(b, a%b);
    return make_tuple(g, y, x-(a/b)*y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    f[1] = 1;
    for (int i = 2; i < 50; i++) {
        f[i] = f[i-1] + f[i-2];
    }
    cin >> T;
    while (T--) {
        cin >> N;
        lld a = 1, b = N-1;
        for (int i = 2; i < 50; i++) {
            if (N % f[i]) continue;
            lld x = N / f[i], y = N / f[i];
            if (cmp(x, y, a, b)) {
                a = x;
                b = y;
            }
        }
        for (int i = 2; f[i] < N; i++) {
            lld g, x, y;
            tie(g, x, y) = extended_euclidean(f[i-1], f[i]);
            //cout << f[i-1] << ' ' << f[i] << " / ";
            x *= N;
            y *= N;
            //cout << x << ' ' << y << " / ";
            lld p = x, q = y;
            lld k = -x / f[i];
            //cout << k << " / ";
            if ((i) % 2 == 0 && x % f[i]) k++;
            x += k * f[i];
            y -= k * f[i-1];
            p = x + f[i];
            q = y - f[i-1];
            if(cmp(x, y, a, b) && (x <= y) && (x > 0)) {
                a = x;
                b = y;
            }
            if(cmp(p, q, a, b) && (p <= q) && (p > 0)) {
                a = p;
                b = q;
            }
            //cout << x << ' ' << y << endl;
        }
        cout << a << ' ' << b << ' ' << '\n';
    }
    return 0;
}