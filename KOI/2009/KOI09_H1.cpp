#include<bits/stdc++.h>

using namespace std;

int N, m[20001], c[20001];

vector<int> cycle;

int gcd(int a, int b) {
    int tmp, n;
    while(b != 0) {
        n = a%b;
        a = b;
        b = n;
    }
    return a;
}

int solve(vector<int> num) {
    int s = num.size(), ans = num[0], a = 0, h, l;
    for(int i = 1; i < s; i++) {
        a = num[i];
        h = max(ans, a);
        l = min(a, ans);
        ans = h * (l / gcd(h, l));
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> m[i];
    for(int i = 1; i <= N; i++) {
        if(c[i]) continue;
        c[i] = 1;
        int x = m[i], cnt = 1;
        while(x != i) {
            c[x] = 1;
            x = m[x];
            cnt++;
        }
        if(cnt != 1) cycle.push_back(cnt);
    }
    sort(cycle.begin(), cycle.end());
    cout << solve(cycle);
    return 0;
}
