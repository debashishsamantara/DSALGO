//From a source vertex v, find the shortest distance to all other nodes in the graph.

//Idea
//1. Initially d[v] = 0 and for all other elements d[] = ∞
//2. In each pass, relax all the edges.
//      i.e. for edge(a, b) having weight w,
//          d[b] = min(d[b], d[a] + w)
//3. Assuming no negative edge cycle, since there are n vertices, shortest path can only contain 'n-1' edges. Therefore, we wil get our answer in at most 'n-1' passes.

//What makes it better than dijkstra algo?
//-Negative Edges!!
//-> It will work for negative edges and negative cycles.
//-> It can detect negative cycles as well.

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

const int INF = 1e9;

int main(){
    int n, m;
    cin >> n >> m;
    vvi edges;
    loop(i, 0, m){
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    int src;
    cin >> src;
    vi dist(n, INF);
    dist[src] = 0;
    loop(iter, 0, n-1){
        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];
            dist[v] = min(dist[v], w + dist[u]);
        }
    }
    for(auto i : dist)
        cout << i << " ";
    return 0;
}