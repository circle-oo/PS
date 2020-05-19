#include<bits/stdc++.h>

using namespace std;

using lld = long long int;
using lf = long double;
using uint = unsigned int;
using ulld = unsigned long long int;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N, Q;
lld tree[2000005];

lld sum(int i) {
    lld ret = 0;
    while (i > 0) {
        ret += tree[i];
        i -= (i & -i);
    }
    return ret;
}

void update(int i, lld d) {
    while (i < N+1) {
        tree[i] += d;
        i += (i & -i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> Q;
    while (Q--) {
        lld a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
            update(b, c);
        if (a == 2)
            cout << sum(c) - sum(b-1) << '\n';
    }
    return 0;
}