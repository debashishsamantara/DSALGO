#include<bits/stdc++.h>
using namespace std;
  
int main(){
    int n = 0, m = 0;
    cin >> n >> m;
    int a[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    //Spiral Order Print
    int rowStart = 0, rowEnd = n-1, colStart = 0, colEnd = m-1;
    while (rowStart <= rowEnd && colStart <= colEnd)
    {
        //for rowStart
        for (int col = colStart; col <= colEnd; col++)
        {
            cout << a[rowStart][col] <<" ";
        }
        rowStart++;

        //for colEnd
        for (int row = rowStart; row <= rowEnd; row++)
        {
            cout << a[row][colEnd] <<" ";
        }
        colEnd--;

        //for rowEnd
        for (int col = colEnd; col >= colStart; col--)
        {
            cout << a[rowEnd][col] <<" ";
        }
        rowEnd--;

        //for colStart
        for (int row = rowEnd; row >= rowStart; row--)
        {
            cout << a[row][colStart] <<" ";
        }
        colStart++;   
        
    }
    return 0;
}