#include<bits/stdc++.h>

using namespace std;

int n, k, r, cnt;
int arr[105], c[105], shd[105];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        int x;
        cin >> x;
        arr[x]++;
        shd[i] = x;
    }
    
    for (int i = 1; i <= k; i++) {
        if (c[shd[i]]) {
            arr[shd[i]]--;
        } else {
            if (cnt < n) {
                c[shd[i]] = 1;
                arr[shd[i]]--;
                cnt++;
            } else {
                int p = 0, last[105] = {0,}, tmp = 0;
                for (int j = 1; j < i; j++)
                    if (c[shd[j]])
                        if (arr[shd[j]] == 0) p = shd[j];
                
                if (p == 0) {
                    for (int j = i+1; j <= k; j++)
                        if (c[shd[j]] && last[shd[j]] == 0)
                            last[shd[j]] = j;
                    
                    for (int j = 1; j <= k; j++)
                        if (last[shd[j]])
                            tmp = max(tmp, last[shd[j]]);
                    p = shd[tmp];
                }
                c[p] = 0;
                r++;
                c[shd[i]] = 1;
                arr[shd[i]]--;
            }
        }
    }
    
    cout << r;
    return 0;
}