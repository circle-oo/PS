#include<bits/stdc++.h>

using namespace std;

string str, devil, angel;
int d[2][100][20], n, m;

int solve(int ad, int i, int j) {
    if(i >= n || j >= m) return 0;
    if(j == m-1) return 1;
    if(d[ad][i][j] != -1) return d[ad][i][j];
    int ret = 0;
    if(ad) {
        for(int k = i+1; k < n; k++) {
            if(devil[k] == str[j+1]) ret += solve(0, k, j+1);
        }
    } else {
        for(int k = i+1; k < n; k++) {
            if(angel[k] == str[j+1]) ret += solve(1, k, j+1);
        }
    }
    return d[ad][i][j] = ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(d, -1, sizeof(d));
    cin >> str >> devil >> angel;
    m = str.size();
    n = angel.size();
    int rst = 0;
    for(int i = 0; i < n; i++) {
        if(devil[i] == str[0]) rst += solve(0, i, 0);
        if(angel[i] == str[0]) rst += solve(1, i, 0);
    }
    cout << rst;
    return 0;
}
