#include<bits/stdc++.h>

using namespace std;

int n, p;
int child[10005][2]; // -1 : X
int par[10005];
pair<int, int> coor[10005];
int rst[10005][2];

void dfs(int x, int d) {
    if (x == -1) return;
    dfs(child[x][0], d+1);
    coor[x] = {d, ++p};
    dfs(child[x][1], d+1);
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
        rst[i][0] = INT_MAX;
        rst[i][1] = 0;
    }
    int root = 1;
    while (par[root] != 0) root = par[root];
    dfs(root, 1);
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