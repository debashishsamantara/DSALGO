//Minimum Subarray Size (Smallest Subarray with sum > X)

//For a given array and an integer X, find the minimum subarray size which sum > X

//Approach 1- Compute sum of all subarrays and check the condition. Time Complexity = O(n^2)

//Approach 2- Using sliding window method
//    -Use variables ans, sum, and start
//    -Iterate over array and start adding elements to sum
//    -If sum > X, remove elements from the start
//Time Complexity - O(n)

#include<bits/stdc++.h>
using namespace std;

int smallestSubarrSum(int arr[], int n, int x){
    int sum = 0, minLen = n+1, start = 0, end = 0;
    while (end < n){
        while(sum <= x && end < n){
            sum += arr[end++];
        }
        while(sum > x && start < n){
            if(end - start < minLen)
                minLen = end - start;
            sum -= arr[start++];
        }
    }
    return minLen;
}

int main(){
    int arr[] = {1, 4, 45, 6, 10, 19};
    int x = 51, n = 6;
    int minLen = smallestSubarrSum(arr, n, x);
    if(minLen == n+1)
        cout << "No subarray exists";
    else    
        cout << "Smallest length subarray is " << minLen;
    return 0;
}