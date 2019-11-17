#include<bits/stdc++.h>

using namespace std;

int N, W, rst;

class Line {
    public:
        int x, i;
        bool r;
        Line(int i, int x, bool r): i(i), x(x), r(r) {}
        bool operator < (const Line &l) const {
            return x < l.x;
        }
};

class Mat {
    public:
        int P, L, R, H, K;
        Mat(int P, int L, int R, int H, int K): P(P), L(L), R(R), H(H), K(K) {}
        bool meet(const Mat &M) const {
            if (R <= M.L || L >= M.R) return false;
            if (P == M.P) return true;
            return H + M.H > W;
        }
        bool operator < (const Mat &M) const {
            return R != M.R ? R < M.R : L < M.L;
        }
};

vector<Mat> A;
vector<Line> B;
int D[3005][6005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> N >> W;
    for (int i = 0; i < N; i++) {
        int P, L, R, H, K;
        cin >> P >> L >> R >> H >> K;
        A.push_back(Mat(P, L, R, H, K));
    }
    sort(A.begin(), A.end());
    for (int i = 0; i < N; i++) {
        B.push_back(Line(i, A[i].L, false));
        B.push_back(Line(i, A[i].R, true));
    }
    sort(B.begin(), B.end());
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2*N; j++) {
            if (B[j].x > A[i].R) break;
            D[i][j] = A[i].K;
            if (j > 0) D[i][j] = max(D[i][j], D[i][j-1]);
            if (B[j].r) {
                int k = B[j].i;
                if (A[k].R <= A[i].L) {
                    D[i][j] = max(D[i][j], D[k][j] + A[i].K);
                } else if (!A[i].meet(A[k])) {
                    if (A[k].L < A[i].L) {
                        int h = upper_bound(B.begin(), B.end(), Line(-1, A[i].L, 0)) - B.begin();
                        D[i][j] = max(D[i][j], D[k][h-1] + A[i].K);
                    } else {
                        int h = upper_bound(B.begin(), B.end(), Line(-1, A[k].L, 0)) - B.begin();
                        D[i][j] = max(D[i][j], D[i][h-1] + A[k].K);
                    }
                }
            }
            rst = max(D[i][j], rst);
        }
    }
    cout << rst;
    return 0;
}

