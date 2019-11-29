#include<bits/stdc++.h>

using namespace std;

using lld = long long int;
using lf = long double;
using uint = unsigned int;
using ulld = unsigned long long int;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

lld K;

lld D[1000], E[64];
const lld MAX = 2000000000000000000ll;

vector<lld> V;

void f(lld s) {
    if (s == 0) return;
    for (lld i = 0; i <= 88; i++) {
        if (!V.size() && i == 0) continue;
        if (D[i] > s) {
            V.push_back(i);
            f(s);
            return;
        }
        s -= D[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> K;
    D[1] = 1;
    D[2] = 1;
    for (lld i = 3; i <= 88; i++) {
        D[i] = 2*D[i-2] + D[i-3];
        //cout << i << ' ' << D[i] << endl;
    } 
    D[0] = 1;
    if (K != 1) {
        f(K-1);
    }
    if (K != 1) {
        for (lld i = V[0], k = 0; i > 0; i--) {
            if (k != V.size() && V[k] == i) {
                cout << 1;
                k++;
            } else cout << 0;
        }
    } else cout << 1;
    return 0;
}