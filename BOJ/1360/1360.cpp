#include<bits/stdc++.h>

using namespace std;

using lld = long long int;
using lf = long double;
using uint = unsigned int;
using ulld = unsigned long long int;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int N;
string R;
lld cmd[100][4]; //0: type, 1: undo / time stamp / value
string ud[100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    int p = 0;
    for (int i = 0; i < N; i++) {
        string s;
        char v; lld t;
        cin >> s;;
        if (s == "type") {
            cin >> v >> t;
            cmd[i][0] = 0;
            cmd[i][1] = t;
            cmd[i][2] = (lld)v;
            cmd[i][3] = 0;
        } else {
            cin >> t;
            cmd[i][0] = 1;
            cmd[i][2] = t;
            cin >> t;
            cmd[i][1] = t;
            cmd[i][3] = p++;
        }
    }
    for (int i = 0; i < N; i++) {
        if (cmd[i][0] == 0)
            R += (char)cmd[i][2];
        if (cmd[i][0] == 1) {
            ud[cmd[i][3]] = R;
            int k = i - 1;
            while (cmd[i][1] - cmd[k][1] <= cmd[i][2]) {
                if (cmd[k][0] == 0)
                    R = R.substr(0, R.size()-1);
                if (cmd[k][0] == 1)
                    R = ud[cmd[k][3]];
                k--;
            }
        }
    }
    cout << R;
    return 0;
}