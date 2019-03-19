#include<bits/stdc++.h>

using namespace std;

typedef long long int lld;
typedef pair<int, lld> pil;

int N, M;
lld presum[300005], Xi[300005], X[300005], Yi[300005], Y[300005];
lld rst, a, b;

void input() {
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> Xi[i] >> X[i];
    cin >> M;
    for(int i = 1; i <= M; i++) cin >> Yi[i] >> Y[i];
    cin >> a >> b;
}

void f() {
    for(int i = 1; i <= M; i++) presum[i] = Y[i] + presum[i-1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    input();
    f();
    for(int i = 1; i <= N; i++) {
        int tmp = presum[upper_bound(Yi+1, Yi+M+1, Xi[i] + b) - Yi - 1] - presum[lower_bound(Yi+1, Yi+M+1, Xi[i]+a) - Yi - 1];
        rst += tmp*X[i];
    }
    cout << rst;
    return 0;
}
