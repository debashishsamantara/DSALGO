//1- Compute sum of the first k elements (i = 0 to k)
//2- While increasing i, subtract a[i-1] ans add a[i+k+1] in the previous sum, which will became current sum.


#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

signed main(){
    int n, k;
    cin >> n >> k;
    vi a(n);
    rep(i, 0, n)
        cin >> a[i];
    int s = 0, ans = INT_MAX;
    rep(i, 0, k)
        s += a[i];
    ans = min(ans, k);
    //sliding window
    rep(i, 1, n){
        s -= a[i-1];
        s += a[i+k-1];
        ans = min(ans, s);
    }
    cout << ans << endl;
}
