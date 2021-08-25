//1. Mark the current node as visited and also mark the index in recursion stack.
//2. Find all the vertices which are not visited and are adjacent to current node.
//3. If the adjacent vertices are already marked in the recursion stack then a cycle is found.

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

bool isCycle(int src, vvi &adj, vector<bool> &visited, vi &stack){
    stack[src] = true;
    if(!visited[src]){
        visited[src] = true;
        for(auto i : adj[src]){
            if(!visited[i] and isCycle(i, adj, visited, stack))
                return true;
            if(stack[i])
                return true;
        }
    }
    stack[src] = false;
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
    }
    bool cycle = false;
    vi stack(n, 0);
    vector<bool> visited(n, 0);
    loop(i, 0, n){
        if(!visited[i] and isCycle(i, adj, visited, stack))
        cycle = true;
    }
    if(cycle)
        cout << "Cycle is present";
    else
        cout << "Cycle is not present";
}