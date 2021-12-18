//Minimum number of squares whose sum equals to given number 'n'
//Example - X = 26 = 4² + 3² + 1² {3 numbers}
//                 = 5² + 1² {numbers}
//So, minimum number of squares required = 2

//Recurrence Relation
//Base Case: f(0) = 0
//           f(1) = 1 {1²}
//           f(2) = 2 {1² + 1²}
//           f(3) = 3 {1² + 1² + 1²}
//           f(x) = min(f(x-i*i)+1) {i varies from 1 to √x}

//This ques has overlapping subproblem property

//Algorithm:
//1) Write the recursion table.
//2) Memoize it in dp table.

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define gi greater<int>
#define pii pair<int, int>
#define vii vector<pii>
#define loop(i, a, b) for(int i = a; i < b; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

const int N = 1e3+2, MOD = 1e9+7;
int dp[N];

// int minSquare(int n){
//     if(n == 1 || n == 2 || n == 3 || n == 0)
//         return n;
//     if(dp[n] != MOD)
//         return dp[n];
//       //int ans = MOD;
//     for(int i = 1; i*i <= n; i++)
//         dp[n] = min(dp[n], 1 + minSquare(n - i*i));
//     return dp[n];
// }

int main(){
    //Memoization
    // loop(i, 0, N)
    //     dp[i] = MOD;
    // int n;
    // cin >> n;
    // cout << minSquare(n) << endl;

    int n;
    cin >> n;
    vi dp(n+1, MOD);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for(int i = 1; i <= sqrt(n); i++){
        for(int j = 0; i+j <= sqrt(n); j++){
            dp[i*i + j] = min(dp[i*i + j], 1 + dp[j]);
        } 
    }
    cout << dp[n] << endl;
    return 0;
}