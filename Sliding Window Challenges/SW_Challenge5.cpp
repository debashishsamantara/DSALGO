//Maximum perfect numbers in subarray of length K

//For a given array and an integer K, find the maximum perfect numbers in a subarrayof size K.

//Perfect Number - Perfect number is a number if it is equal to the sum of its proper divisors (positive divisors) except for the number itself.
//Ex:- 6 (proper divisors = 1, 2, 3 & 1+2+3=6)

//Approach 1 - Generate all subarrays of size K and count number of perfect numbers. Time Complexity - O(n*k)

//Trick - Convert the given array into a binary array with values 0 & 1 only

//Approach 2 - Sliding Window Method
//     - Traverse the array and if the number at index i is a perfect number then replace value at ith index with '1', else with a '0'.
//     - Initialize a variable to store sum of divisors.
//     - Traverse every number less than arr[i] and add it to the sum if it is a divisor of arr[i].
//     - If the sum of all the divisors is equal to arr[i], then the number is a perfect number.
//     - Time Complexity - O(n*sqrt(n))

//Alternate version of this question - Find the maximum sum of a subarray from all possible subarrays of size K.

#include<bits/stdc++.h>
using namespace std;

int maxSum(int arr[], int n, int k){
    if(n < k){
        cout <<"Invalid Values" << endl;
        return -1;
    }
    int res = 0;
    for(int i = 0; i < k; i++)
        res += arr[i];
    int sum = res;
    for(int i = k; i < n; i++){
        sum += arr[i] - arr[i-k];
        res = max(res, sum);
    }
    return res;
}

bool isNumberPerfect(int n){
    int sum = 1;
    for(int i = 2; i < sqrt(n); i++){
        if(n % i == 0){
            if(i == n/i)
                sum += i;
            else    
                sum += i + n/i;
        }
    }
    if(sum == n and n != 1)
        return true;
    return false;
}

int maxNumberOfPerfects(int arr[], int n, int k){
    for(int i = 0; i < n; i++){
        if(isNumberPerfect(arr[i]))
            arr[i] = 1;
        else    
            arr[i] = 0;
    }
    return maxSum(arr, n, k);
}

int main(){
    int arr[] = {28, 2, 3, 6, 496, 99, 8128,24};
    int k = 4, n = 8;
    cout << maxNumberOfPerfects(arr, n, k);
    return 0;
}