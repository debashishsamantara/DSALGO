//Print all the subarrays of a array.
#include<bits/stdc++.h>
using namespace std;
  
int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int maxSum = INT_MIN;


    //Brute Force Approach (Worst Approach) (O(n^3))
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i; j < n; j++)
    //     {
    //         int sum = 0;
    //         for (int k = i; k <= j; k++)
    //         {
    //             sum += arr[k];
    //             //cout << arr[k] <<" ";
    //         }
    //         maxSum = max(maxSum, sum);
    //         //cout << "\n";
    //     }        
    // }
    // cout << maxSum;


    //Cumulative Sum Approach (Better than Brute Force) (O(n^2))
    // int currSum[n+1];
    // currSum[0] = 0;
    // for (int i = 0; i <= n; i++)
    // {
    //     currSum[i] = currSum[i-1] + arr[i-1];
    // }
    // for (int i = 0; i <= n; i++)
    // {
    //     int sum = 0;
    //     for (int j = 0; j < i; j++)
    //     {
    //         sum = currSum[i] - currSum[j];
    //         maxSum = max(sum, maxSum);
    //     }
    // }
    // cout << maxSum;


    //Kadane's Algorithm (Best Approach) (O(n))
    int currSum = 0;
    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        if (currSum < 0)
        {
            currSum = 0;
        }
        maxSum = max(maxSum, currSum);
    }
    cout << maxSum;
    return 0;
} 