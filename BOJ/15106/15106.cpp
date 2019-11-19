#include<bits/stdc++.h>

using namespace std;

using lld = long long int;
using llf = long double;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

lld a, b;

lld g(lld x, lld y) {
    return (lld)((__int128)y*(y+1)/2 - (__int128)x*(x+1)/2);
}

lld f(lld N) {
    lld R = 0;
    for (lld i = N; i != 0; i = N / (N/i + 1)) {
        //cout << i << ' ' << N/i + 1 << ' ' << g(N / (N/i + 1), i) << endl;
        R += (N/i) * g(N / (N/i + 1), i);
    }
    return R;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a >> b;
    cout << f(b) - f(a-1);
    return 0;
}