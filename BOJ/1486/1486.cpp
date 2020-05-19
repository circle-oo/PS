#include<bits/stdc++.h>

using namespace std;

using lld = long long int;
using lf = long double;
using uint = unsigned int;
using ulld = unsigned long long int;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

inline int p(int x) {return x*x;}

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int N, M, D, T;

char mp[25][25];
int imp[25][25];

int d[700], rd[700];

vector<pii> adj[626], radj[626];

void solve(vector<pii> V[626], int dist[626]) {
    priority_queue<pii> pq;
    pq.push({0, 0});
    dist[0] = 0;
    while (!pq.empty()) {
        int h = pq.top().second;
        int t = -pq.top().first;
        pq.pop();
        if (dist[h] < t) continue;
        for (auto x : V[h]) {
            int nx = x.second;
            if (dist[nx] > t + x.first) {
                dist[nx] = t + x.first;
                pq.push({-dist[nx], nx});
            }
        }
    }
}

int main() {
    memset(d, 0x3f, sizeof d);
    memset(rd, 0x3f, sizeof rd);
    scanf("%d %d %d %d", &N, &M, &T, &D);
    for (int i = 0; i < N; i++) scanf("%s", &mp[i]);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if ('A' <= mp[i][j] && mp[i][j] <= 'Z')
                imp[i][j] = mp[i][j] - 'A';
            else
                imp[i][j] = mp[i][j] - 'a' + 26;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < 4; k++) {
                int y = i + dy[k], x = j + dx[k];
                if (y < 0 || y >= N || x < 0 || x >= M) continue;
                int s = imp[i][j], e = imp[y][x];

                if (abs(s - e) > T) continue;
                if (s >= e)
                    adj[i*M + j].emplace_back(1, y*M + x);
                else
                    adj[i*M + j].emplace_back(p(s-e), y*M + x);
                if (s > e)
                    radj[i*M + j].emplace_back(p(s-e), y*M + x);
                else 
                    radj[i*M + j].emplace_back(1, y*M + x);
            }
        }
    }

    solve(adj, d);
    solve(radj, rd);

    int rst = imp[0][0];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (d[i*M + j] + rd[i*M + j] <= D)
                rst = max(rst, imp[i][j]);
        }
    }

    printf("%d\n", rst);

    return 0;
}