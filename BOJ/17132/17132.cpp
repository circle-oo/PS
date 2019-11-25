#include<bits/stdc++.h>

using namespace std;

using lld = long long int;
using lf = long double;
using uint = unsigned int;
using ulld = unsigned long long int;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N;
vector<pair<int, pii>> A;
lld par[100005], siz[100005];
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N-1; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        A.push_back({w, {x, y}});
    }
    sort(A.begin(), A.end(), greater<pair<int, pii>>());
    for (int i = 1; i <= N; i++) {
        par[i] = i;
        siz[i] = 1;
    }
    for (int i = 0; i < N-1; i++) {
        lld w = A[i].first;
        int l = A[i].second.first;
        int r = A[i].second.second;
        rst += w * siz[find(l)] * siz[find(r)];
        //cout << w << ' ' << siz[find(l)] << ' ' <<  siz[find(r)] << endl;
        merge(l, r);
    }
    cout << rst;
    return 0;
}