#include<bits/stdc++.h>

using namespace std;

using lld = long long int;
using llf = long double;
using uint = unsigned int;
using ulld = unsigned long long int;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

pii I[75005];
int T;
int N, B[75005];

bool comp(pii a, pii b) {
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

struct segTree {
    lld tree[400005];
    segTree() {
        for (int i = 0; i < 400005; i++) tree[i] = 0;
    }
    void segTreeInit() {
        for (int i = 0; i < 400005; i++) tree[i] = 0;
    }
    lld update(int n, int nl, int nr, int i, lld v) {
        if (i < nl || nr < i) return tree[n];
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--) {
        lld rst = 0;
        vector<int> y;
        seg.segTreeInit();
        memset(B, 0, sizeof(B));
        cin >> N;
        for (int i = 0; i < N; i++) {
            int a, b;
            cin >> a >> b;
            I[i] = {a, b};
            y.push_back(b);
        }
        sort(I, I+N, comp);
        sort(y.begin(), y.end());
        y.erase(unique(y.begin(), y.end()), y.end());
        for (int i = 0; i < N; i++) {
            int k = upper_bound(y.begin(), y.end(), I[i].second) - y.begin();
            rst += seg.query(1, 1, N, 0, k);
            B[k]++;
            seg.update(1, 1, N, k, B[k]);
        }
        cout << rst << '\n';
    }
    return 0;
}