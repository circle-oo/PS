#include<bits/stdc++.h>

using namespace std;

#define MIN -2E9

int N, a, b, D[403][403][403], tmp, A[403], B[403];

int get(int i, int j, int k) {
    if(i < j || i < k) return MIN;
    if(!j || !k) return 0;
    return D[i][j][k];
}

void solve() {
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= a; j++)
            for(int k = 1; k <= b; k++)
                D[i][j][k] = max(get(i-1, j-1, k-1) + A[j]*B[k], max(get(i-1, j-1, k), get(i-1, j, k-1)));
}

int main() {
    memset(D, -1, sizeof(D));
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &tmp);
        if(tmp) A[++a] = tmp;
    }
    for(int i = 0; i < N; i++) {
        scanf("%d", &tmp);
        if(tmp) B[++b] = tmp;
    }
    N = min(N, a+b);
    solve();
    printf("%d", D[N][a][b]);
    return 0;
}
