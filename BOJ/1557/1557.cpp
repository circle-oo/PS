#include<bits/stdc++.h>

using namespace std;

using lld = long long int;
using llf = long double;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

lld K, R;
lld M[100002];

lld f(lld x) {
    lld ret = 0;
    for (int i = 1; i*i <= x; i++) ret += M[i] * (x / (i*i));
    return x - ret;
}

int main() {
    //AC by Mobius Function
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> K; //sum_{i = 1 to sqrt(K)} {M(i) * (N / (i*i)} : number of square free number
    for (int i = 1; i <= 100000; i++)
        M[i] = 1;
    for (int i = 2; i*i <= 100000; i++) {
        if (M[i] == 1) {
            for(int j = i; j <= 100000; j+=i) M[j] *= -i;
            for(int j = i*i; j <= 100000; j+=i*i) M[j] = 0;
        }
    }
    for (int i = 2; i <= 100000; i++) {
        if (M[i] == i) M[i] = 1;
        else if (M[i] == -i) M[i] = -1;
        else if (M[i] < 0) M[i] = 1;
        else if (M[i] > 0) M[i] = -1;
    }
    R = K + f(K);
    while (R != K) {
        lld t = R + f(R) - f(K);
        K = R;
        R = t;
    }
    cout << R;
    return 0;
}