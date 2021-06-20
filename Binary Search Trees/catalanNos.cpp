//Catalan Numbers are a sequence of natural numbers that occur in various counting problems, often involving recursively defined objects.

//Their closed form is in terms of binomial coffecients:
//Cn = (1 / (n+1))(2nCn) = summation(Ci*Cn-i) , i = 0 to n-1

#include<bits/stdc++.h>
using namespace std;

int catalanNos(int n){
    if(n <= 1)
        return 1;
    int res = 0;
    for(int i = 0; i <= n-1; i++){
        res += catalanNos(i) * catalanNos(n-i-1);
    }
    return res;
}

int main(){
    for(int i = 0; i < 10; i++)
        cout << catalanNos(i) << " ";
    cout << endl;
    return 0;
}

//Time Complexity - O(n^2)