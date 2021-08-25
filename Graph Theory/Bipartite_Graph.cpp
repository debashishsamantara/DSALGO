//Its vertices can be divided into two disjoint and independent sets U and V such that every edge connects a vertex in U to one in V.
//The graph doesn't contain any odd-length cycles.
//The graph is 2 colourable.

//-Traverse the graph
//-If the current node is of red colour, paint its neighbours as blue.

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

vvi adj;
vector<bool> visited;
vi col;
bool bipart = true;

void color(int u, int curr){
    if(col[u] != -1 and col[u] != curr){
        bipart = false;
        return;
    }
    col[u] = curr;
    if(visited[u])
        return;
    visited[u] = true;
    for(auto i : adj[u])
        color(i, curr xor 1);
}

int main(){
    int n, m;
    cin >> n >> m;
    adj = vvi(n);
    visited = vector<bool>(n, false);
    col = vi(n, -1);
    loop(i, 0, m){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    loop(i, 0, n){
        if(!visited[i])
            color(i, 0);
    }
    if(bipart)
        cout << "Graph is bipartite";
    else
        cout << "Graph is not bipartite";
    return 0;
}