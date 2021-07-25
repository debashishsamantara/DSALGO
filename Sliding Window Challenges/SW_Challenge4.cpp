//Subarray of size K with palindromic concatenation

//Palindrome - Words/Numbers that when read are same from forward as well as backward
//   Ex:- NITIN, 223343322, RACECAR, etc.......

//For a given array and an integer K, check if any subarray of size K exists in the array such that concatenation of elements form a palindrome.

//Approach 1 - Generate all subarrays of size K. Time Complexity - O(n^2)
//   Check if their concatenation forms a palindrome. Time Complexity - O(n)
//   Final Time Complexity - O(n^3)

//Approach 2 - Sliding Window Method
//     - Store concatenation of initial K elements
//     - Iterate over the array and start deleting elements from the start and adding elements from the end.
//     - At each step, check if concatenation is palindrome or not.
//     - Time complexity - O(n^2)

#include<bits/stdc++.h>//iostream, vector & cmath libraries used
using namespace std;

bool isPalindrome(int n){
    int temp = n, number = 0;
    while(temp > 0){
        number = number*10 + temp%10;
        temp = temp/10;
    }
    if(number == n)
        return true;
    return false;
}

int findPalindromicSubarr(vector<int> arr, int k){
    int num = 0;
    for(int i = 0; i < k; i++)
        num = num*10 + arr[i];
    if(isPalindrome(num))
        return 0;
    for(int j = k; j < arr.size(); j++){
        num = (num % (int)pow(10, k-1))*10 + arr[j];
        if(isPalindrome(num))
            return j-k+1;
    }
    return -1;
}

int main(){
    vector<int> arr = {2, 3, 5, 1, 1, 5};
    int k = 4;
    int ans = findPalindromicSubarr(arr, k);
    if(ans == -1)
        cout << "Palindromic subarray doesnt exist" <<endl;
    else{
        for(int i =ans; i < ans+k; i++)
            cout <<arr[i] <<" ";
        cout << endl;
    }
    return 0;
}