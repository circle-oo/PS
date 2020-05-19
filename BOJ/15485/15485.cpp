#include<bits/stdc++.h>

using namespace std;

using lld = long long int;
using lf = long double;
using uint = unsigned int;
using ulld = unsigned long long int;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

const int MOD = 1000000007;

string S;
lld a, b, c;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> S;

    for (int i = 0; i < S.size(); i++) {
        if (S[i] == 'a')
            a = (1 + 2*a) % MOD;
        if (S[i] == 'b')
            b = (a + 2*b) % MOD;
        if (S[i] == 'c')
            c = (b + 2*c) % MOD;
    }
    cout << c;
    return 0;
}