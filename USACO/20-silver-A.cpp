#include<bits/stdc++.h>

using namespace std;

int N;
vector<int> V[100005];
int a[100005];
int vis[100005];

void dfs(int x) {
    vis[x] = 1;
    int r = 0;
    for (auto u: V[x]) {
        if (!vis[u]) {
            dfs(u);
            r++;
        }
    }
    a[x] = r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N-1; i++) {
        int x, y;
        cin >> x >> y;
        V[x].push_back(y);
        V[y].push_back(x);
    }
    long long rst = 0;
    dfs(1);
    for (int i = 1; i <= N; i++)
        if (a[i] != 0)
            rst += (int)ceil(log2(a[i]+1));
    
    cout << rst + N - 1;
    return 0;
}