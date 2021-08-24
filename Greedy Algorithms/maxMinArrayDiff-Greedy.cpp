//You are given an array A of n elements. You have to remove exactly n\2 elements from array A and add it to another array B(initially empty).
//Find the maximum and minimum values of differences between these two arrays.
//We define the difference between these two arrays as: Σ abs(A[i] - B[i])

//Idea

//To maximize abs(A[i]-A[j])
//1. A[i] should be as large as possible
//2. A[j] should be as small as possible
//For a sorted array,
//Maximum diff = (A[n-1]-A[0])+(A[n-2]-A[1]).....A[n/2-1] = (A[n-1]+A[n-2]....A[n/2]) - A[0]+A[1]...A[n/2-1])

//To minimize abs(A[i]-A[j])
//1. The differences should between A[i] and A[j] should be similar.
//For a sorted array,
//Minimum diff = A[1]-A[0]+A[3]-A[2]........=(sum of odd elements) - (sum of even elements)

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define gi greater<int>
#define pii pair<int, int>
#define vii vector<pii>
#define loop(i, a, b) for(int i = a; i < b; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

int main(){
    int n;
    cin >> n;
    vi a(n);
    for(auto &i : a)
        cin >> i;
    sort(a.begin(), a.end());
    long long mn = 0, mx = 0;
    loop(i, 0, n/2){
        mx += (a[i+n/2] - a[i]);
        mn += (a[2*i+1] - a[2*i]);
    }
    cout << mn << " " << mx << endl;
    return 0;
}