//0-1 Knapsack Problem
#include<bits/stdc++.h>
using namespace std;

int knapSack(int value[], int wt[], int n, int W){
    if(n == 0 || W == 0){
        return 0;
    }
    if(wt[n-1] > W){
        return knapSack(value, wt, n-1, W);
    }
    return max(knapSack(value, wt, n-1, W-wt[n-1])+value[n-1],
    knapSack(value, wt, n-1, W));
}

int main(){
    int wt[] = {10, 20, 30};
    int value[] = {100, 50, 150};
    int W = 50;
    cout << knapSack(value, wt, 3, W);
    return 0;
}