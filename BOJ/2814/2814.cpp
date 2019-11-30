#include<bits/stdc++.h>

using namespace std;

using lld = long long int;
using lf = long double;
using uint = unsigned int;
using ulld = unsigned long long int;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

lld N, P;
vector<lld> A;

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
    cin >> N >> P;
    for (int i = 2; i <= sqrt(1e9); i++)
        if (isPrime(i))
            A.push_back(i);
    if (N == 1) {
        cout << P;
        return 0;
    }
    if (P > A[A.size()-1]) {
        cout << 0;
        return 0;
    }
    if (P == 2) {
        cout << ((__int128)P * N > 1e9 ? 0 : P * N);
        return 0;
    }
    vector<lld> B, C;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] >= P)
            C.push_back(A[i]);
        else if (A[i] % 2)
            B.push_back(A[i]);
    }
    int k = 1;
    for (lld x = P*P; x <= 1e9; x += 2*P) {
        bool isDivided = false;
        for (lld i : B) {
            if (x % i == 0) {
                isDivided = true;
                break;
            }
        }
        if (!isDivided) {
            k++;
        }
        if (k == N) {
            cout << x;
            return 0;
        }
    }
    cout << 0;
    return 0;
}