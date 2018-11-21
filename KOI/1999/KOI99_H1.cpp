#include<bits/stdc++.h>

using namespace std;

#define INF 2E9

typedef pair<int, int> pii;

int N, A[101], B[101], W[101];
int D[105][105], E[105][105];

vector<pii> rec[105][105];

int solve(int i, int j) {
    if(j-i == 1) {
        rec[i][j].push_back(pii(i, j));
        E[i][j] = 1;
        return 3;
    }
    if(D[i][j] != -1) return D[i][j];
    int ret = INF, q, h;
    for(int k = i+2; k <= j-2; k++) {
        if(B[k-1]-B[i] == W[k-1]-W[i] && A[i]+A[k] == 1) {
            int tmp = solve(i+1, k-1) + solve(k+1, j) + k-i;
            tmp += 2*(E[i+1][k-1]+1);
            if(tmp < ret) {
                q = k;
                ret = tmp;
                h = E[i+1][k-1]+1;
            }
        }
    }
    if(A[i] + A[i+1] == 1) {
        int tmp = solve(i+2, j) + 3;
        if(tmp < ret) {
            q = i+1;
            ret = tmp;
            h = 1;
        }
    }
    if(A[i] + A[j] == 1) {
        int tmp = solve(i+1, j-1) + j - i;
        tmp += 2*(E[i+1][j-1]+1);
        if(tmp < ret) {
            q = j;
            ret = tmp;
            h = E[i+1][j-1]+1;
        }
    }
    E[i][j] = max(h, E[q+1][j]);
    for(int k = 0; k < rec[i+1][q-1].size(); k++) rec[i][j].push_back(rec[i+1][q-1][k]);
    for(int k = 0; k < rec[q+1][j].size(); k++) rec[i][j].push_back(rec[q+1][j][k]);
    rec[i][j].push_back(pii(i, q));
    return D[i][j] = ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    memset(D, -1, sizeof(D));
    cin >> N;
    char tmp;
    for(int i = 1; i <= N; i++) {
        cin >> tmp;
        if(tmp == '1') A[i] = 1;
    }
    for(int i = 1; i <= N; i++) {
        if(A[i]) {
            B[i] = B[i-1] + 1;
            W[i] = W[i-1];
        } else {
            B[i] = B[i-1];
            W[i] = W[i-1] + 1;
        }
    }
    cout << solve(1, N) << endl;
    sort(rec[1][N].begin(), rec[1][N].end());
    rec[1][N].erase(unique(rec[1][N].begin(), rec[1][N].end()), rec[1][N].end());
    for(int i = 0; i < rec[1][N].size(); i++) cout << rec[1][N][i].first << ' ' << rec[1][N][i].second << endl;
    return 0;
}
