#include<bits/stdc++.h>

using namespace std;

using lld = long long int;
using llf = long double;
using uint = unsigned int;
using ulld = unsigned long long int;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

lld a, b, S;

lld gcd(lld x, lld y) {
    if (y == 0)
        return x;
    return gcd(y, x%y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a >> b >> S;
    if (a == 0 && b == 0) {
        cout << (S ? "NO" : "YES");
        return 0;
    } else if (a == 0) {
        cout << (S % b ? "NO" : "YES");
        return 0;
    } else if (b == 0) {
        cout << (S % a ? "NO" : "YES");
        return 0;
    }

    if (a == S || b == S) {
        cout << "YES";
        return 0;
    }

    lld d = gcd(a, b);
    if (S%d)
        cout << "NO";
    else {
        lld x = 1;
        while ((S - a*x) % b) x++;
        lld y = (S - a*x) / b;
        while (y > 0) {
            if (gcd(x, y) == 1) {
                cout << "YES";
                return 0;
            }
            x += b/d;
            y -= a/d;
        }
        cout << "NO";
    }
    return 0;
}