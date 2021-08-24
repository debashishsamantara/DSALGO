//You are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time

//Constraints
// 1 <= n <= 1e5
// 1 <= start, end <= 1e9
// start <= end

//Greedy
//If you are at the ith activity, What should be your next step?
//Take the next activity which ends first.

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define loop(i, a, b) for(int i = a; i < b; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

int main(){
    int n;
    cin >> n;
    vector<vector<int>> v;
    loop(i, 0, n){
        int start, end;
        cin >> start >> end;
        v.push_back({start, end});
    }
    sort(v.begin(), v.end(), [&](vector<int> &a, vector<int> &b){
        return a[1] < b[2];
    });
    int take = 1;
    int end = v[0][1];
    loop(i, 1, n){
        if(v[i][0] >= end){
            take++;
            end = v[i][1];
        }
    }
    cout << take <<"\n";
}