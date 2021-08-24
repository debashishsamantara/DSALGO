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

const int N = 1e5+2, MOD = 1e9+7;
vi adj[N];

signed main(){
    //Adjacency Matrix
    int n, m;
    cin >> n >> m;
    vvi adjm (n+1, vi(n+1, 0));
    loop(i, 0, m){
        int x, y;
        cin >> x >> y;
        adjm[x][y] = 1;
        adjm[y][x] = 1;
    }
    cout << "adjacency matrix of above graph given by:" << endl;
    loop(i, 1, n+1){
        loop(j, 1, n+1)
            cout << adjm[i][j] <<" ";
        cout << endl;
    }
    if(adjm[3][7] == 1)
        cout << "There is a edge between 3 and 7" << endl;
    else
        cout << "no edge";

    cout << endl << endl;

    //Adjacency List
    cin >> n >> m;
    loop(i, 0, m){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout << "Adjacency list is given by:" << endl;
    loop(i, 1, n+1){
        cout << i << "->";
        for(int x : adj[i])
            cout << x << " ";
        cout << endl;
    }
}