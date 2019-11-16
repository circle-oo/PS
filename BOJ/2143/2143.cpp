#include<bits/stdc++.h>

using namespace std;

using lld = long long int;
using llf = long double;
using uint = unsigned int;
using ulld = unsigned long long int;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

vector<lld> X, Y;
int N, M;
lld A[1005], B[1005], T;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    cin >> M;
    for (int i = 0; i < M; i++)
        cin >> B[i];
    
    for (int i = 0; i < N; i++) {
        lld k = A[i];
        X.push_back(k);
        for (int j = i+1; j < N; j++) {
            k += A[j];
            X.push_back(k);
        }
    }
    for (int i = 0; i < M; i++) {
        lld k = B[i];
        Y.push_back(k);
        for (int j = i+1; j < M; j++) {
            k += B[j];
            Y.push_back(k);
        }
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    lld rst = 0;
    for (auto &x : X) {
        lld k = T - x;
        lld l = lower_bound(Y.begin(), Y.end(), k) - Y.begin();
        lld r = upper_bound(Y.begin(), Y.end(), k) - Y.begin();
        rst += r - l;
    }
    cout << rst;

    return 0;
}