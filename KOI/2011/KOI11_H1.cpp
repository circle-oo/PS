#include<bits/stdc++.h>

using namespace std;

int g, l, mul, a, b, p = 1;

int f(int a, int b) {
    if (a == 0) return b;
    return f(b%a, a);
}

int main() {
    cin >> g >> l;
    mul = l/g;
    for (int i = 2; i*i <= mul; i ++) {
        if (mul % i == 0 && f(i, mul/i) == 1) p= i;
    }
    a = g * p;
    b = g * (mul / p);
    cout << a << ' ' << b;
    return 0;
}
