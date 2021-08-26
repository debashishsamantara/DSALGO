//Spanning Tree - Given an undirected and connected graph G(V, E), a spanning tree of the graph G is a tree that spans G (that is, includes every vertex of G) and is a subgraph of G (every edge in the tree belongs to G).
//The cost of the spanning tree is the sum of the weights of all the edges in the tree
//There can be many spanning trees.

//Min. Spanning Tree - MST is the spanning tree where the cost is minimum among all the spanning trees.
//There also can be many MSTs.

//Pseudo Code of Kruskal's Algorithm
//1. Sort the edges in increasing order of their weights.
//2. Iterate in the sorted edges,
//     If inclusion of i'th edge leads to a cycle, then skip this edge.
//   else
//     include the edge in the MST.

//Complexity Analysis
//Time Complexity - O(ElogV)
//Space Complexity - O(E+V)

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

const int N = 1e5+6;
vi parent(N);
vi sz(N);

void makeSet(int v){
    parent[v] = v;
    sz[v] = 1;
}

int findSet(int v){
    if(v == parent[v])
        return v;
    return parent[v] = findSet(parent[v]);
}

void unionSets(int a, int b){
    a = findSet(a);
    b = findSet(b);
    if(a != b){
        if(sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main(){
    loop(i, 0, N)
        makeSet(i);
    int n, m;
    cin >> n >> m;
    vvi edges;
    loop(i, 0, m){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }
    sort(edges.begin(), edges.end());
    int cost = 0;
    for(auto i : edges){
        int w = i[0];
        int u = i[1];
        int v = i[2];
        int x = findSet(u);
        int y = findSet(v);
        if(x == y)
            continue;
        else{
            cout << u << " " << v << "\n";
            cost += w;
            unionSets(u, v);
        }
    }
}