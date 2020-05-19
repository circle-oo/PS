#include<bits/stdc++.h>

using namespace std;

using lld = long long int;
using lf = long double;
using uint = unsigned int;
using ulld = unsigned long long int;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

const lld MOD = 1000000000;

struct M {
    lld data[2][2];
};

M mult(M a, M b) {
    M c;
    c.data[0][0] = (a.data[0][0] * b.data[0][0] + a.data[0][1] * b.data[1][0]) % MOD;
	c.data[0][1] = (a.data[0][0] * b.data[0][1] + a.data[0][1] * b.data[1][1]) % MOD;
	c.data[1][0] = (a.data[1][0] * b.data[0][0] + a.data[1][1] * b.data[1][0]) % MOD;
	c.data[1][1] = (a.data[1][0] * b.data[0][1] + a.data[1][1] * b.data[1][1]) % MOD;
    return c;
}

M div(M a, lld n) {
    if (n > 1) {
        a = div(a, n/2);
        a = mult(a, a);
        if (n % 2 == 1) {
            M b;
            b.data[0][0] = 1; b.data[0][1] = 1;
            b.data[1][0] = 1; b.data[1][1] = 0;
            a = mult(a, b);
        }
    }
    return a;
}


lld f(lld x) {
    M a;
    a.data[0][0] = 1; a.data[0][1] = 1;
    a.data[1][0] = 1; a.data[1][1] = 0;
    a = div(a, x);
    return a.data[0][1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    lld a, b;
    cin >> a >> b;
    cout << (f(b+2) % MOD - f(a+1)%MOD + MOD) % MOD;
    
    return 0;
}