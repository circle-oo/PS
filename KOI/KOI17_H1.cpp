#include<bits/stdc++.h>
 
using namespace std;
 
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
 
map<pii, int> m;
int a, b, c, d;
 
ppi p(int i, int j, int k) {
    return ppi(pii(i, j), k);
}
 
void solve() {
    queue<ppi> q;
    q.push(p(0, 0, 0));
    while(q.size() != 0) {
        ppi t = q.front();
        q.pop();
        int i = t.first.first, j = t.first.second, k = t.second;
        m.insert(p(i, j, k));
        if(m.insert(p(0, j, k+1)).second) q.push(p(0, j, k+1));
        if(m.insert(p(i, 0, k+1)).second) q.push(p(i, 0, k+1));
        if(m.insert(p(a, j, k+1)).second) q.push(p(a, j, k+1));
        if(m.insert(p(i, b, k+1)).second) q.push(p(i, b, k+1));
        int u = min(b-j, i);
        if(m.insert(p(i-u, j+u, k+1)).second) q.push(p(i-u, j+u, k+1));
        u = min(a-i, j);
        if(m.insert(p(i+u, j-u, k+1)).second) q.push(p(i+u, j-u, k+1));
    }
}
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> a >> b >> c >> d;
    solve();
    int r = m.find(pii(c, d))->second;
    if(!c && !d) cout << 0;
    else cout << (r > 0 ? r : -1);
    return 0;
}
