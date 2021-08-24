//Write a program to solve a sudoku puzzle by filling the empty cells. A Sudoku solution must satisfy all the following rules:
//1. Each of the digits 1-9 must occur exactly once in each row.
//2. Each of the digits 1-9 must occur exactly once in each column.
//3. Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
//The '.' character indicates empty cells.


//Pseudo Code
//1 - Start from (0, 0) you want to reach (8, 8)
//2 - Try out all valid combinations
//3 - false, currently at (x, y)
//4 - If
//      ans = already filled, move to next block,
//5 - else
//      for(numbers = 1 to 9)
//          if you can place number at (x, y)
//              ans = ans or place number at (x, y) and move to next block


#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

void helper(int r, int c, vector<vector<char>> &a, map<pair<int, int>, map<int, int>> &mp, vector<map<int, int>> &row, vector<map<int, int>> &col){
    if(r == 9){
        for(auto it : a){
            for(auto i : it){
                cout << i << " ";
            }
            cout << "\n";
        }
        cout << "\n";
        return;
    }
    if(c == 9){
        helper(r+1, 0, a, mp, row, col);
        return;
    }
    if(a[r][c] != '.'){
        helper(r, c+1, a, mp, row, col);
        return;
    }
    rep(i, 1, 9){
        int rw = r/3, cl = c/3;
        if(!mp[{rw, cl}][i] and !row[r][i] and !col[c][i]){
            mp[{rw, cl}][i] = 1;
            row[r][i] = 1;
            col[c][i] = 1;
            a[r][c] = i + '0';
            helper(r, c+1, a, mp, row, col);
            mp[{rw, cl}][i] = 0;
            row[r][i] = 0;
            col[c][i] = 0;
            a[r][c] = '.';
        }
    }
}

void solveSudoku(vector<vector<char>> &a){
    map<pair<int, int>, map<int, int>> mp;
    vector<map<int, int>> row(9);
    vector<map<int, int>> col(9);
    rep(i, 0, 9){
        rep(j, 0, 9){
            if(a[i][j] != '.'){
                mp[{i/3, j/3}][a[i][j]-'0'] = 1;
                row[i][a[i][j]-'0'] = 1;
                col[i][a[i][j]-'0'] = 1;
            }
        }
    }
    helper(0, 0, a, mp, row, col);
} 

signed main(){
    vector<vector<char>> sudoku = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    solveSudoku(sudoku);
}