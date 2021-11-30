#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

int N, M;
int C[55], B[10005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> C[i];
    cin >> M;
    for (int i = 0; i < M; i++)
        cin >> B[i];
    sort(C, C+N);
    sort(B, B+M);
    if (C[N-1] < B[M-1]) {
        cout << -1;
        return 0;
    }
    vector<int> V;
    for (int i = 0; i < M; i++)
        V.push_back(B[i]);
    
    int t = 0;

    while(!V.empty()) {
        t++;
        for (int i = 0; i < N; i++) {
            if (V.empty()) break;
            if (C[i] < V[0]) continue;
            auto it = upper_bound(V.begin(), V.end(), C[i]);
            it--;
            V.erase(it);
        }
    }
    cout << t;


    return 0;
}