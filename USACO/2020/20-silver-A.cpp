#include<bits/stdc++.h>

using namespace std;

int N;
int a[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N-1; i++) {
        int x, y;
        cin >> x >> y;
        a[x]++; a[y]++;
    }
    long long rst = 0;
    a[1]++;
    for (int i = 1; i <= N; i++)
        if (a[i] != 0)
            rst += (int)ceil(log2(a[i]));
    
    cout << rst + N - 1;
    return 0;
}