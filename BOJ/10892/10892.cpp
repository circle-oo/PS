#include<bits/stdc++.h>

using namespace std;

using lld = long long int;
using lf = long double;
using uint = unsigned int;
using ulld = unsigned long long int;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

using ppi = pair<pii, int>;

int N;
vector<ppi> V;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= 3*N; i++) {
        int x, y;
        cin >> x >> y;
        V.push_back({{x, y}, i});
    }
    sort(V.begin(), V.end());

    for (int i = 0; i < 3*N; i += 3) {
        cout << V[i].second << ' ' << V[i+1].second << ' ' << V[i+2].second << '\n';
    }
    return 0;
}