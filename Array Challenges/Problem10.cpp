//Pair Sum Problem
#include<bits/stdc++.h>
using namespace std;


//Brute Force (O(n^2))
// bool pairSum(int arr[], int n, int k){
//     for (int i = 0; i < n-1; i++){
//         for (int j = 0; j < n; j++){
//             if (arr[i] + arr[j] == k){
//                 cout << i << " " << j << "\n";
//                 return true;
//             }   
//         } 
//     }
//     return false;
// }


//Best Approach (2 Pointer Approach) (O(n))
bool pairSum(int arr[], int n, int k){
    int low = 0;
    int high = n-1;
    while (low < high){
        if(arr[low] + arr[high] == k){
            cout << low << " " << high << "\n";
            return true;
        }
        else if (arr[low] + arr[high] > k){
            high--;
        }
        else{
            low++;
        }
    }
    return false;
}


int main(){
    int arr[] = {2, 4, 7, 11, 14, 16, 20, 21};
    int k = 31;
    cout << pairSum(arr, 8, k);
    return 0;
}