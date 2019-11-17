#include<bits/stdc++.h>

using namespace std;

vector<double> A;
int D1, D2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> D1 >> D2;
    for (int i = D1; i <= D2; i++) {
        for (int j = 0; j < i; j++) {
            A.push_back((double)j/i);
        }
    }
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    cout << A.size();
    return 0;
}
