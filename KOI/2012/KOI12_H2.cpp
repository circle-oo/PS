#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, rst[500000];

struct player {
    int ab, d;
};

vector<player> ps;

void input() {
    int tmp;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> tmp;
        ps.push_back({tmp, i});
    }
}

void solve(vector<player>& A, int l, int r) {
    if(l == r) return;
    int mid = (l+r)/2;
    solve(A, l, mid);
    solve(A, mid+1, r);
    vector<player> tmp(r-l+1);
    int tmpIndex = 0, lIndex = l, rIndex = mid+1;
    while(lIndex <= mid || rIndex <= r) {
        if((lIndex <= mid) && (rIndex > r || A[lIndex].ab <= A[rIndex].ab)) {
            tmp[tmpIndex++] = A[lIndex++];
        } else {
            rst[A[rIndex].d] += mid-lIndex+1;
            tmp[tmpIndex++] = A[rIndex++];
        }
    }
    for(int i = 0; i < tmp.size(); i++) {
        A[l+i] = tmp[i];
    }
}

void output() {
    for(int i = 0; i < N; i++) cout << rst[i]+1 << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve(ps, 0, N-1);
    output();
    return 0;
}
