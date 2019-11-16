#include<bits/stdc++.h>

using namespace std;

using lld = long long int;
using llf = long double;
using uint = unsigned int;
using ulld = unsigned long long int;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N, L;
int x;
deque<pii> B;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        while (B.size() && B.front().second <= i - L)
            B.pop_front();
        cin >> x;
        while (B.size() && B.back().first >= x)
            B.pop_back();
        B.emplace_back(x, i);
        cout << B.front().first << ' ';
    }
    
    return 0;
}