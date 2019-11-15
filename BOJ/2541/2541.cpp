#include<bits/stdc++.h>

using namespace std;

using lld = long long int;
using llf = long double;
using uint = unsigned int;
using ulld = unsigned long long int;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int a, b, x, y;
int p[5], q[5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a >> b;
    for (int i = 0; i < 5; i++)
        cin >> p[i] >> q[i];
    
    lld t = a - b;
    while (t != 0 && (abs(t) % 2 == 0))
        t /= 2;
    for (int i = 0; i < 5; i++) {
        lld k = p[i] - q[i];
        if (t != 0) {
            if ((abs(k) % abs(t)) || k == 0 || (k * t < 0))
                cout << "N\n";
            else
                cout << "Y\n";
        } else {
            if (k != 0)
                cout << "N\n";
            else
                cout << "Y\n";
        }
    }
    return 0;
}