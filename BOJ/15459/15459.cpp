#include<bits/stdc++.h>

using namespace std;

using lld = long long int;
using lf = long double;
using uint = unsigned int;
using ulld = unsigned long long int;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N;
lld M;
lld F[100005], S[100005], G[100005];
vector<lld> R;

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
        return tree[n] = max(a, b);
    }
    lld query(int n, int nl, int nr, int l, int r) {
        if (l > r) return 0;
        if (r < nl || l > nr) return 0;
        if (l <= nl && nr <= r) return tree[n];
        lld mid = (nl + nr) / 2;
        lld a = query(2*n, nl, mid, l, r);
        lld b = query(2*n+1, mid+1, nr, l, r);
        return max(a, b);
    }
} seg;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> F[i] >> S[i];
    for (int i = 1; i <= N; i++)
        G[i] = G[i-1] + F[i];
    for (int i = 1; i <= N; i++)
        seg.update(1, 1, N, i, S[i]);
    for (int i = 1; i <= N; i++) {
        int j = lower_bound(G, G+N, G[i] - M) - G;
        if (G[i] - G[j] < M)
            j--;
        if (j == -1)
            continue;
        R.push_back(seg.query(1, 1, N, j+1, i));
    }
    sort(R.begin(), R.end());
    cout << R[0];
    return 0;
}