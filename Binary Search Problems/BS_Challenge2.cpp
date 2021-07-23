//Allocate Minimum Pages
//n - number of pages in different books (ascending order)
//m - number of students
//All the books have to be divided among m students, consecutively. Allocate the pages in such a way that the maximum pages allocated to student in minimum
#include<bits/stdc++.h>
using namespace std;

bool isPossible(int arr[], int n, int m, int min){
    int studentsReq = 1, sum = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] > min)
           return false; 
        if(sum + arr[i] > min){
            studentsReq++;
            sum = arr[i];
            if(studentsReq > m)
                return false;
        }else
            sum += arr[i];
    }
    return true;
}

int allocateMin(int arr[], int n, int m){
    int sum = 0;
    if(n < m)
        return -1;
    for(int i = 0; i < n; i++)
        sum = sum + arr[i];
    int start = 0, end = sum, ans = INT_MAX;
    while(start <= end){
        int mid = (start + end)/2;
        if(isPossible(arr, n, m, mid)){
            ans = min(ans, mid);
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }
    return ans;
}

int main(){
    int arr[] = {12, 34, 67, 90};
    int n = 4;
    int m = 2;
    cout << allocateMin(arr, n, m);
    return 0;
}