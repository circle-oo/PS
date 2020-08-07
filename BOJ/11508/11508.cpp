#include<bits/stdc++.h>

using namespace std;

using lld = long long int;
using lf = long double;
using uint = unsigned int;
using ulld = unsigned long long int;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N, R, A[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        R += A[i];
    }
    sort(A, A+N);
    for (int i = N-3; i >= 0; i -= 3) R -= A[i];
    for (int i = 0; i < i % 3; i++) R -= A[i];

    cout << R;
    return 0;
}