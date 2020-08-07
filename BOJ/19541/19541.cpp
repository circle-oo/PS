#include<bits/stdc++.h>

using namespace std;

using lld = long long int;
using lf = long double;
using uint = unsigned int;
using ulld = unsigned long long int;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N, M;
vector<int> Meet[100005];
bool S[100005] = {true, }, P[100005] = {false,}, E[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            Meet[i].push_back(x);
        }
    }
    for (int i = 1; i <= N; i++) {
        cin >> E[i];
        S[i] = E[i];
    }
    for (int i = M-1; i >= 0; i--) {
        bool r = false;
        for (int x: Meet[i])
            if (!S[x]) r = true;
        if (r) {
            for (int x: Meet[i]) S[x] = false;
        } 
    }
    for (int i = 1; i <= N; i++) P[i] = S[i];
    for (int i = 0; i < M; i++) {
        bool r = false;
        for (int x: Meet[i])
            if (P[x]) r = true;
        if (r) {
            for (int x: Meet[i]) P[x] = true;
        }
    }
    bool rst = true;
    for (int i = 1; i <= N; i++) 
        if (E[i] != P[i])
            rst = false;
    if (rst) {
        cout << "YES" << endl;
        for (int i = 1; i <= N; i++) cout << S[i] << ' ';
    } else cout << "NO";
    return 0;
}