//Painter's Partition Problem

//n = length of n different boards
//m = painters available
//A painter paints 1 unit of board of in 1 unit of time & each painter will paint consecutive boards. Find the minimum time that will be required to paint all the boards.

//Strategy - Apply binary search for minimum and maximum possible values of' 'min' length of boards to be painted.

//Check the feasibility of this chosen value.

//Checking feasibility - Assign boards to each painter in a sequential manner, while the current length of assigned boards dont exceed the value set by binary search. If during allocation the number of painters dont exceed the limit of 'm' then the solution is feasible. Else it isn't. 

#include<bits/stdc++.h>
using namespace std;

int findFeasible(int boards[], int n, int upLim){
    int sum = 0, painters = 1;
    for(int i = 0; i < n; i++){
        sum += boards[i];
        if(sum > upLim){
            sum = boards[i];
            painters++;
        }
    }
    return painters;
}

int paintersPartition(int boards[], int n, int m){
    int totalLen = 0, k = 0;
    for(int i = 0; i < n; i++){
        k = max(k, boards[i]);
        totalLen += boards[i];
    }
    int low = k, high = totalLen;
    while(low < high){
        int mid = (low + high)/2;
        int painters =findFeasible(boards, n, mid);
        if(painters <= m)
            high = mid;
        else    
            low = mid + 1;
    }
    return low;
}

int main(){
    int arr[] = {10, 20, 30, 40};
    int n = 4, m = 2;
    cout << paintersPartition(arr, n, m);
    return 0;
}