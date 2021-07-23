//Find the peak element

//For a given array, find the peak element in the array. Peak element is one which is greater than both, left and right neighbours of itself.

//Corner cases:
//     Ascending array : last element is peak
//     Descending array : first element is the peak
//     For all same elements : each element is peak

//arr[] = {10, 20, 15, 2, 23, 90, 67}
//So, the above array has 2 peak elements i.e., 20 and 90

//Strategy - Use binary search, analyze indices from 0 to n-1. Compute mid and for each mid check if arr[mid] is a peak element, else if arr[mid-1] > arr[mid], check left for peak else if arr[mid] < arr[mid+1], check right is a peak element.

#include<bits/stdc++.h>
using namespace std;

int peakEle(int arr[], int low, int high, int n){
    int mid = low+(high-low)/2;
    if((mid == 0 || arr[mid-1] <= arr[mid]) && (mid == n-1 || arr[mid+1] <= arr[mid]))
        return mid;
    else if(mid > 0 && arr[mid-1] > arr[mid])
        return peakEle(arr, low, mid-1, n);
    else
        return peakEle(arr, mid+1, high, n);
}

int main(){
    int arr[] = {0, 6, 8, 5, 7, 9};
    int n = 6;
    cout << peakEle(arr, 0, n-1, n);
    return 0;
}