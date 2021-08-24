//Problem - You are given n files with their computation times in an array.

//Operation - Choose/take any files, add their computation times and append it to the list of computation times. {Cost = Sum of computation time}
//      Do this until we are left with only one file in the array. We have to do this operation such that we get minimum cost finally.

//Approach -
//  1. Push all elements to a minheap.
//  2. Take top 2 elements one by one and add the cost to the answer. Push the merged file to the minheap.
//  3. When single element remains, output the cost.

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define gi greater<int>
#define pii pair<int, int>
#define vii vector<pii>
#define loop(i, a, b) for(int i = a; i < b; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)


signed main(){
    int n;
    cin >> n;
    vi a(n);
    loop(i, 0, n)
        cin >> a[i];
    priority_queue<int, vi, gi> minheap;
    loop(i, 0, n)
        minheap.push(a[i]);
    int ans = 0;
    while(minheap.size() > 1){
        int e1 = minheap.top();
        minheap.pop();
        int e2 = minheap.top();
        minheap.pop();
        ans += e1 + e2;
        minheap.push(e1 + e2);
    }
    cout << ans << endl;
    return 0;
}