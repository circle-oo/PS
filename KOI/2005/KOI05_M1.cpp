#include<bits/stdc++.h>

using namespace std;

int N, K;
int D[50], E[50], rst;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> K;
    E[0] = 1;
    E[1] = 1;
    for(int i = 2; i <= 40; i++) E[i] = E[i-1] + E[i-2];
    D[0] = 0;
    D[1] = 1;
    for(int i = 2; i <= 40; i++) D[i] = E[i-1] + D[i-1];
    rst += E[N-K]*E[K-1];
    for(int i = 1; i <= K-1; i++) {
        rst += D[i] * E[K-1-i] * E[N-K];
        rst += E[i-1] * D[K-i] * E[N-K];
        rst -= E[i-1] * E[K-i-1] * E[N-K];
    }
    for(int i = K+1; i <= N; i++) {
        rst += D[i-K] * E[N-i] * E[K-1];
        rst += E[i-K-1] * D[N-i+1] * E[K-1];
        rst -= E[N-i] * E[i-K-1] * E[K-1];
    }
    cout << rst;
    return 0;
}
