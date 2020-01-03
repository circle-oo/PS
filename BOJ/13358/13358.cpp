#include<bits/stdc++.h>

using namespace std;

using lld = long long int;
using lf = long double;
using uint = unsigned int;
using ulld = unsigned long long int;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

lld a, b, c;


ulld mul(ulld x, ulld y, ulld m) {
    return (ulld)((__int128)x * y % m);
}

ulld lpow(ulld x, ulld y, ulld m) {
    ulld r = 1;
    while (y) {
        if (y&1) r = mul(r, x, m);
        x = mul(x, x, m);
        y >>= 1;
    }
    return r;
}

lld f(lld n) {
    lld ret = n;
	lld p = 2;
	while(p*p <= n){
		if(n%p == 0) ret = ret / p * (p - 1);
		while(n%p == 0) n /= p;
		p++;
	}
	if(n != 1) ret = ret / n * (n - 1);
	return ret;
}

lld g(lld N, lld M) {
    if (N == 1) return 1;
    return lpow(N, g(N-1, M) % f(M), M);
}

lld s(lld n, lld m) {
    if (m == 1) return 1;
    if (n <= 5) return g(n, m);
    return lpow(n, s(n-1, f(m)) + f(m), m);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a >> b;
    c = f(b);
    cout << s(a, b) % b;
    return 0;
}