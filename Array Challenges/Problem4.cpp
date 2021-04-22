//Record Breakers
/*//Brute Force Approach -> Iterate over all elements and check if it is record breaking day or not.
//Note:- To check if arr[i] is a record breaking day, we have to iterate over arr[0], arr[1],....., arr[i-1].
//Time complexity -> O(n) and overall time complexity -> O(n^2)
This is not a optimised approach coz we cant afford time*/
/*Optimised Approach -> If we can optimise step 1, then we can optimise our overall solution.
For step 1:- We need to check if arr[i] > {arr[i-1], arr[i-2],......, arr[0]}, which is same as a[i] > max(arr[i-1], arr[i-2],......, arr[0]
For this we will keep a variable mx, which will store the maximum value till arr[i]. Then we just need to check, arr[i] > mx
arr[i] > arr[i+1], {if i+1 < n}
and now update mx = max(mx, arr[i])
So, step 1 time complexity reduces to O(1).
Overall time complexity -> O(n).*/
#include<bits/stdc++.h>
using namespace std;
  
int main(){
    int n;
    cin >> n;
    int arr[n+1];
    arr[n] = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (n == 1)
    {
        cout <<"1"<<endl;
        return 0;
    }
    int ans = 0;
    int mx = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mx && arr[i] > arr[i+1])
        {
            ans++;
        }
        mx = max(mx, arr[i]);
    }
    cout << ans <<endl;
    return 0;
}