//Given a weighted graph. Find the single source shortest path from a vertex u to all the vertices in the graph. If the node is unreachable, then print -1.
//Note - The weights of the edges must be positive.

//Idea
//1. Assign a distance value to all vertices in the input graph. Initialize all distance values as INFINITE. Assign distance value as 0 for the source vertex.
//2. While set is not empty
//      A. Pick a vertex U from set s that has minimum distance value.
//      B. Update distance value of all adjacent vertices of u.

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

const int inf = 1e7;

int main(){
    int n, m;
    cin >> n >> m;
    vi dist(n+1, inf);
    vector<vii> graph(n+1);
    loop(i, 0, m){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    int source;
    cin >> source;
    dist[source] = 0;
    set<pii> s;
    s.insert({0, source});
    while(!s.empty()){
        auto x = *(s.begin());
        s.erase(x);
        for(auto i : graph[x.second]){
            if(dist[i.first] > dist[x.second] + i.second){
                s.erase({dist[i.first], i.first});
                dist[i.first] = dist[x.second] + i.second;
                s.insert({dist[i.first], i.first});
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(dist[i] < inf)
            cout << dist[i] << " ";
        else
            cout << "-1";
    }
    return 0;
}