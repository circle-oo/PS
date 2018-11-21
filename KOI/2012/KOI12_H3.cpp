#include<bits/stdc++.h>

using namespace std;

typedef long long int lld;

int N, M, p1, p2, p3, A[101], B[101], C[101];
int D[101][101][101][3];

inline int dist(int a, int b) {
    return min(abs(a-b), N - abs(a-b));
}

void solve() {
    for(int i = 0; i <= p1; i++) {
        for(int j = 0; j <= p2; j++) {
            for(int k = 0; k <= p3; k++) {
                D[i+1][j][k][0] = min(D[i+1][j][k][0],
                                    min(D[i][j][k][0] + dist(A[i+1], A[i]),
                                    min(D[i][j][k][1] + dist(A[i+1], (B[j] + 2*M) % N),
                                    D[i][j][k][2] + dist(A[i+1], (C[k] + M) % N))));
                D[i][j+1][k][1] = min(D[i][j+1][k][1],
                                    min(D[i][j][k][0] + dist(B[j+1], (A[i] + M) % N),
                                    min(D[i][j][k][1] + dist(B[j+1], B[j]),
                                    D[i][j][k][2] + dist(B[j+1], (C[k] + 2*M) % N))));
                D[i][j][k+1][2] = min(D[i][j][k+1][2],
                                    min(D[i][j][k][0] + dist(C[k+1], (A[i] + 2*M) % N),
                                    min(D[i][j][k][1] + dist(C[k+1], (B[j] + M) % N),
                                    D[i][j][k][2] + dist(C[k+1], C[k]))));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(D, 0, sizeof(D));
    cin >> N;
    M = N/3;
    cin >> p1;
    for(int i = 1; i <= p1; i++) cin >> A[i];
    cin >> p2;
    for(int i = 1; i <= p2; i++) cin >> B[i];
    cin >> p3;
    for(int i = 1; i <= p3; i++) cin >> C[i];
    for(int i = 0; i <= p1; i++)
        for(int j = 0; j <= p2; j++)
            for(int k = 0; k <= p3; k++)
                for(int p = 0; p < 3; p++)
                    D[i][j][k][p] = 2E9;
    A[0] = 1;
    B[0] = 1 + M;
    C[0] = 1 + 2*M;
    D[0][0][0][0] = D[0][0][0][1] = D[0][0][0][2] = 0;
    solve();
    cout << min(D[p1][p2][p3][0], min(D[p1][p2][p3][1], D[p1][p2][p3][2]));
    return 0;
}
