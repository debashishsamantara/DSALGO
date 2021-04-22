#include<bits/stdc++.h>
using namespace std;

bool isPowerOf2(int n){
    return (n && !(n & n-1));
}

int main(){
    int n;
    cin >> n;
    cout << isPowerOf2(n);
    return 0;
}