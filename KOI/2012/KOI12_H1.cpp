#include<iostream>
#include<algorithm>

using namespace std;

int n, m, s[10000];

int solve() {
    int ret = 0, tot = 0, crr = 0;
    for(int i = 0; i < n; i++) {
        tot = s[i]*(n-i);
        if(tot + crr < m) {
            crr += s[i];
        } else {
            ret = (m-crr)/(n-i);
            break;
        }
    }
    return ret;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> s[i];
    cin >> m;
    sort(s, s+n);
    int tot = 0;
    for(int i = 0; i < n; i++) tot += s[i];
    if(tot <= m) cout << s[n-1];
    else cout << solve();
    return 0;
}
