// Max sum subarray of size = K and sum < X

// For a given array and integers K and X, find the maximum sum subarray of size K and having sum less than X.

// Approach 1 - Compute sum of all subarrays of size K
// Time Complexity = O(n*k) (Very bad, will take very long time to calculate ans)

// Approach 2 - Sliding Window with two pointers
// 1. Calculate sum of first K elements
// 2. Intialize ans with this sum
// 3. Iterate over the rest of the arr. Keep adding one element in sum and removing one from start. Compare new sum with ans in each iteration.
// Time Complexity - O(n)

#include<bits/stdc++.h>
using namespace std;

void maxSubarrSum(int arr[], int n, int k, int x){
    int sum = 0, ans = 0;
    for(int i = 0; i < k; i++)
        sum += arr[i];
    if(sum < x)
        ans = sum;
    for(int i = k; i < n; i++){
        sum = sum - arr[i-k];
        sum = sum + arr[i];
        if(sum < x)
            ans = max(ans, sum);
    }
    cout << ans <<" is the max subarray sum (<x)";
}

int main(){
    int arr[] = {7, 5, 4, 6, 8, 9};
    int k = 3;
    int x = 20;
    int n = 6;
    maxSubarrSum(arr, n, k, x);
    return 0;
}