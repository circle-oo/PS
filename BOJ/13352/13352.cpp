#include<bits/stdc++.h>

using namespace std;

using lld = long long int;
using lf = long double;
using uint = unsigned int;
using ulld = unsigned long long int;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N;
vector<pii> A;

bool rst = false;

bool inLine(int px, int py, int dx, int dy) {
    if (dx == 0 && px == 0)
        return true;
    else if (dy == 0 && py == 0) 
        return true;
    else {
        int g = gcd(abs(px), abs(py));
        px /= g;
        py /= g;
        if (dx == px && dy == py)
            return true;
    }
    return false;
}

void solve() {
    int a = rand()%N, b = rand()%N;
    while (a == b) b = rand()%N;
    pii L = A[a], K = A[b];
    if (L < K) swap(L, K);
    int dx = L.first - K.first;
    int dy = L.second - K.second;
    if (dx != 0 && dy != 0) {
        int g = gcd(abs(dx), abs(dy));
        if (g != 0) {
            dx /= g;
            dy /= g;
        }
    }
    vector<pii> B, C;
    for (int i = 0; i < N; i++) {
        if (i == a || i == b) continue;
        pii P = A[a], Q = A[i];
        if (P < Q) swap(P, Q);
        int px = P.first - Q.first;
        int py = P.second - Q.second;
        if (!inLine(px, py, dx, dy))
            B.push_back(A[i]);
    }
    if (B.size() <= 2) {
        rst = true;
        return;
    }
    L = B[0], K = B[1];
    if (L < K) swap(L, K);
    int qx = L.first - K.first;
    int qy = L.second - K.second;
    if (qx != 0 && qy != 0) {
        int qg = gcd(abs(qx), abs(qy));
        //cout << qg << endl;
        if (qg != 0) {
            qx /= qg;
            qy /= qg;
        }
    }
    for (int i = 1; i < B.size(); i++) {
        pii P = B[0], Q = B[i];
        if (P < Q) swap(P, Q);
        int wx = P.first - Q.first;
        int wy = P.second - Q.second;
        if (!inLine(wx, wy, qx, qy))
            C.push_back(B[i]);
    }
    //cout << A.size() << ' ' << B.size() << ' ' << C.size() << endl;
    if (C.empty()) rst = true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(123456);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        A.emplace_back(x, y);
    }
    if (N <= 4) {
        cout << "success";
        return 0;
    }
    for (int i = 0; i < 50; i++) 
        solve();
    if (rst)
        cout << "success";
    else
        cout << "failure";
    
    return 0;
}