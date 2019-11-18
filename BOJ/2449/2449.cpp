#include<bits/stdc++.h>

using namespace std;

using lld = long long int;
using lf = long double;
using uint = unsigned int;
using ulld = unsigned long long int;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N, K;
int A[205];
int D[205][205];

int solve(int l, int r) {
    if (l == r) return 0;
    if (D[l][r] != -1) return D[l][r];
    int ret = INT_MAX;
    for (int i = l; i < r; i++) {
        int t = (A[l] != A[i+1] ? 1 : 0);
        ret = min(ret, solve(l, i) + solve(i+1, r) + t);
    }
    return D[l][r] = ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(D, -1, sizeof(D));
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    int rst = INT_MAX;
    cout << solve(1, N);

    return 0;
}