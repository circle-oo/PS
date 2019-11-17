#include<bits/stdc++.h>

using namespace std;

typedef long long int lld;

int K, C, M, N;

int solve(int a, int b) {
    int t = abs(a - b), r = K - max(a, b);
    return (a < b) ? (t - r <= 1) : (t - r <= 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> K >> C;
    while(C--) {
        cin >> M >> N;
        cout << solve(M, N) << '\n';
    }
    return 0;
}
