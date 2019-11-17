#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s;
    cin >> s;
    regex w("(100+1+|01)+");
    if(regex_match(s, w)) cout << "SUBMARINE";
    else cout << "NOISE";
    return 0;
}
