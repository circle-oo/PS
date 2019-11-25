#include<bits/stdc++.h>

using namespace std;

using lld = long long int;
using lf = long double;
using uint = unsigned int;
using ulld = unsigned long long int;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

int G, P;
vector<int> V[100005], W, X, Y;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> G >> P;
    for (int i = 0; i < P; i++) {
        int g;
        cin >> g;
        V[g].push_back(i+1);
    }

    for (int i = 0; i <= G; i++){
        if (!V[i].empty()) {
            //sort(V[i].begin(), V[i].end());
            W.push_back(i);
        }
    }
    Y.push_back(min(W[0], (int)V[W[0]].size()));

    for (int i = 1; i < W.size(); i++) {
        //cout << "k: " << W[i]-W[i-1] << ' ' <<  V[W[i]].size() << endl;1
        Y.push_back(Y[i-1] + min(W[i]-W[i-1], (int)V[W[i]].size()));
    }
    
    //sort(W.begin(), W.end());

    if (W[0] < V[W[0]].size()) X.push_back(V[W[0]][W[0]]);
    for (int i = 1; i < W.size(); i++) {
        if (W[i] - Y[i-1] < V[W[i]].size())
            X.push_back(V[W[i]][W[i]-Y[i-1]]);
    }

    int rst = INT_MAX;
    for (int x: X) {
        rst = min(rst, x);
        //cout << "p: " << x << ' ' << rst << endl;
    }
    
    cout << (rst == INT_MAX ? P : rst-1);
    return 0;
}