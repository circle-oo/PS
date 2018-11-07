#include<bits/stdc++.h>

using namespace std;

string str;
char S[500], a = 'a', t = 't', g = 'g', c = 'c';
int D[500][500];

int solve(int i, int j) {
    if(i == j) return 0;
    if(D[i][j] != -1) return D[i][j];
    if(j - i == 1) {
        if(((S[i] == a) && (S[j] == t)) || ((S[i] == g) && (S[j] == c)))
            return D[i][j] = 2;
        else return D[i][j] = 0;
    }
    int ret = 0;
    for(int k = i+1; k < j; k++) 
        ret = max(ret, solve(i, k) + solve(k+1, j));
    ret = max(ret, max(solve(i+1, j), solve(i, j-1)));
    if(((S[i] == a) && (S[j] == t)) || ((S[i] == g) && (S[j] == c)))
        ret = max(ret, solve(i+1, j-1) + 2);
    return D[i][j] = ret;
}

int main() {
    cin >> str;
    for(int i = 0; i < str.size(); i++) S[i] = str[i];
    memset(D, -1, sizeof(D));
    cout << solve(0, str.size()-1);
}
