#include<bits/stdc++.h>

using namespace std;

int n;
int child[10005][2]; // -1 : X
int par[10005];
int lr[10005]; //-1 : l, 1 : r, 0 : root
int subt[10005]; // size of subtree
pair<int, int> coor[10005];
int rst[10005][2];

int dfs(int x) {
    if (x == -1) return 0;
    return subt[x] = dfs(child[x][0]) + dfs(child[x][1]) + 1;
}

void solve(int x, int d) {
    if (x == -1) return;
    if (lr[x] == 0) {
        solve(child[x][0], d+1);
        solve(child[x][1], d+1);
        return;
    }
    if (lr[x] == -1) {
        coor[x] = {d, coor[par[x]].second - subt[child[x][1] == -1 ? 0 : child[x][1]] - 1};
    }
    if (lr[x] == 1) {
        coor[x] = {d, coor[par[x]].second + subt[child[x][0] == -1 ? 0 : child[x][0]] + 1};
    }
    solve(child[x][0], d+1);
    solve(child[x][1], d+1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int u, l, r;
        cin >> u >> l >> r;
        child[u][0] = l;
        child[u][1] = r;
        par[l] = u;
        par[r] = u;
        if (l != -1)
            lr[l] = -1;
        if (r != -1)
            lr[r] = 1;
        rst[i][0] = INT_MAX;
        rst[i][1] = 0;
    }
    int root = 1;
    while (par[root] != 0) root = par[root];
    dfs(root);
    coor[root] = {root, subt[child[root][0] == -1 ? 0 : child[root][0]] + 1};
    solve(root, 1);
    for (int i = 1; i <= n; i++) {
        rst[coor[i].first][0] = min(rst[coor[i].first][0], coor[i].second);
        rst[coor[i].first][1] = max(rst[coor[i].first][1], coor[i].second);
    }
    int level, width = -1;
    for (int i = 1; i <= n; i++) {
        if (rst[i][1] - rst[i][0] + 1 > width) {
            level = i;
            width = rst[i][1] - rst[i][0] + 1;
        }
    }
    cout << level << ' ' << width; 
    return 0;
}