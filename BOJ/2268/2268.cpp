#include<bits/stdc++.h>

using namespace std;

using lld = long long int;
using llf = long double;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct segTree {
    lld tree[4000005];
    void segTreeInit() {
        for (int i = 0; i < 4000005; i++) tree[i] = 0;
    }
    lld update(int n, int nl, int nr, int i, lld v) {
        if (i < nl || i > nr) return tree[n];
        if (nl == nr) return tree[n] = v;
        lld mid = (nl + nr) / 2;
        lld a = update(2*n, nl, mid, i, v);
        lld b = update(2*n+1, mid+1, nr, i, v);
        return tree[n] = a+b;
    }
    lld query(int n, int nl, int nr, int l, int r) {
        if (l > r) return 0;
        if (r < nl || l > nr) return 0;
        if (l <= nl && nr <= r) return tree[n];
        lld mid = (nl + nr) / 2;
        lld a = query(2*n, nl, mid, l, r);
        lld b = query(2*n+1, mid+1, nr, l, r);
        return a+b;
    }
} seg;

int N, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    seg.segTreeInit();
    while (M--) {
        lld a, x, y;
        cin >> a >> x >> y;
        if (a == 0) {
            if (x > y) swap(x, y);
            cout << seg.query(1, 1, N, x, y) << '\n';
        }
        if (a == 1) {
            seg.update(1, 1, N, x, y);
        }
    }
    return 0;
}