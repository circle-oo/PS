#include<iostream>
#include<algorithm>
#include<math.h>
 
using namespace std;
 
typedef pair<int, int> pii;
 
int m, n, l, x[100001], cnt;
pii ani[100001];
 
int dist(int a, int x) {
    return abs(x - ani[a].first) + ani[a].second;
}
 
int find(int a) {
    int start = 0, end = m-1;
    int mid, rst, ld, hd;
    if(a <= x[0]) return 0;
    if(a >= x[m-1]) return m-1;
    while(start <= end) {
        mid = (start+end)/2;
        if(x[mid] < a) start = mid+1;
        else if(x[mid] > a) end = mid-1;
        else return mid;
    }
    ld = abs(a-x[start]);
    hd = abs(a-x[end]);
    rst = ld <= hd ? start : end;
    return rst;
}
 
int main() {
    cin >> m >> n >> l;
    for(int i = 0; i < m; i++)
        cin >> x[i];
    for(int i = 0, a, b; i < n; i++) {
        cin >> a >> b;
        ani[i] = pii(a, b);
    }
    sort(x, x+m);
    sort(ani, ani+n);
    for(int i = 0; i < n; i++)
        if(dist(i, x[find(ani[i].first)]) <= l) cnt++;
    cout << cnt;
    return 0;
}
