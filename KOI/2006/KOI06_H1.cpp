#include<iostream>
#include<utility>
#include<algorithm>

using namespace std;

int n, D[10001];
pair<int, int> bui[10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        bui[i] = pair<int, int>(a, b);
    }
    sort(bui+1, bui+n+1);
    D[0] = 0;
    for(int i = 1; i <= n; i++) {
        D[i] = 2000000000;
        int h = 0;
        for(int j = i; j > 0; j--) {
            int w = bui[i].first - bui[j].first;
            if(2*abs(bui[j].second) > h)
                h = 2*abs(bui[j].second);
            D[i] = min(D[i], D[j-1] + max(w, h));
        }
    }
    cout << D[n];
    return 0;
}
