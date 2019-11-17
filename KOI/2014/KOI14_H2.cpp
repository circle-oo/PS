#include<bits/stdc++.h>

using namespace std;

class Line {
    public:
        int s, e, i;
        Line(int s, int e, int i) : s(s), e(e), i(i) {}
        bool operator < (Line l) const {
            return (s != l.s) ? (s < l.s) : (e > l.e);
        }
};

vector<Line> L;
bool c[500005];
int N, M, B;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) {
            B = max(b, B);
            b += N;
        }
        L.push_back(Line(a, b, i+1));
    }
    sort(L.begin(), L.end());
    for (int i = 0; i < M; i++) {
        if(L[i].e <= B)
            c[L[i].i] = true;
        else
            B = L[i].e;
    }
    for (int i = 1; i <= M; i++)
        if(!c[i])
            cout << i << ' ';
    return 0;
}
