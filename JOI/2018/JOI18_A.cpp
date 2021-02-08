#include<bits/stdc++.h>

using namespace std;

using ll = long long;

int N, K;
int T[100005];
priority_queue<int> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> T[i];
    
    for (int i = 1; i < N; i++)
        pq.push(T[i] - T[i-1] - 1);
    
    ll ans = T[N-1] - T[0] + 1;
    K--;
    while (K--) {
        ans -= pq.top();
        pq.pop();
    }
    cout << ans;
    return 0;
}