#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define INF 2E18

using namespace std;

typedef long long int lld;
typedef pair<lld, int> pli;
typedef pair<int, lld> pil;

priority_queue<pli> pq;
vector<pil> adj[2501], cst[2501];
vector<lld> dist(2501, INF);
int n, m, l[2501];
int x, y, d;

void f(int start) {
    dist[start] = 0;
    pq.push(pli(0, start));
    while(!pq.empty()) {
        int now = pq.top().second;
        lld cost = -pq.top().first;
        pq.pop();
        if(dist[now] < cost) continue;
        for(auto& e : adj[now]) {
            int nv = e.first;
            lld nw = e.second;
            if(dist[nv] > nw + cost) {
                dist[nv] = nw + cost;
                pq.push(pli(-(cost+nw), nv));
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        if(i == start) continue;
        cst[start].push_back(pil(i, l[start]*dist[i]));
    }
    for(int i = 1; i <= n; i++) dist[i] = INF;
}

void solve(int start) {
    dist[start] = 0;
    pq.push(pli(0, start));
    while(!pq.empty()) {
        int now = pq.top().second;
        lld cost = -pq.top().first;
        pq.pop();
        if(dist[now] < cost) continue;
        for(auto& e : cst[now]) {
            int nv = e.first;
            lld nw = e.second;
            if(dist[nv] > nw + cost) {
                dist[nv] = nw + cost;
                pq.push(pli(-(cost+nw), nv));
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> l[i];
    for(int i = 0; i < m; i++) {
        cin >> x >> y >> d;
        adj[x].push_back(pil(y, d));
        adj[y].push_back(pil(x, d));
    }
    for(int i = 1; i <= n; i++) f(i);
    solve(1);
    cout << dist[n];
    return 0;
}
