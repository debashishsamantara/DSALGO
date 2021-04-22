//Given an array a[] of size n. Output sum of each subarray of the given array.
//Approach -> Iterate over all the subarrays with nested loop. for every i=0 to i=n-1:
//                   for every j=i to j=n-1:
//                      Output sum[i...j]
#include<bits/stdc++.h>
using namespace std;
  
int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int curr = 0;
    for (int i = 0; i < n; i++){
        curr = 0;
        for (int j = 0; j < n; j++){
            curr += arr[j];
            cout << curr <<endl;
        }   
    }
    return 0;
}