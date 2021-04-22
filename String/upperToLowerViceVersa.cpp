#include<bits/stdc++.h>
using namespace std;
  
int main(){
    string str = "lkdfjvndk";
    int n = str.length;
    //convert lowercase
    for (int i = 0; i < n ; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')     
        {
            str[i] -= 32;
        }
    }
    cout << str;
    return 0;
}