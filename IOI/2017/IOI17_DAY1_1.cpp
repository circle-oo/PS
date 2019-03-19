#include<bits/stdc++.h>
#include"molecules.h"
 
using namespace std;
 
typedef long long int lld;
typedef pair<int, int> pii;
 
vector<int> find_subset(int l, int u, vector<int> w) {
    vector<pii> p;
    vector<int> rst;
    int a = 0, b = 0;
    lld sum = 0;
    for (int i = 0; i < (int)w.size(); i++)
        p.push_back({w[i], i});
    sort(p.begin(), p.end());
    while (b < w.size() && sum < l) {
        //cout << 'a';
        sum += p[b++].first;
        if (l <= sum && sum <= u) break;
        while (a <= b && sum > u)
            sum -= p[a++].first;
    }
    //cout << sum << endl;
    if (l <= sum && sum <= u)
        for (int i = a; i < b; i++)
            rst.push_back(p[i].second);
    return rst;
}
