//Given an array A of 0s and 1s we may change up to k values from 0 to 1. Return the length of the longest(contiguous) subarray that contains only 1s.
#include<bits/stdc++.h>
using namespace std;
  
int main(){
    int n; cin >> n;
    int k; cin >> k;
    vector<int> a(n);
    for(auto &i : a)
        cin >> i;
    int zeroCnt = 0, i = 0, ans = 0;
    for(int j = 0; j < n; j++){
        if(a[j] == 0)
            zeroCnt++;
        while(zeroCnt > k){
            if(a[i] == 0)
                zeroCnt--;
            i++;
        }
        ans = max(ans, j - i + 1);
    }
    cout << ans;
    return 0;
}