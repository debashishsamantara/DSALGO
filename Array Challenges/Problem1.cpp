//Given an array a[] of size n. For every i from 0 to n-1 output max(a[0], a[1], a[2],...., a[i])
//Example -> Let elements of array be
// 1   0   5   4   6   8
//(0) (1) (2) (3) (4) (5)
//So max till i is ->
// 1   1   5   5   6   8
//Approach: Keep variable mx which stores the maximum till ith element and iterate over the array and update mx = max(mx, a[i])
//Time Complexity -> O(n)
#include<bits/stdc++.h>
using namespace std;
  
int main(){
    int mx = -19999999;
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        mx = max(mx, arr[i]);
        cout << mx <<" ";
    }
    return 0;
}