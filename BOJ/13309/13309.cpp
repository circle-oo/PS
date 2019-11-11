#include<bits/stdc++.h>

using namespace std;

using lld = long long int;
using llf = long double;
using uint = unsigned int;
using ulld = unsigned long long int;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N, Q;
int par[200005][22], depth[200005], p[200005];

//for ETT and tree segment
vector<int> edge[200005];
int in[200005], out[200005], t;

struct segTree { //for RMQ when we find maximum depth
    lld tree[800005], lazy[800005];
    segTree() {
        for (int i = 0; i < 800005; i++) {
            tree[i] = 0;
            lazy[i] = 0;
        }
    }
    void lazyp(int n, int nl, int nr) {
        if (!lazy[n]) return;
        tree[n] = max(tree[n], lazy[n]);
        if (nl != nr) {
            lazy[2*n] = max(lazy[2*n], lazy[n]);
            lazy[2*n+1] = max(lazy[2*n+1], lazy[n]);
        }
        lazy[n] = 0;
    }
    lld update(int n, int nl, int nr, int l, int r, lld v) {
        lazyp(n, nl, nr);
        if (r < nl || nr < l) return tree[n];
        if (l <= nl && nr <= r) {
            lazy[n] = max(lazy[n], v);
            lazyp(n, nl, nr);
            return tree[n];
        }
        int mid = (nl+nr)/2;
        lld a = update(2*n, nl, mid, l, r, v);
        lld b = update(2*n+1, mid+1, nr, l, r, v);
        return tree[n] = max(a, b);
    }
    lld query(int n, int nl, int nr, int l, int r) {
        lazyp(n, nl, nr);
        if (r < nl || l > nr) return -INT_MAX;
        if (l <= nl && r >= nr) return tree[n];
        int mid = (nl+nr)/2;
        lld a = query(2*n, nl, mid, l, r);
        lld b = query(2*n+1, mid+1, nr, l, r);
        return max(a, b);
    }
} seg;

void euler(int root) {
    in[root] = ++t;
    for (auto& e: edge[root]) 
        euler(e);
    out[root] = t;
}

void dfs(int root) {
    for (auto& e: edge[root]) {
        depth[e] = depth[root] + 1;
        dfs(e);
    }
}

bool lca(int x, int y) {
    int lx = depth[x] - seg.query(1, 1, N, in[x], in[x]);
    int ly = depth[y] - seg.query(1, 1, N, in[y], in[y]);
    for (int i = 20; i >= 0; i--) {
        if (par[x][i] && lx >= (1 << i)) {
            lx -= (1 << i);
            x = par[x][i];
        }
    }
    for (int i = 20; i >= 0; i--) {
        if (par[y][i] && ly >= (1 << i)) {
            ly -= (1 << i);
            y = par[y][i];
        }
    }
    return x == y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> Q;
    for (int i = 2; i <= N; i++) {
        cin >> par[i][0];
        edge[par[i][0]].push_back(i);
    }
    euler(1);
    dfs(1);
    for (int i = 1; i <= 20; i++)
        for (int j = 1; j <= N; j++)
            par[j][i] = par[par[j][i-1]][i-1];
    
    while (Q--) {
        int x, y, z;
        cin >> x >> y >> z;
        if (z) {
            bool k = lca(x, y);
            cout << (k ? "YES" : "NO") << "\n";
            if (k)
                seg.update(1, 1, N, in[x], out[x], depth[x]);
            else
                seg.update(1, 1, N, in[y], out[y], depth[y]);
        } else {
            cout << (lca(x, y) ? "YES" : "NO") << "\n";
        }
    }
    return 0;
}