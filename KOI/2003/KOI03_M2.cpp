#include<bits/stdc++.h>

using namespace std;

#define INF 2e9

int N, W;
int X[1002], Y[1002], D[1002][1002];
int px[1002][1002], py[1002][1002];

inline int dist(int i, int j) {
    return abs(X[i]-X[j]) + abs(Y[i]-Y[j]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    memset(D, -1, sizeof(D));
    cin >> N >> W;
    X[0] = Y[0] = 1;
    X[1] = Y[1] = N;
    for(int i = 2; i <= W+1; i++) cin >> X[i] >> Y[i];
    for(int i = 0; i <= W+1; i++)
        for(int j = 0; j <= W+1; j++)
            D[i][j] = INF;
    D[0][1] = 0;
    for(int i = 0; i <= W; i++) {
        for(int j = 1; j <= W; j++) {
            int k = max(i, j) + 1;
            if(D[k][j] > D[i][j] + dist(i, k)) {
                D[k][j] = D[i][j] + dist(i, k);
                px[k][j] = i;
                py[k][j] = j;
            }
            if(D[i][k] > D[i][j] + dist(j, k)) {
                D[i][k] = D[i][j] + dist(j, k);
                px[i][k] = i;
                py[i][k] = j;
            }
        }
    }
    int rst = INF, a, b;
    for(int i = 0; i <= W; i++) {
        if(D[W+1][i] < rst) {
            rst = D[W+1][i];
            a = W+1;
            b = i;
        }
        if(D[i][W+1] < rst) {
            rst = D[i][W+1];
            a = i;
            b = W+1;
        }
    }
    cout << rst <<'\n';
    int tmp = W+1;
    vector<int> r;
    while(a != 0 || b != 1) {
        if(a == tmp--) r.push_back(1);
        else r.push_back(2);
        int t1 = px[a][b];
        int t2 = py[a][b];
        a = t1;
        b = t2;
    }
    for(int i = r.size()-1; i >= 0; i--) cout << r[i] << '\n';
    return 0;
}
