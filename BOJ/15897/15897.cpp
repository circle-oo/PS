#include<bits/stdc++.h>

using namespace std;

using lld = long long int;
using llf = long double;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

lld N, R;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    N--;
    for (int i = N+1; i != 0; i = N / (N/i + 1))
        R += (N/i + 1) * (i - N / (N/i + 1));
    cout << R;
    return 0;
}