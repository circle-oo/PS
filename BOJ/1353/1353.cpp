#include<bits/stdc++.h>

using namespace std;

using lld = long long int;
using lf = long double;
using uint = unsigned int;
using ulld = unsigned long long int;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

lld S, P;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> S >> P;
    if (S == P) {
        cout << 1;
        return 0;
    }
    lf a = -1.0;
    for (int r = 2; ; r++) {
        lf b = pow((lf)S/r, r);
        if (a > b) {
            cout << -1;
            return 0;
        } else if (P <= b) {
            cout << r;
            return 0;
        }
        a = b;
    }
    return 0;
}