#include<iostream>
#include<utility>
#include<algorithm>
#include<vector>

using namespace std;

#define endl '\n'

typedef long long lld;
typedef pair<lld, lld> pll;

lld n, s, d[300001], m[300001], f[300001], a, b;
vector<pll> art;

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0);
    cin >> n >> s;
    art.resize(n+1);
    art[0] = pll(0, 0);
    for(int i = 1; i <= n; i++) {
        cin >> a >> b;
        art[i] = pll(a, b);
    }
    sort(art.begin(), art.end());
    for(int i = 1; i <= n; i++) {
        for(int j = f[i-1]; j < i; j++)
            if(art[j].first + s <= art[i].first)
                f[i] = j;
            else break;
    }
    for(int i = 1; i <= n; i++) {
        d[i] = art[i].second + m[f[i]];
        m[i] = max(m[i-1], d[i]);
    }
    cout << m[n] << endl;
    return 0;
}
