#include<bits/stdc++.h>

using namespace std;

using lld = long long int;
using lf = long double;
using uint = unsigned int;
using ulld = unsigned long long int;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N, S, thr, sum;
int A[100005];
lld rst;
map<int, int> cnt;

void f1(int pos) {
    if (pos == thr) {
        auto iter = cnt.find(sum);
        if (iter != cnt.end()) ++iter->second;
        else cnt[sum] = 1;
        return;
    }
    f1(pos+1);
    sum += A[pos];
    f1(pos+1);
    sum -= A[pos];
}

void f2(int pos) {
    if (pos == N) {
        auto iter = cnt.find(S - sum);
        if (iter != cnt.end()) rst += iter->second;
        return;
    }
    f2(pos+1);
    sum += A[pos];
    f2(pos+1);
    sum -= A[pos];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> S;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    thr = N/2;
    f1(0);
    f2(thr);
    if (S == 0) rst--;
    cout << rst;
    return 0;
}