#include<bits/stdc++.h>

using namespace std;

typedef long long int lld;

vector<int> A[100005];

int x, y, N;
lld rst;

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d %d", &x, &y);
        A[y].push_back(x);
    }
    for(int i = 1; i <= N; i++) {
        sort(A[i].begin(), A[i].end());
        if(A[i].size() == 1) continue;
        for(int j = 0; j < A[i].size(); j++) {
            int tmp = 2e9;
            if(j != 0) tmp = min(tmp, A[i][j]-A[i][j-1]);
            if(j != A[i].size()-1) tmp = min(tmp, A[i][j+1]-A[i][j]);
            rst += tmp;
        }
    }
    printf("%lld\n", rst);
    return 0;
}
