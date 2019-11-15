#include<bits/stdc++.h>

using namespace std;

using lld = long long int;
using llf = long double;
using uint = unsigned int;
using ulld = unsigned long long int;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

lld N, R;
lld P = 1000000007;
lld A[4000005], B[4000005]; //A[n] = n!, B[n] = inverse of n!

lld extended_gcd(lld a, lld b) {
    lld s = 0, old_s = 1;
    lld t = 1, old_t = 0;
    lld r = b, old_r = a;

    while (r != 0) {
        lld q = old_r / r;
        lld x, y, z;
        x = old_r - q * r;
        y = old_s - q * s;
        z = old_t - q * t;
        old_r = r;
        r = x;
        old_s = s;
        s = y;
        old_t = t;
        t = z;
    }
    return old_s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> R;
    A[0] = 1;
    A[1] = 1;
    for (int i = 2; i <= N; i++) {
        A[i] = A[i-1] * i;
        A[i] %= P;
    }

    lld K = extended_gcd(A[N-R], P);
    lld L = extended_gcd(A[R], P);
    lld rst = A[N] * K;
    rst %= P;
    rst *= L;
    rst %= P;
    if (rst == 0)
        cout << 1;
    else if (rst < 0)
        cout << rst + P;
    else 
        cout << rst;
    return 0;
}