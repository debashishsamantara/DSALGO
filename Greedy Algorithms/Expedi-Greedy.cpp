//A group of cows grabbed a truck and ventured on an expedition deep into the jungle. The truck leak one unit of fuel every unit of distance it travels. To repair the truck, the cows need to drive to the nearest town (no more than 10^6 units distance). On this road, between the town and the current location, there are N(1 < N < 10^5) fuel stops where the cows can stop to  additional fuel (1 - 100 units at each stop).

//The cows want to make the minimum possible number of stops for fuel on the way to town.

//Capacity of the tank is sufficiently large to hold any amount of fuel.

//Initial units of fuel: P(1 <= P <= 10^6), Initial distance from town: L

//Determine minimum number of stops to reach the town

//Methods to solve:
// - Brute Force - 1) Generate all subsequences of stops.
//                 2) Iterate over all subsequence choose the one that is feasible and has minimum no. of stops.
//                 Time Complexity - O(2^n)

// - Greedy Algorithm - 1) Create a maxheap, which stores the fuels available at the stops that we have traversed.
//                      2) Sort the stops on the basis of distance of stops from initial position of truck.
//                      3) Keep iterating on the stops, and whenever fuel in the tank of truck becomes empty, take the fuel from the maxheap and add to it.(Greedy Step)
//                      4) Maintain the count of stops from which we have taken fuel.
//                      Using Greedy Algorithm is the most optimized method.



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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vii a(n);
        loop(i, 0, n)
            cin >> a[i].ff >> a[i].ss;
        int l, p;
        cin >> l >> p;
        loop(i, 0, n)
            a[i].ff = l - a[i].ff;
        sort(a.begin(), a.end());
        int ans = 0, curr = p;
        bool flag = 0;
        priority_queue<int, vi> pq;
        loop(i, 0, n){
            if(curr >= l)
                break;
            while(curr < a[i].ff){
                if(pq.empty()){
                    flag = 1;
                    break;
                }
                ans++;
                curr += pq.top();
                pq.pop();
            }
            if(flag)
                break;
            pq.push(a[i].ss);
        }
        if(flag){
            cout << "-1" << endl;
            continue;
        }
        while(!pq.empty() and curr < l){
            curr += pq.top();
            pq.pop();
            ans++;
        }
        if(curr < l){
            cout << "-1" << endl;
            continue;
        }
        cout << ans << endl;
    }
    return 0;
}