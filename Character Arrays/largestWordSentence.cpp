#include<bits/stdc++.h>
using namespace std;
  
int main(){
    int n;
    cin >> n;
    char arr[n+1];
    cin.getline(arr, n);
    cin.ignore();
    int i = 0;
    int currLen = 0, maxLen = 0, st = 0, maxst = 0;
    while (arr[i] != '\0')
    {
        if (arr[i] == ' ' || arr[i] == '\0')
        {
            if (currLen > maxLen)
            {
                maxLen = currLen;
                maxst = st;
            }
            currLen = 0;
            st = i+1;
        }
        else
        {
            currLen++;
        }
        i++;
    }
    cout << maxLen <<" ";
    for (int i = 0; i < maxLen; i++)
    {
        cout << arr[i+maxst];
    }
    return 0;
}