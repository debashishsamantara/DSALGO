//Step1- Map prefix sum to a map
//Step2 - For every key, choose 2 values from all the occurrences of particular prefSum.
//Step3 - Special Case : for prefSum O, we have to also include them.

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
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n)
        cin >> n;
    map<int, int> cnt;
    int prefSum = 0;
    rep(i, 0, n){
        prefSum += a[i];
        cnt[prefSum]++;
    }
    int ans = 0;
    map<int, int> :: iterator it;
    for(it = cnt.begin(); it != cnt.end(); it++){
        int c = it -> ss;
        ans += (c*(c-1))/2;
        if(it -> ff == 0)
            ans += it -> ss;
    }
    cout << ans << endl;
}