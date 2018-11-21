#include<iostream>
#include<utility>
#include<algorithm>

using namespace std;

int n, p[201], d[201], r;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    d[1] = 1;
    r = d[1];
    for(int i = 2; i <= n; i++) {
        d[i] = 1;
        for(int j = 1; j < i; j++) {
            if(p[i] > p[j] && d[j]+1 > d[i])
                d[i] = d[j]+1;
        }
        r = max(r, d[i]);
    }
    cout << n-r;
    return 0;
}
