//Subarray with given sum
//Given an unsorted array A of size N of non-negative integers, find a continous subarray which adds to a given number S.
#include<bits/stdc++.h>
using namespace std;
  
int main(){
    int n, s;
    cin >> n >> s;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int i = 0, j = 0, st = -1, en = -1, sum = 0;
    while (j < n && sum+arr[j] <= s)
    {
        sum += arr[j];
        j++;
    }
    if (sum == s)
    {
        cout << i+1 <<" "<< j << endl;
        return 0;
    }
    while (j < n)
    {
        sum += arr[j];
        while (sum > s)
        {
            sum -= arr[i];
            i++;
        }
        if (sum == s)
        {
            st = i+1;
            en = j+1;
            break;
        }
        j++;
    }
    cout<< st <<" "<< en << endl;
    return 0;
}