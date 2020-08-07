#include<bits/stdc++.h>

using namespace std;

using lld = long long int;
using lf = long double;
using uint = unsigned int;
using ulld = unsigned long long int;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N, M;
vector<int> V[200005], S;
int C[200005], visit[200005], found[200005];

void bfs() {
    queue<pii> q;
    for (int x: S) {
        q.emplace(x, 0);
        visit[x] = 0;
    }
    
    while (!q.empty()) {
        int cur = q.front().first, t = q.front().second; q.pop();
        for (int next: V[cur]) {
            found[next]++;
            if (found[next] >= C[next] && visit[next] == -1) {
                q.emplace(next, t+1);
                visit[next] = t+1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; i++) visit[i] = -1;
    for (int i = 1; i <= N; i++) {
        int t;
        while (cin >> t && t != 0) {
            V[i].push_back(t);
        }
        C[i] = ceil((float)V[i].size()/2);
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        int t;
        cin >> t;
        S.push_back(t);
    }
    bfs();
    for (int i = 1; i <= N; i++)
        cout << visit[i] << ' ';
    return 0;
}