#include<bits/stdc++.h>

using namespace std;

using lld = long long int;
using lf = long double;
using uint = unsigned int;
using ulld = unsigned long long int;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N;
vector<pii> A;
bool c[1000005];
lld par[1000005], siz[1000005];
lld rst;

int find(int x) {
    if (x == par[x])
        return x;
    return par[x] = find(par[x]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (siz[v] > siz[u])
        swap(u, v);
    par[v] = u;
    siz[u] += siz[v];
}

void init() {
    for (int i = 0; i <= N+1; i++) {
        par[i] = i;
        siz[i] = 0;
        c[i] = false;
    }
}

lld solve() {
    lld rst = 0;
    for (int i = 0; i < N; i++) {
        lld w = A[i].first;
        int p = A[i].second;
        c[p] = true;
        siz[find(p)] = 1;
        rst += w * (siz[find(p-1)]+1) * (siz[find(p+1)]+1);
        //cout << w << ' ' << w * (siz[find(p-1)]+1) * (siz[find(p+1)]+1) << endl;
        if (p-1 >= 1 && c[p-1])
            merge(p, p-1);
        if (p+1 <= N && c[p+1])
            merge(p, p+1);
    }
    return rst;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        A.emplace_back(x, i);
    }
    lld rst = 0;
    init();
    sort(A.begin(), A.end());
    rst += solve();
    //cout << solve() << endl;
    init();
    sort(A.begin(), A.end(), greater<pii>());
    rst -= solve();
    //cout << solve() << endl;
    cout << rst;
    return 0;
}