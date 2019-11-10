#include<bits/stdc++.h>

using namespace std;

using lld = long long int;
using llf = long double;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N, T;
lld Mq[55], Pq[55], Rq[55];
tuple<lld, lld, lld> A[55];
lld D[55][100005];

inline lld M(int i) { return get<1>(A[i]); }
inline lld P(int i) { return get<0>(A[i]); }
inline lld R(int i) { return get<2>(A[i]); }

bool f(tuple<lld, lld, lld> a, tuple<lld, lld, lld> b) {
    return get<0>(a) * get<2>(b) > get<0>(b) * get<2>(a);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> T;
    for (int i = 0; i < N; i++)
        cin >> Mq[i]; //M
    for (int i = 0; i < N; i++)
        cin >> Pq[i]; //P
    for (int i = 0; i < N; i++)
        cin >> Rq[i]; //R

    for (int i = 0; i < N; i++)
        A[i] = {Pq[i], Mq[i], Rq[i]};

    sort(A, A + N, f);

    for (int i = 0; i < N; i++) {
        //cout << M(i) << ' ' << P(i) << ' ' << R(i) << endl;
    }

    for (int i = 0; i < N; i++) {
        if (R(i) <= T)
            D[i][R(i)] = max((lld)0, M(i) - R(i) * P(i));
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= T; j++) {
            if (j == 0)
                continue;
            if (j + R(i + 1) <= T)
                D[i + 1][j + R(i + 1)] = max(D[i + 1][j + R(i + 1)], D[i][j] + M(i + 1) - (j + R(i + 1)) * P(i + 1));
            D[i + 1][j] = max(D[i + 1][j], D[i][j]);
        }
    }
    lld ret = 0;
    for (int i = 0; i <= T; i++) {
        ret = max(ret, D[N - 1][i]);
    }
    cout << ret;
    return 0;
}