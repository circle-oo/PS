#include<bits/stdc++.h>

using namespace std;

using lld = long long int;
using lf = long double;
using uint = unsigned int;
using ulld = unsigned long long int;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N;
lld T[100005];

bool f(lld x) {
    lld t = 0, d = 0;
    queue<lld> A, B;
    for (int i = 0; i < N; i++) {
        if (T[i] <= x)
            A.push(T[i]);
        else
            B.push(T[i]);
    }
    while (!A.empty()) {
        if (!B.empty() && B.front() - (t - d) <= x) {
            d = t;
            t += x;
            B.pop();
        } else {
            t += x;
            A.pop();
        }
    }
    if (B.empty())
        return true;
    while (!B.empty() && B.front() - (t - d) <= x) {
        d = t;
        t += x;
        B.pop();
    }
    if (B.empty())
        return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> T[i];
    
    lld l = 1, r = 1e9;
    while (l <= r) {
        lld mid = (l + r) / 2;
        if (f(mid))
            r = mid-1;
        else
            l = mid+1;
    }
    cout << l;
    return 0;
}