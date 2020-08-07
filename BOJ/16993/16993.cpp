#include<bits/stdc++.h>

using namespace std;

using lld = long long int;
using lf = long double;
using uint = unsigned int;
using ulld = unsigned long long int;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

using ppi = pair<pii, int>;

const int inf = 1e9 + 5;

int a[100005], s[100005];

struct segTree {
    ppi tree[400005]; //lmax rmax mmax
    void init(int n, int nl, int nr) {
        if (nl == nr) {
            tree[n] = {{a[nl], a[nl]}, a[nl]};
            return;
        }
        int lsum = 0, rsum = 0, m = (nl + nr)/2;
        tree[n] = {{-inf, -inf}, -inf};
        for (int i = nr; i >= nl; i--) {
            lsum += a[i];
            tree[n].first.first = max(tree[n].first.first, lsum);
        }
        for (int i = nl; i <= nr; i++) {
            rsum += a[i];
            tree[n].first.second = max(tree[n].first.second, rsum);
        }
        init(2*n, nl, m); init(2*n+1, m+1, nr);
        tree[n].second = max({tree[2*n].second, tree[2*n+1].second, tree[2*n].first.first + tree[2*n+1].first.second});
    }

    ppi query(int n, int nl, int nr, int l, int r) {
        if (r < nl || nr < l) return {{-inf, -inf}, -inf};
        if (l <= nl && nr <= r) return tree[n];
        int m = (nl + nr)/2;
        ppi a = query(2*n, nl, m, l, r), b = query(2*n+1, m+1, nr, l, r), ret;
        ret.first.first = max(a.first.first + s[nr] - s[m], b.first.first);
        ret.first.second = max(b.first.second + s[m] - s[nl-1], a.first.second);
        ret.second = max({a.second, b.second, a.first.first + b.first.second});
        return ret;
    }
} seg;

int N, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
        s[i] = s[i-1] + a[i];
    }
    seg.init(1, 1, N);
    cin >> M;
    while (M--) {
        int l, r;
        cin >> l >> r;
        cout << seg.query(1, 1, N, l, r).second << '\n';
    }
    return 0;
}