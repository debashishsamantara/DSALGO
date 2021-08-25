//Keep on traversing the graph
//If you found an edge pointing to an already visited node (except the parent node), a cycle is found.

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

bool isCycle(int src, vvi &adj, vector<bool> &visited, int parent){
    visited[src] = true;
    for(auto i : adj[src]){
        if(i != parent){
            if(visited[i])
                return true;
            if(!visited[i] and isCycle(i, adj, visited, src))
                return true;
        }
    }
    return false;
}

int main(){
    int n, m;
    cin >> n >> m;
    vvi adj(n);
    loop(i, 0, m){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool cycle = false;
    vector<bool> visited(n, false);
    loop(i, 0, n){
        if(!visited[i] and isCycle(i, adj, visited, -1))
            cycle = true;
    }
    if(cycle)
        cout << "Cycle is present";
    else
        cout << "Cycle is not present";
}