#include<bits/stdc++.h>

using namespace std;

using lld = long long int;
using llf = long double;
using uint = unsigned int;
using ulld = unsigned long long int;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

lld N = 2, M;
int A[1000005];
vector<lld> P;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(true) {
    cin >> N;
    if (N == 0)
        break;
    M = N;
    P.clear();
    for (int i = 2; i <= sqrt(M); i++) {
        while (!(M%i)) {
            P.push_back(i);
            M /= i;
        }
    }
    if (M != 1) P.push_back(M);
    P.erase(unique(P.begin(), P.end()), P.end());
    sort(P.begin(), P.end());
    for (lld& x : P)
        N = N - N / x;
    cout << N << '\n';
    }
    return 0;
}