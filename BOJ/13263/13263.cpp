#include<bits/stdc++.h>

using namespace std;

using lld = long long int;
using lf = long double;
using uint = unsigned int;
using ulld = unsigned long long int;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct Linear{
    lld a, b;
    double s;
    Linear(): Linear(1, 0){}
    Linear(lld a1, lld b1): a(a1), b(b1), s(0){}
};

int N;
lld A[100005], B[100005];
lld D[100005];

inline double cross(Linear &f, Linear &g) {
    return (g.b - f.b) / (f.a - g.a);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
        cin >> B[i];
    Linear L[100005];
    int top = 0, fpos = 0;
    for (int i = 1; i < N; i++) {
        Linear g(B[i-1], D[i-1]);
        while (top > 0) {
            g.s = cross(L[top-1], g);
            if (L[top-1].s < g.s) break;
            if (--top == fpos) --fpos;
        }
        L[top++] = g;
        lld x = A[i];
        while (fpos+1 < top && L[fpos+1].s < x) ++fpos;
        D[i] = L[fpos].a * x + L[fpos].b;
    }
    cout << D[N-1];
    return 0;
}
