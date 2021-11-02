//Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
//A region is captured by flipping all 'O's into 'X's in that surrounded region.

//Idea
//1. Traverse the 'O' components around the edges of the grid and change it to '*'.
//2. The remaining 'O' components will be surrounded regions that can be captured.
//3. Change the '*' back to 'O'.

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define gi greater<int>
#define pii pair<int, int>
#define vii vector<pii>
#define loop(i, a, b) for(int i = a; i < b; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

void change(vector<vector<char>> &A, int x, int y){
    A[x][y] = '*';
    int dx[] = {0, 0, -1, 1};
    int dy[] = {1, -1, 0, 0};
    loop(i, 0, 4){
        int cx = x + dx[i];
        int cy = y + dy[i];
        if(cx >= 0 and cx < A.size() and cy >= 0 and cy < A[0].size() and A[cx][cy] == 'O'){
            change(A, cx, cy);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> A(n, vector<char>(m));
    loop(i, 0, n){
        loop(j, 0, m){
            cin >> A[i][j];
        }
    }
    loop(i, 0, n){
        loop(j, 0, m){
            if(i == 0 or i == n-1 or j == 0 or j == m-1){
                change(A, i, j);
            }
        }
    }
    loop(i, 0, n){
        loop(j, 0, m){
            if(A[i][j] == 'O'){
                A[i][j] = 'X';
            }
        }
    }
    loop(i, 0, n){
        loop(j, 0, m){
            if(A[i][j] == '*')
                A[i][j] == 'O';
        }
    }
    loop(i, 0, n){
        loop(j, 0, m){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}