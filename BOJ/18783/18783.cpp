#include<bits/stdc++.h>

using namespace std;

using lld = long long int;
using lf = long double;
using uint = unsigned int;
using ulld = unsigned long long int;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N, M, K;
int T;
int A[100005], B[100005], P[100005];

vector<vector<int>> cycle;

void perm() {
    for (vector<int> T : cycle) {
        for (int i = 0; i < T.size(); i++) {
            //cout << T[i+(K%T.size())] << ' ';
            A[T[i]] = T[(i+K)%T.size()];
        }
        //cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) 
        A[i] = B[i] = i;
    
    for (int i = 0; i < M; i++) {
        int l, r;
        cin >> l >> r;
        int C[100005];
        for (int i = l; i <= r; i++)
            C[i] = B[i];
        for (int i = 0; i <= (r-l); i++)
            B[l+i] = C[r-i];
    }

    for(int i = 1; i <= N; i++) {
        vector<int> T;
        if(P[i]) continue;
        P[i] = 1;
        T.push_back(i);
        int x = B[i];
        while(x != i) {
            T.push_back(x);
            P[x] = 1;
            x = B[x];
        }
        cycle.push_back(T);
    }
    
    perm();
    
    for (int i = 1; i <= N; i++)
        cout << A[i] << '\n';

    return 0;
}