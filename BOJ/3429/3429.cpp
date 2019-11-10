#include<bits/stdc++.h>

using namespace std;

using lld = long long int;
using llf = long double;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int Z, N, A[200005], L[200005], T[200005];
pii R[200005];

struct segTree {
    int tree[800005];
    void segTreeInit() {
        for (int i = 0; i < 800005; i++) tree[i] = 0;
    }
    int update(int n, int nl, int nr, int i, int v) {
        if (i < nl || i > nr) return tree[n];
        if (nl == nr) return tree[n] = max(tree[n], v);
        int mid = (nl + nr) / 2;
        int a = update(2*n, nl, mid, i, v);
        int b = update(2*n+1, mid+1, nr, i, v);
        return tree[n] = max(tree[n], max(a, b));
    }
    int query(int n, int nl, int nr, int l, int r) {
        if (l > r) return 0;
        if (r < nl || l > nr) return 0;
        if (l <= nl && nr <= r) return tree[n];
        int mid = (nl + nr) / 2;
        int a = query(2*n, nl, mid, l, r);
        int b = query(2*n+1, mid+1, nr, l, r);
        return max(a, b);
    }
} seg;

bool f(pii a, pii b) {
    return a.first < b.first;
}

inline int getX(int x) {
    return lower_bound(R, R+N, (pii){x, 0}) - R + 1;
}

int solve() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    seg.segTreeInit();
    L[0] = 1;
    for (int i = 1; i < N; i++) {
        if (A[i] > A[i-1])
            L[i] = L[i-1] + 1;
        else 
            L[i] = 1;
    }
    R[N-1] = {A[N-1], 1};
    T[N-1] = 1;
    for (int i = N-2; i >= 0; i--) {
        if (A[i] < A[i+1]) 
            R[i] = {A[i], R[i+1].second + 1};
        else
            R[i] = {A[i], 1};
        T[i] = R[i].second;
    }
    sort(R, R+N);
    for (int i = 0; i < N; i++)
        A[i] = getX(A[i]);
    int ret = 0;
    for (int i = N-1; i >= 0; i--) {
        ret = max(ret, L[i] + seg.query(1, 1, N, A[i]+1, N));
        //cout << A[i] << ' ' << L[i] << ' ' << seg.query(1, 1, N, A[i]+1, N) << endl;
        seg.update(1, 1, N, A[i], T[i]);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> Z;
    while (Z--) {
        cout << solve() << '\n';
    }
    return 0;
}