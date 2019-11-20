#include<bits/stdc++.h>

using namespace std;

using lld = long long int;
using lf = long double;
using uint = unsigned int;
using ulld = unsigned long long int;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

vector<lld> F;
lld N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    F.push_back(0);
    F.push_back(1);
    F.push_back(1);
    while (0 != F[F.size()-2] || 1 != F[F.size()-1]) {
        lld t = (F[F.size()-1] + F[F.size()-2]) % 1000000;
        //cout << t << endl;
        F.push_back(t);
    }
    F.pop_back();
    F.pop_back();
    cout << F[N%(lld)F.size()];
    return 0;
}