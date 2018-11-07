#include<bits/stdc++.h>

#define INF 2E9

using namespace std;

int N, M, A[1000][1000];
int D[1000][1000][2]; //0 : left to right 1 : r2l

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> A[i][j];
            D[i][j][0] = D[i][j][1] = -INF;
        }
    }
    D[0][0][0] = A[0][0];
    for(int j = 1; j < M; j++) D[0][j][0] = D[0][j-1][0] + A[0][j];
    for(int i = 1; i < N; i++) {
        for(int j = 0; j < M; j++) {
            D[i][j][0] = max(D[i][j][0], A[i][j]+max(D[i-1][j][0], D[i-1][j][1]));
            if(j > 0) D[i][j][0] = max(D[i][j][0], A[i][j]+D[i][j-1][0]);
        }
        for(int j = M-1; j >= 0; j--) {
            D[i][j][1] = max(D[i][j][1], A[i][j]+max(D[i-1][j][0], D[i-1][j][1]));
            if(j < M-1) D[i][j][1] = max(D[i][j][1], A[i][j] + D[i][j+1][1]);
        }
    }
    cout << max(D[N-1][M-1][0], D[N-1][M-1][1]);
}
