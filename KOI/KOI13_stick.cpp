#include<bits/stdc++.h>

using namespace std;

typedef long long int lld;
typedef pair<int, int> pii;

int N, l;
vector<pii> S;
vector<int> U, L;
lld D[100005], E[100005];

inline int getx(int x) {
    return lower_bound(U.begin(), U.end(), x) - U.begin();
}

inline int gety(int y) {
    return lower_bound(L.begin(), L.end(), y) - L.begin();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> l;
    for(int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        S.push_back(pii(x, y));
        U.push_back(x);
        L.push_back(y);
    }
    sort(S.begin(), S.end());
    sort(U.begin(), U.end());
    sort(L.begin(), L.end());
    U.erase(unique(U.begin(), U.end()), U.end());
    L.erase(unique(L.begin(), L.end()), L.end());
    lld rst = 0;
    for(int i = 0; i < N; i++) {
        int a = getx(S[i].first);
        int b = gety(S[i].second);
        lld ta, tb;
        ta = max(D[a], E[b] + abs(S[i].first-S[i].second) + l);
        tb = max(E[b], D[a] + abs(S[i].first-S[i].second) + l);
        D[a] = ta;
        E[b] = tb;
        //cout << a << ' ' << D[a] << ' ';
        //cout << b <<  ' ' << E[b] << endl;
    }
    for(int i = 0; i < N; i++)
        rst = max(rst, max(D[getx(S[i].first)], E[gety(S[i].second)]));
    cout << rst << endl;
    return 0;
}
