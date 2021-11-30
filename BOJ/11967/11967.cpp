#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int N, M;
int R[101][101], C[101][101];
vector<pii> E[101][101];

void bfs() {
    queue<pii> q;
    q.emplace(1, 1);
    C[1][1] = 1;
    R[1][1] = 1;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        //cout << x << ' ' << y << endl;
        for (auto [a, b]: E[x][y]) {
            R[a][b] = 1;
            bool flag = false;
            for (int i = 0; i < 4; i++) {
                int nx = a + dx[i];
                int ny = b + dy[i];
                if (nx <= 0 || N < nx || ny <= 0 || N < ny) continue;
                if (!C[nx][ny]) continue;
                flag = true;
            }
            if (flag && !C[a][b]) {
                C[a][b] = 1;
                q.emplace(a, b);
            }
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx <= 0 || N < nx || ny <= 0 || N < ny) continue;
            if (C[nx][ny] || !R[nx][ny]) continue;
            C[nx][ny] = 1;
            q.emplace(nx, ny);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        E[x][y].emplace_back(a, b);
    }
    bfs();
    int r = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            r += R[i][j];
    cout << r;
    return 0;
}