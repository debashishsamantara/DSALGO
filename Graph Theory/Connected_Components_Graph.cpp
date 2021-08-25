//A connected component is a subgraph in which any 2 vertices are connected to each other by paths, and which is connected to no additional vertices in the subgraph.

//Idea
//1. Visit the nodes in Depth-First fashion.
//2. If the node is not visited, visit that node and its neighbour recursively.
//Each time a unvisited node is found, a new component will be found.

//Ques.- find the number of connected components in a graph and its size.

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

vector<bool> visited;
int n, m;
vvi adj;
vi components;

int get_comp(int idx){
    if(visited[idx])
        return 0;
    visited[idx] = true;
    int ans = 1;
    for(auto i : adj[idx]){
        if(!visited[i]){
            ans += get_comp(i);
            visited[i] = true;
        }
    }
    return ans;
}

int main(){
    int n, m;
    cin >> n >> m;
    adj = vvi(n);
    visited = vector<bool>(n);
    loop(i, 0, m){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    loop(i, 0, n){
        if(!visited[i])
            components.push_back(get_comp(i));
    }
    for(auto i : components){
        cout << i << " ";
    }
}