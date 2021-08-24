//We are given 'n' items with {weight, value} of each term and the capacity of knapsack(sack) 'W'. We need to find these items in knapsack such that final value of items in knapsack is maximum.

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define loop(i, a, b) for(int i = a; i < b; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

bool compare(pii p1, pii p2){
    double v1 = (double) p1.ff / p2.ss;
    double v2 = (double) p2.ff / p2.ss;
    return v1 > v2;
}

signed main(){
    int n;
    cin >> n;
    vii a(n);
    loop(i, 0, n)
        cin >> a[i].ff >> a[i].ss;
    int w;
    cin >> w;
    sort(a.begin(), a.end(), compare);
    int ans = 0;
    loop(i, 0, n){
        if(w >= a[i].ss){
            ans += a[i].ff;
            w -= a[i].ss;
            continue;
        }
        double vw = (double) a[i].ff / a[i].ss;
        ans += vw * w;
        w = 0;
        break;
    }
    cout << ans <<endl;
    return 0;
}